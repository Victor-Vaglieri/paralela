#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//observações: 
// - long double não conseque mais de 18 casas de precisão
// - usar pthread é ruim em relação ao tempo
// - omp critical garante o mesmo resultado (msm errado apos 18 casa)
// - divisão de tarefa das trheads é complexo alem do abaixo

// - pesquisar sobre GMP ou possíveis bibliotecas de ponto flutuante
// - pesquisar sobre outros pragmas disponíveis 
// - talvez programação dinâmica
// - ainda aceitando qualquer gambiarra pra conseguir mais precisão sem utilizar bibliotecas

long double result = 0.0;

long double fat(int num) {
    long double resu = 1; 
    for (int i = num; i > 1; i--) {
        resu *= i;
    }
    return resu;
}

void calc_e(long double* result) {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    long double my_result = 0.0;
    int ini = (4096 / thread_count) * my_rank;
    int fim = (4096 / thread_count) * (my_rank + 1); 
    for (int i = ini; i < fim; i++) {
        my_result += 1.0 / fat(i);
    }
    #pragma omp critical
    *result += my_result;
    //printf("Thread %d: %Lf\n", my_rank, m_result);
}

int main(int argc, char* argv[]) {
    int thread_count = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(thread_count)
    calc_e(&result);
    printf("resultado é %.100Lf\n", result); // faz com 60 numeros apos a virgula com precisão de 18 (com no minimo com 32 de N's )
    return 0;
}
