myprog: complex.o mycomp.o 
	gcc -g -ansi -Wall -pedantic complex.o mycomp.o -o myprog -lm
mycomp.o: mycomp.c complex.h
	gcc -c -ansi -Wall -pedantic mycomp.c -o mycomp.o
complex.o: complex.c complex.h
	gcc -c -ansi -Wall -pedantic complex.c -o complex.o -lm

