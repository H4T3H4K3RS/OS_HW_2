//
// Created by Всеволод Овчинников on 25.04.2023.
//

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ROOMS_COUNT 30

typedef struct {
    sem_t room_sem;
    int rooms[ROOMS_COUNT];
} SharedData;

SharedData *shared_data;

void client(void *index) {
    int client_id = *(int *) index;
    while (1) {
        printf("[Client #%d] Waiting for allocation\n", client_id);
        sem_wait(&shared_data->room_sem);
        int room_id = -1;
        for (int i = 0; i < ROOMS_COUNT; ++i) {
            if (!shared_data->rooms[i]) {
                shared_data->rooms[i] = 1;
                room_id = i;
                break;
            }
        }
        int sleep_time = rand() % 3 + 1;
        if (room_id != -1) {
            printf("[Client #%d]{%ds} Allocated into number %d\n", client_id, sleep_time, room_id);
            sleep(sleep_time);
            shared_data->rooms[room_id] = 0;
            sem_post(&shared_data->room_sem);
            printf("[Client #%d] Checkout. Stayed for: {%d}s\n", client_id, sleep_time);
            break;
        } else {
            printf("[Client #%d]{%ds} Waiting for vacant room\n", client_id, sleep_time);
            sleep(sleep_time);
        }
    }
}

int main() {
    int fd = shm_open("/shared_memory", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(fd, sizeof(SharedData)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }
    shared_data = mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    sem_init(&shared_data->room_sem, 1, ROOMS_COUNT);
    for (int i = 0; i < ROOMS_COUNT; ++i) {
        shared_data->rooms[i] = 0;
    }
    int num_clients;
    printf("Number of clients: ");
    scanf("%d", &num_clients);
    pid_t pid;
    for (int i = 0; i < num_clients; ++i) {
        int *t = malloc(sizeof(int));
        *t = i;
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            client(t);
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < num_clients; ++i) {
        wait(NULL);
    }
    sem_destroy(&shared_data->room_sem);
    if (munmap(shared_data, sizeof(SharedData)) == -1) {
        perror("munmap");
    }
    if (shm_unlink("/shared_memory") == -1) {
        perror("shm_unlink");
    }
    return 0;
}
