#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>

typedef long double ld;


void* run(void *arg);

int *arr;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Invalid number of arguments.\n");
        return 0;
    }
    int N = argc-1;
    int *idxs = malloc(sizeof(int) * N);
    arr = malloc(sizeof(int) * N);
    pthread_t *threads = malloc(sizeof(pthread_t) * N);

    for (int i = 0; i < N; i++) {
        arr[i] = strtol(argv[i+1], NULL, 10);
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < N; i++) {
        idxs[i] = i;
        int ret = pthread_create(&threads[i], NULL, run, (void*) &idxs[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("has been replaced with ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(idxs);
    free(arr);
    free(threads);

    return 0;
}

void *run(void *arg) {
    int index = *(int *) arg;
    if (arr[index] % 2 == 0)
        arr[index] = pow(arr[index], 3);
    else
        arr[index] *= -1;
}
