# Programa para verificar linhas de código c++

# Sobre
O programa é composto de alguns arquivos modularizados, para facilitar a identificação na montagem do Makefile. Sendo assim, os módulos do contador de linhas em C++ estão concatenados para execução por meio do Makefile.

## Como compilar o programa

Para compilar o programa, primeiro é necessário instalar a biblioteca boost utilizada para zerar a variável temporária e definir a contagem de linhas a cada rodada.

No ubuntu:

```
$ sudo apt-get install libboost-dev
```

Após feito isso, deve acessar a pasta src e executar:

```
$ make
```

Feito isso, o programa main.cpp com os respectivos valores de total de linhas, linhas em branco ou comentadas e linhas de código útil, são mostradas em tela com o comando:

```
$make run
```

## Vendo o total de testes cobertos com gcov

Para isso basta executar:

```
$ make gcov
```

# Documentação - Doxygen

Para acessar o doxygen, basta abrir no navegador o .html presente em:


```
$ src/html/index.html
```
