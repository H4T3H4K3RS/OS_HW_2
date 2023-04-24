//
// Created by Всеволод Овчинников on 25.04.2023.
//

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>

#define ROOMS_COUNT 30

int *rooms;
sem_t *room_sem;

void handle_sigint(int sig) {
    printf("Interrupt signal received, cleaning up... Sig: %d\n", sig);
    munmap(rooms, ROOMS_COUNT * sizeof(int));
    shm_unlink("/rooms_shm");
    munmap(room_sem, sizeof(sem_t));
    sem_destroy(&room_sem[0]);
    shm_unlink("/sem_shm");
    killpg(getpgid(getpid()), sig);
    exit(EXIT_FAILURE);
}

void client(int client_id) {
    while (1) {
        printf("[Client #%d] Waiting for allocation\n", client_id);
        sem_wait(&room_sem[0]);
        int room_id = -1;
        for (int i = 0; i < ROOMS_COUNT; ++i) {
            if (!rooms[i]) {
                rooms[i] = 1;
                room_id = i;
                break;
            }
        }
        int sleep_time = rand() % 3 + 1;
        if (room_id != -1) {
            printf("[Client #%d]{%ds} Allocated into number %d\n", client_id, sleep_time, room_id);
            sleep(sleep_time);
            rooms[room_id] = 0;
            sem_post(&room_sem[0]);
            printf("[Client #%d] Checkout. Stayed for: {%d}s\n", client_id, sleep_time);
            break;
        } else {
            printf("[Client #%d]{%ds} Waiting for vacant room\n", client_id, sleep_time);
            sleep(sleep_time);
        }
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    int num_clients;
    printf("Number of clients: ");
    scanf("%d", &num_clients);
    int shm_fd = shm_open("/rooms_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, ROOMS_COUNT * sizeof(int));
    rooms = (int *) mmap(NULL, ROOMS_COUNT * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    int sem_fd = shm_open("/sem_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(sem_fd, sizeof(sem_t));
    room_sem = (sem_t *) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, sem_fd, 0);
    sem_init(&room_sem[0], 1, ROOMS_COUNT);
    for (int i = 0; i < num_clients; ++i) {
        int pid = fork();
        if (pid == 0) {
            client(i);
            exit(0);
        }
    }
    for (int i = 0; i < num_clients; ++i) {
        wait(NULL);
    }
    munmap(rooms, ROOMS_COUNT * sizeof(int));
    shm_unlink("/rooms_shm");
    munmap(room_sem, sizeof(sem_t));
    sem_destroy(&room_sem[0]);
    shm_unlink("/sem_shm");
    killpg(getpgid(getpid()), 0);
    exit(EXIT_SUCCESS);
}
