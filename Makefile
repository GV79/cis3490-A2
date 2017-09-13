all: main
main:
	gcc main.c P11.c P12.c P21.c -std=c99 -Wall -pedantic -lm -o main
