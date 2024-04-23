 
## Construa uma solução paralela utilizando OpenMP e calcule o valor aproximado da área sob a curva,  respondendo às seguintes questões (A curva utilizada foi a função f(x) = sen(x) + 5):

+ para compilar foi utilizado o comando: "gcc -o exercicio1 exercicio1.c -g -Wall -fopenmp -lm"
+ para executar foi utilizado o comando: "./exercicio1 X" sendo X o numero de threads
---
### 1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/188f4c49-d751-4842-a718-7fc1499d9121)

---
### 2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/26c437be-2e19-4ff4-be63-437be9b2bf3b)

---
### 3. Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

**falta responder a pergunta aqui**

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/3216994e-bb0f-47c6-9eea-2a3b337db59f)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/ce22a894-c7a6-43e2-b148-8b898bf525b2)

**Sem a locução diretiva, a função calc_area é chamada por várias threads simultaneamente, e cada thread atualiza a variável result independentemente, o que pode levar a problemas de concorrência.**

**Então, ao adicionar #pragma omp critical antes da operação que atualiza result, você está garantindo que apenas uma thread pode executar essa parte do código por vez. Isso resolve os problemas de concorrência, garantindo que apenas uma thread atualize result de cada vez, evitando resultados incorretos devido a condições de corrida**

**Ao adicionar a diretiva critical, o código se torna mais seguro em termos de concorrência, mas pode perder um pouco em eficiência devido à contenção, já que apenas uma  thread pode executar a parte crítica do código de cada vez.**


---
> [!IMPORTANT]
> processador usado: *AMD Ryzen 5 1600 six-core*
> 
> sistema operacional usado: *Debian GNU/Linux 12*
