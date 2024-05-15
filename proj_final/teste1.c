#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <mpfr.h>

#define ENES 8192
#define N_CASA 1000000 //casa decimais 

//13021 casas corretas
//tradução do v1 com a biblioteca mpfr

mpfr_t result;
int numThreads;

void fatorial(int n, mpfr_t result_fat) {
    mpfr_set_ui(result_fat, 1.0, MPFR_RNDU);
    for (int i = n; i > 1; i--) {
        mpfr_mul_ui(result_fat, result_fat, i, MPFR_RNDU);
    }
}

void soma(mpfr_t* result) {
    int quant = ENES / numThreads;
    int ini = (ENES / numThreads) * omp_get_thread_num();
    int fim = (ENES / numThreads) * (omp_get_thread_num() + 1);
    
    //cria as variáveis
    mpfr_t my_result, resu_div, um;
    
    // inicia variáveis
    mpfr_init2(my_result, N_CASA);
    mpfr_set_d(my_result, 0.0, MPFR_RNDU);
    mpfr_init2(resu_div, N_CASA);
    mpfr_set_d(resu_div, 1.0, MPFR_RNDU);
    mpfr_init2(um, N_CASA);
    mpfr_set_d(um, 1.0, MPFR_RNDU);
    mpfr_t f;
    for (int i = ini; i < fim; i++) {
        mpfr_init2(f,N_CASA);
        fatorial(i,f);
        mpfr_div(resu_div, um, f, MPFR_RNDU);
        mpfr_add(my_result, my_result, resu_div, MPFR_RNDU);
        mpfr_clear(f);
    }
    #pragma omp critical
    mpfr_add(*result, *result, my_result, MPFR_RNDU);
    mpfr_clear(resu_div);
    mpfr_clear(my_result);
    mpfr_clear(um);
}

int main(int argc, char* argv[]) {
    numThreads = strtol(argv[1], NULL, 10);
    mpfr_init2(result, N_CASA);
    mpfr_set_d(result, 0.0, MPFR_RNDU);
    #pragma omp parallel num_threads(numThreads)
    soma(&result);

    mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);
    mpfr_clear(result);
    return 0;
}

