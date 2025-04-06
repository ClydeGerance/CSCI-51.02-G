#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>

typedef long double ld;

ld *sum;
int N;
ld X;
const ld eps = 1e-16; // compute until the absolute value is less than this

void* calc_sin(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Invalid number of arguments. Please pass integer N and real number X.\n");
        return 0;
    }
    N = strtol(argv[1], (char **)NULL, 10);
    X = strtod(argv[2], (char **)NULL);

    sum = malloc(sizeof(ld) * N);
    int *idxs = malloc(sizeof(int) * N);

    pthread_t *threads = malloc(sizeof(pthread_t) * N);
    for (int i = 0; i < N; i++) {
        idxs[i] = i;
        int ret = pthread_create(&threads[i], NULL, calc_sin, (void*) &idxs[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    ld total = 0;
    for (int i = 0; i < N; i++)
        total += sum[i];
    
    printf("sin(%Lf) = %Lf\n", X, total);
    printf("sinl(%Lf) = %Lf\n", X, sinl(X));

    free(idxs);
    free(sum);
    free(threads);

    return 0;
}

void *calc_sin(void *arg) {
    int index = *(int *) arg;

    int n = index;
    ld curr;

    do {
        int exp = 2*n+1;
        ld num = pow(X, exp);
        ld den = 1;
        for (int i = 1; i <= exp; i++)
            den *= i;
        int sign = n % 2 == 0 ? 1 : -1;
        curr = sign * num / den;
        // printf("%d | %d %d %Lf %Lf %d %Lf\n", index, n, exp, num, den, sign, curr);
        // sleep(1);
        sum[index] += curr;
        n += N;
    } while (fabsl(curr) >= eps); // terminates when absolute value of the last calculated term < 10^-16
}