#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

using namespace std;

#define SHM_KEY 1234 // shared memory key
#define SEM_KEY 1234 // semaphore key

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
    struct timespec t = {5, 0}; // timeout after 5 seconds
    if (semtimedop(sem_id, &op, 1, &t) == -1)
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
    int buffer_size = shm_size - sizeof(short); // leave space to store chunk size

    // initialize shared memory
    int shm_id = shmget(SHM_KEY, shm_size, IPC_CREAT | 0666);
    if (shm_id == -1)
        error("shmop: shmget failed");

    char* shm_ptr = (char*) shmat(shm_id, NULL, 0);

    if (((int*)shm_ptr) == (int*)-1)
        error("shmop: shmat failed");
    
    // get semaphores
    // 0: full
    // 1: empty

    sem_id = semget(SEM_KEY, 2, IPC_CREAT | 0666);
    if (sem_id == -1) {
        error("semop: semget failed");
    }

    // write file
    ofstream file(file_path, ios::binary);
    if (!file.is_open())
        error("Failed to open file");

    char* buffer = shm_ptr + sizeof(short); // part of shared memory that actually stores the file content
    short chunk;
    int idx = 0;

    while (true) {
        wait(FULL);

        // critical section
        memcpy(&chunk, shm_ptr, sizeof(short)); // get the chunk size
        cout << idx++ << " " << chunk << " " << buffer << endl;
        if (chunk <= 0) {
            signal(EMPTY);
            break;
        }
        file.write(buffer, chunk); // write the contents of buffer to output file
        
        signal(EMPTY);
        sleep(1);
    }

    // clean up
    file.close();
    shmdt(shm_ptr);

    semctl(sem_id, FULL, IPC_RMID);
    semctl(sem_id, EMPTY, IPC_RMID);
    shmctl(shm_id, IPC_RMID, NULL);
    
    return 0;
}