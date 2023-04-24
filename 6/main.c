//
// Created by Всеволод Овчинников on 25.04.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>

#define ROOMS_COUNT 30
#define SEM_KEY 1234
#define SHM_KEY 5678

void client(int client_id, int *rooms, int sem_id) {
    while (1) {
        printf("[Client #%d] Waiting for allocation\n", client_id);
        struct sembuf sem_op = {0, -1, SEM_UNDO};
        semop(sem_id, &sem_op, 1);
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
            sem_op.sem_op = 1;
            semop(sem_id, &sem_op, 1);
            printf("[Client #%d] Checkout. Stayed for: {%d}s\n", client_id, sleep_time);
            break;
        } else {
            printf("[Client #%d]{%ds} Waiting for vacant room\n", client_id, sleep_time);
            sleep(sleep_time);
        }
    }
}

int main() {
    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    int shm_id = shmget(SHM_KEY, ROOMS_COUNT * sizeof(int), IPC_CREAT | 0666);
    int *rooms = (int *) shmat(shm_id, NULL, 0);
    union semun sem_arg;
    sem_arg.val = ROOMS_COUNT;
    semctl(sem_id, 0, SETVAL, sem_arg);
    int num_clients;
    printf("Number of clients: ");
    scanf("%d", &num_clients);

    pid_t pid;
    for (int i = 0; i < num_clients; ++i) {
        pid = fork();
        if (pid == 0) {
            client(i, rooms, sem_id);
            exit(0);
        }
    }
    for (int i = 0; i < num_clients; ++i) {
        wait(NULL);
    }
    shmdt(rooms);
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID, 0);
    return 0;
}
