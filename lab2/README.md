- para compilar foi utilizado o comando: "gcc -g -Wall -o teste codigo-final.c -lpthread"

- para executar foi utilizado o comando: "./teste  X" sendo X o numero de threads


- o desafio proposto foi de criar um programa de multiplicação de matriz por um vetor a qual recebesse o número de threads e devolveria os resultados em um vetor resposta, primeiro foi utilizado um programa com número definido de threads como no arquivo “lab2 com num de threads definida.c” para compreender como trabalhar com as threads e logo após foi feito o arquivo denominado “codigo-final.c” implementando os requisitos do desafio.
Se percebe pela imagem “captura.png” que o programa apresentou as respostas corretas da multiplicação da matriz A pelo vetor X o utilizar os números de threads 1,2,4, porém na escolha de 3 threads não houve resultado na ultima soma das multiplicações e permaneceu zerado


```
A = 
1  2  3  4  5  6
7  8  9  10 11 12
13 14 15 16 17 18
1  2  3  4  5  6
```
```
X = {2, 2, 2, 2, 2, 2}
```

resultado esperado **“42 114 186 42”**
