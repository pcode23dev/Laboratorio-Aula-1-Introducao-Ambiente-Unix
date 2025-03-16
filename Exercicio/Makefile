main: main.o implementacao.o
	gcc -o main main.o implementacao.o
main.o: main.c TAD.h
	gcc -g -c main.c
implementacao.o: implementacao.c TAD.h
	gcc -g -c implementacao.c
clean:
	rm -f *.o main
start:
	./main
