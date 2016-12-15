all: main busqueda_test ejercicio1 ejercicio2

ejercicio1: ejercicio1.o busqueda.o permutaciones.o
	gcc -o ejercicio1 ejercicio1.o busqueda.o permutaciones.o

ejercicio2: ejercicio2.o busqueda.o permutaciones.o tiempos.o
	gcc -o ejercicio2 ejercicio2.o busqueda.o permutaciones.o tiempos.o
	
busqueda_test: busqueda_test.o  busqueda.o
	gcc -o busqueda_test busqueda_test.o busqueda.o
	
main: main.o  busqueda.o
	gcc -o main main.o busqueda.o

ejercicio1.o: ejercicio1.c
	gcc -c -g -Wall -pedantic ejercicio1.c

ejercicio2.o: ejercicio2.c
	gcc -c -g -Wall -pedantic ejercicio2.c

busqueda_test.o: busqueda_test.c
	gcc -c -g -Wall -pedantic busqueda_test.c

main.o: main.c
	gcc -c -g -Wall -pedantic main.c
	
tiempos.o: tiempos.c tiempos.h
	gcc -c -g -Wall -pedantic tiempos.c
	
busqueda.o: busqueda.c busqueda.h
	gcc -c -g -Wall -pedantic busqueda.c
	
ordenacion.o: ordenacion.c ordenacion.h
	gcc -c -g -Wall -pedantic ordenacion.c

	
permutaciones.o: permutaciones.c permutaciones.h
	gcc -c -g -Wall -pedantic permutaciones.c

clean:
	rm -f *.o *~ 
