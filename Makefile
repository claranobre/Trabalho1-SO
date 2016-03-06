CFLAGS = -g -Wall
SRCS = ordenacao.c
CC = gcc

# Regra default para criar o programa
all: ordenacao

# Compilando o programa
ordenacao.o: ordenacao.c
	gcc -g -Wall -c ordenacao.c

# Ligando o programa
ordenacao: ordenacao.o
	gcc -g ordenacao.o -o ordenacao

# Limpando tudo o que foi gerado automaticamente pelo comando clean
clean:
	/bin/rm -f ordenacao ordenacao.o