## Considere o problema da tartaruga envolvido no projeto final da disciplina. Desenvolva uma versão paralela:

+ é necessario baixar a bilbioteca a MPFR e GMP 
+ para compilar a versão 1.1 foi utilizado o comando: "gcc -o teste V1-1.c -g -Wall -fopenmp -lmpfr -lgmp"
+ para compilar a versão 1.2 foi utilizado o comando: "gcc -o teste2 V1-2.c -g -Wall -fopenmp -lmpfr -lgmp"
+ para executar foi utilizado o comando: "./teste X" sendo X o numero de threads
  
---

## Instalação das Bibliotecas (No Debian)

#### Para instalar GMP
> sudo apt-get install libgmp-dev

#### Para instalar MPFR
> sudo apt-get install libmpfr-dev

---

## a criação da V1-1

a V1-1 foi construída a partir da V1 montada no diretório [proj_v1]( https://github.com/Victor-Vaglieri/paralela/tree/main/proj_v1) apenas com o objetivo de atingir mais casas decimais visto que anteriormente conseguia 18 casas, assim foi utilizado  a biblioteca MPFR pois a mesma oferece suporte a aritmética de ponto flutuante com precisão arbitrária. A MPFR permite realizar cálculos com um número muito maior de dígitos de precisão do que o tipo *long double* padrão em C, que foi utilizado na V1.

---

## a criação da V1-2

Nos testes da V1-1, percebeu-se que havia uma grande demora na execução, indicando que havia uma parte a ser melhorada. A V1-2 foi criada com o objetivo de otimizar o tempo de cálculo dos fatoriais. Na V1-1, o fatorial de N era calculado multiplicando de N até 1 em todas as iterações, o que resultava em muitas operações redundantes.

Na V1-2, essa abordagem foi otimizada. Agora, cada thread, na primeira iteração do seu bloco, calcula o fatorial de N até 1 e o salva. Este valor pré-calculado é então utilizado nas iterações subsequentes para calcular o fatorial de N+1 de forma mais eficiente. Em vez de recalcular tudo do zero, a thread simplesmente multiplica o fatorial de N pelo próximo número, reduzindo significativamente o tempo de cálculo. Veja a comparação de tempo no gráfico abaixo com teste de 8192 iterações totais e 1000000 de precisão.


### grafico de comparação
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8b39e28c-3c2a-45ef-8c37-9cdf8dba27dd)

#### speedup da V1-1
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/d6cb2edd-266c-42c6-b7f6-60931fe36c39)

#### speedup da V1-2
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/b4192208-fcbd-4dd7-8b3c-8de2ddcbd03e)

---

### Maximo de casas decimais atingidas corretamente


Agora com o programa funcionando e um o tempo aceitável, foram feitos os testes de quantas possíveis casas decimais corretas de Euler seriam atingidas, para isso foram feitos vários testes e com o melhor teste usando 12 threads, 229376 somas/iterações totais (N’s) e com a precisão em bits igual a 3321930 (aproximadamente 1000000 de casas decimais) atingindo a 999998 casas decimais iguais e com o tempo igual a 24 minutos e 37,557 segundos, como visto na imagem abaixo e no arquivo output.log.

Para conferir o resultado foi utilizado um outro programa em python que compara a última saída do log com o arquivo texto que contém o [número de Euler]( https://apod.nasa.gov/htmltest/gifcity/e.2mil) calculado por Robert Nemiroff e verificado por Jerry Bonnell, ambos da NASA Goddard Space Flight Center.

Para executar o programa em python se utiliza o comando “python3 verif.py”, mas antes se deve ter salvo o resultado da V1-2 em um arquivo log chamado *output.log* e o arquivo *comparar.txt* com o [número de Euler]( https://apod.nasa.gov/htmltest/gifcity/e.2mil) 

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8b4edd68-6381-447e-9bb3-213689328c82)

---

## funções utilizadas

(USAR A FONTE ABAIXO)

### • *mpfr_set_d*

 FALTA: (tem que falar o que faz, quais os parametros e falar que o motivo que foi usado é porque precisava colocar o valor double na variavel)
 
#### A função mpfr_set_d é utilizada para definir o valor de uma variável do tipo mpfr_t a partir de um valor do tipo double então para explicar melhor a baixo esta sua sintaxe

#### void mpfr_set_d(mpfr_t rop, double op, mpfr_rnd_t rnd);

##### Parâmetros

##### rop: A variável de destino do tipo mpfr_t onde o valor double será armazenado.

##### op: O valor do tipo double que será atribuído à variável rop.

##### rnd: O modo de arredondamento a ser usado. A biblioteca MPFR suporta diversos modos de arredondamento, como MPFR_RNDN (arredondamento para o número mais próximo), MPFR_RNDZ (arredondamento para zero), MPFR_RNDU (arredondamento para cima), e MPFR_RNDD (arredondamento para baixo).


#### Então função converte o valor do tipo double fornecido em op para um número de alta precisão representado pela variável mpfr_t rop, usando o modo de arredondamento especificado em rnd. Então foi necaessario utilizala para inicializar variáveis mpfr_t com valores específicos representados como double. Por exemplo:


##### mpfr_init2(my_result, PRECISAO);

##### mpfr_set_d(my_result, 0.0, MPFR_RNDU);

#### por exemplo aqui ela é inicializada a variável my_result com uma precisão de PRECISAO bits, e seu valor é definido como 0.0 (zero) com o modo de arredondamento MPFR_RNDU (arredondamento para cima).Alem  disso a  função garante que a conversão do valor double para o tipo mpfr_t seja realizada com a precisão e o arredondamento desejados, essenciais para manter a precisão nas operações subsequentes com números de alta precisão.

 função mpfr_set_d é chamada várias vezes para inicializar variáveis:

mpfr_set_d(my_result, 0.0, MPFR_RNDU);

mpfr_set_d(resu_div, 1.0, MPFR_RNDU);

mpfr_set_d(um, 1.0, MPFR_RNDU);

mpfr_set_d(f, 0.0, MPFR_RNDU);

Essas chamadas são usadas para garantir que as variáveis my_result, resu_div, um, e f sejam corretamente inicializadas com os valores 0.0 ou 1.0, prontos para as operações de alta precisão que seguirão.


 

### • *mpfr_init2*

FALTA: (tem que falar o que faz, como faz para guardar a variavel, quais os parametros e falar que o motivo que foi usado é porque precisa que a variavel tenha aquela precisão especifica)

### • *mpfr_set_ui*

FALTA: (tem que falar o que faz, quais os parametros e falar que o motivo que foi usado é porque precisa que a variavel comece com um valor e que o valor seria grande o suficiente para talvez uma variavel do tipo inteiro assinado)

### • *mpfr_mul_ui*

### • *mpfr_div*

### • *mpfr_add* 

### • *mpfr_clear*

FALTA: (tem que falar o que faz)

### • *mpfr_out_str* 

FALTA: (tem que falar o que faz e explicar os parametros)

Fontes: 

+ [https://www.mpfr.org/algo.html](https://www.mpfr.org/algo.html)
+ [https://github.com/bennoleslie/mpfr/tree/master/src](https://github.com/bennoleslie/mpfr/tree/master/src)


---

#### Logs do grafico de comparação 
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/8c02ab85-1e8e-4f39-9ee2-31f708b8b579)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/afdc91b0-8f66-438e-9173-d43cff92790d)

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/c3a5e16a-1bac-456f-9463-af9cc5a0b5ea)

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/a2126d38-5027-4cbe-9d51-0f5de8c161af)

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/3b3961bb-05a8-4bab-8b45-ac2c00dc3c82)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/9f4b25b8-198c-4d46-b37c-96302c29a8e2)

![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/97a36639-01dd-4c9a-8b1e-62067ee35242)
![image](https://github.com/Victor-Vaglieri/paralela/assets/127432508/878f6565-5402-456c-9e81-6156a2a08c94)


---

> [!IMPORTANT]
> processador usado: *AMD Ryzen 5 1600 six-core*
> 
> sistema operacional usado: *Debian GNU/Linux 12*
