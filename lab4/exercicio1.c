#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// função da curva = sin(x)+5
void calc_area(double a, double b, int n, double* result){
  double h,x,m_result, l_a, l_b;
  int l_n, my_rank = omp_get_thread_num(), thread_count = omp_get_num_threads();
  h = (b-a)/n;
  l_n = n/thread_count;
  l_a = a + my_rank * l_n * h;
  l_b = l_a +l_n*h;
  m_result = ((sin(l_a)+5)+(sin(l_b)+5))/2.0;
  for (int i = 1; i <= l_n-1;i++){
    x = l_a + i*h;
    m_result += (sin(x)+5);
  }
  m_result = m_result*h;
  *result += m_result;
}

int main(int argc, char* argv[]){
  double result = 0.0;
  double a = 0, b = 1000000000;
  int n = 500000;
  int thread_count;
  
  thread_count = strtol(argv[1], NULL, 10);
  # pragma omp parallel num_threads(thread_count)
  calc_area(a,b,n,&result);
  
  printf("n = %d trapezios, a = 0, b = %.0f,com a função igual a \"sin(x)+5\" a area é %.5lf\n",n,b,result);
  return 0;
} 
