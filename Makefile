CFLAGS = -g -Wall
SRCS = ordenacao.c
CC = gcc

temporizador.o: ordenacao.c
    gcc -g -Wall -c ordenacao.c
