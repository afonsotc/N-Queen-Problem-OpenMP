# N-Queen-Problem-OpenMP

Trabalho prático para disciplina de INTRODUÇÃO PROCESSAMENTO PARALELO E DISTRIBUÍDO

Integrantes: Afonso Theil Cabreira


Existem dois arquivos de implementação, um para encontrar uma solução e mostra-la na tela e outro para calcular todas possibilidades.

Abaixo os passos para compilar e utilizar o código:


# Mostrar uma possibilidade #

* Compilar
```
gcc -fopenmp primeirapossibilidade.c -o nome_do_executavel
```
* Executar
```
./nome_do_executavel tamanho_tabuleiro numero_de_threads
```

# Calcular todas possibiidades

* Compilar
```
gcc -fopenmp todaspossibilidades.c -o nome_do_executavel
```
* Executar
```
./nome_do_executavel tamanho_tabuleiro numero_de_threads
```
# Observações

Não é possivel compilar sem adicionar ``` -fopenmp ``` pois estou utilizando as funções ```omp_get_wtime()```, ```omp_set_dynamic()``` e ```omp_set_num_thread()```. Caso queira utilizar a versão serial é preciso modificar o argumento ```numero_de_threads``` para 0 na hora de executar.
