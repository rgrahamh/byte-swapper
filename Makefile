CC=gcc
CFLAGS= -g -Wall

default:
	${CC} ${CFLAGS} -o byte_swap byte_swap.c
