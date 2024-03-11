#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int matriz[3][4] = { // matriz da multiplicação
      {1, 2, 3, 4}, 
      {5, 6, 7, 8}, 
      {9, 10, 11, 12}};

int vetor[4] = {1, 2, 3, 4}; // vetor da multiplicação

int resultado[3] = {0}; // matriz que guarda a resposta

// resultado esperado "30 70 110"

void *mult(void *arg){ // função que as threads vão usar
  int *id = (int *) arg; // diz que o utlimo parametro de "pthread_create" sera id da thread
    for (int i = 0; i < 4; i++) { // looping que passa por todos os elementos da linha
        resultado[*id] += matriz[*id][i] * vetor[i]; // adiciona cada multiplicação para o vetor resultado
    }
    pthread_exit(NULL); // finaliza a thread
}

int main() {
    pthread_t threads[3]; // cria um vetor de threads
    int id[3] = {0,1,2}; // define ids DAS threads 
    
    for (int i = 0; i < 3; i++) { // looping para criar as threads 
        pthread_create(&threads[i], NULL, mult, &id[i]);
    }

    for (int i = 0; i < 3; i++) { // looping que bloqueia que a main termine antes de todas threads
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        printf("thread %d: %d \n", i , resultado[i]); // mostra o resultado obtido das threads
    }
}
