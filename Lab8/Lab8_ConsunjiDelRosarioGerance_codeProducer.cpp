#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

using namespace std;

#define SHM_KEY 1234 // shared memory key
#define SEM_KEY 1235 // semaphore key

#define FULL 0 // full semaphore index
#define EMPTY 1 // empty semaphore index

int sem_id;

void error(string message) {
    const char* chars = message.c_str();
    perror(chars);
    exit(1);
}

void wait(int idx) {
    // while (S <= 0);    since attempts to decrement a semaphore to a value less than zero fails or blocks
    // S--;

    struct sembuf op = {idx, -1, 0};
    if (semop(sem_id, &op, 1) == -1)
        error("semop: decrement failed");
}

void signal(int idx) {
    // S++
    struct sembuf op = {idx, 1, 0}; // increment semaphore by 1
    if (semop(sem_id, &op, 1) == -1)
        error("semop: increment failed");
}

int main(int argc, char *argv[]) {
    if (argc < 3)
        error("Invalid number of arguments.");

    string file_path = argv[1];
    int shm_size = stoi(argv[2]);
    int buffer_size = shm_size - sizeof(int); // leave space to store chunk size

    // initialize shared memory
    int shm_id = shmget(SHM_KEY, shm_size, IPC_CREAT | 0666);
    if (shm_id == -1)
        error("shmop: shmget failed");

    char* shm_ptr = (char*) shmat(shm_id, NULL, 0);

    if (((int*)shm_ptr) == (int*)-1)
        error("shmop: shmat failed");
    
    // initialize semaphores
    // 0: full 
    // 1: empty

    sem_id = semget(SEM_KEY, 2, IPC_CREAT | 0666);
    if (sem_id == -1) {
        error("semop: semget failed");
    }
    union sem_un {
        int val;
        struct semid_ds *buf;
        struct sembuf *arr;
        void *ptr;
    } arg;

    arg.val = 0;
    if (semctl(sem_id, FULL, SETVAL, arg) == -1) // full = 0
        error("semop: semctl failed");
    arg.val = 1;
    if (semctl(sem_id, EMPTY, SETVAL, arg) == -1) // empty = 1
        error("semop: semctl failed");
    
    // read file
    ifstream file(file_path, ios::binary);
    if (!file.is_open())
        error("Failed to open file");

    char* buffer = shm_ptr + sizeof(int); // part of shared memory that actually stores the file content
    int chunk; // how much data was actually read (in bytes)
    int idx = 0;
    while (true) {
        wait(EMPTY);

        // critical section
        file.read(buffer, buffer_size); // read file into buffer
        chunk = file.gcount();
        cout << idx++ << " " << chunk << " " << buffer << endl;
        memcpy(shm_ptr, &chunk, sizeof(int)); // store chunk size (number of bytes read) at the beginning of shared memory

        signal(FULL);
        if (chunk <= 0)
            break;
        
        sleep(1);
    }

    // clean up
    file.close();
    shmdt(shm_ptr);
    
    return 0;
}