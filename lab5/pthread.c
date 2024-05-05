#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_TERMS 4096

long double result = 0.0;

typedef struct {
    long double partial_sum;
    int start;
    int end;
} ThreadArgs;

long double fat(long double num) {
    long double resu = 1.0;
    for (int i = num; i > 1; i--) {
        resu *= i;
    }
    return resu;
}

void* calc_e_partial(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    args->partial_sum = 0.0;
    for (int i = args->start; i < args->end; i++) {
        args->partial_sum += 1.0 / fat(i);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    long double total_sum = 0.0;
    int terms_per_thread = 128 / num_threads;
    
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].start = i * terms_per_thread;
        thread_args[i].end = (i + 1) * terms_per_thread;
        pthread_create(&threads[i], NULL, calc_e_partial, &thread_args[i]);
    }
    
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_args[i].partial_sum;
    }
    printf("resultado é %.100Lf\n", total_sum);
    return 0;
}
