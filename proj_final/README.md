## Considere o problema da tartaruga envolvido no projeto final da disciplina. Desenvolva uma versão paralela:

+ é necessario baixar a bilbioteca a MPFR (falar com baixar no Linux)
+ para compilar a versão 1.1 foi utilizado o comando: "gcc -o teste V1-1.c -g -Wall -fopenmp -lmpfr -lgmp"
+ para compilar a versão 1.2 foi utilizado o comando: "gcc -o teste2 V1-2.c -g -Wall -fopenmp -lmpfr -lgmp"
+ para executar foi utilizado o comando: "./teste X" sendo X o numero de threads
---

## V1-1 (falar que o foi feita uma "tradução" da v1 para essa utilizando a biblioteca)

---

## V1-2 (pq criou versão v1-2 ela é melhor, resumindo V1-2 faz o primeiro fatorial utiliza a função recursiva o resto multiplica a ultima iteração com o proximo N)


### grafico de comparação
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8b39e28c-3c2a-45ef-8c37-9cdf8dba27dd)


### maxima de casas decimais atingidas corretamente

(falar que para saber quantas casas decimais corretas de euler foi utilizado o codigo "verif.py" que compara o log da V1-2 com o .txt do site da nasa)

com 229376 N's
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8b4edd68-6381-447e-9bb3-213689328c82)

---

## funções utilizadas

(falar o algritmo que a função usa e como esse biblioteca tanka tantas casas decimais)

### como esse biblioteca tanka tantas casas decimais

### "mpfr_set_d", 

### "mpfr_init2",

### "mpfr_set_ui", 

### "mpfr_mul_ui",

### "mpfr_div", 

### "mpfr_add", 

### "mpfr_clear",

### "mpfr_out_str", 

---

#### Logs
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8c02ab85-1e8e-4f39-9ee2-31f708b8b579)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/afdc91b0-8f66-438e-9173-d43cff92790d)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/c3a5e16a-1bac-456f-9463-af9cc5a0b5ea)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/a2126d38-5027-4cbe-9d51-0f5de8c161af)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/a8daba96-5cdd-4af3-90e4-5c0c4fe0c01a)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/97a36639-01dd-4c9a-8b1e-62067ee35242)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/a83a208e-e073-4622-af70-71cfb4b738a8)

---

> [!IMPORTANT]
> processador usado: *AMD Ryzen 5 1600 six-core*
> 
> sistema operacional usado: *Debian GNU/Linux 12*
