projet : fct_lettre.o fct_login.o fct_chiffres.o main.o
	gcc -o projet fct_lettre.o fct_login.o fct_chiffres.o main.o


fct_chiffres.o : fct_chiffres.c declar.h
	gcc -c declar.h fct_chiffres.c


fct_lettre.o : fct_lettre.c declar.h
	gcc -c declar.h fct_lettre.c


fct_login.o : fct_login.c declar.h
	gcc -c declar.h fct_login.c


main.o : fct_login.c declar.h fct_lettre.c fct_chiffres.c main.c
	gcc -c  declar.h fct_login.c fct_lettre.c fct_chiffres.c main.c