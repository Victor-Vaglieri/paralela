#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A[10000000][10]; // matriz grande

int x[10] = {1, 1, 1, 1,1,2,2,2,2,2}; // vetor x para a multiplicação
int y[10000000] = {0}; // valores de resposta
int thread_count; 
int num_linhas = 10000000, num_colunas = 10;
void *mat(void *rank)
{
  long mrank = (long)rank; // define que a variavel de entrada da criação da thread sera seu rank/id
  printf("thread %d começou\n", mrank);
  int parti = num_linhas / thread_count; // define quantas linhas a thread vai ler
  int f_row = mrank * parti;             // define em que linha a thread começará
  int l_row = (mrank + 1) * parti - 1;   // define em que linha thread terminará
  for (int i = f_row; i <= l_row; i++)   // looping que percorre a(s) linha(s)
  {
    for (int j = 0; j < num_colunas; j++) // looping que percorre cada elemento da linha
    {
      y[i] += A[i][j] * x[j]; // soma das multiplicações
    }
  }
  
  return NULL;
}

int main(int argc, char *argv[])
{
  // pega o numero de threads utilizadas
  thread_count = strtol(argv[1], NULL, 10);
  // cria vetor dinamico de threads
  pthread_t *threads;
  threads = (pthread_t *)malloc(thread_count * sizeof(pthread_t));

  for (int i = 0; i < 10000000; i++){
      for (int j = 0; j < 10; j++){
          A[i][j] = j+1;
      }
  }
  // cria as threads
  for (long p_thr = 0; p_thr < thread_count; p_thr++)
  {
    pthread_create(&threads[p_thr], NULL, mat, (void *)p_thr);
  }

  // Aguarde todas as threads terminarem
  for (long p_thr = 0; p_thr < thread_count; p_thr++)
  {
    pthread_join(threads[p_thr], NULL);
  }

  // imprime o resultado
  //for (int i = 0; i < num_linhas; i++)
  //{
  //  printf("%d ", y[i]);
  //}
  //printf("\n");

  // libera as threads
  free(threads);

  return 0;
}
