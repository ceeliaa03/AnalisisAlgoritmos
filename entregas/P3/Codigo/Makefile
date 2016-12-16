all: ejercicio1 ejercicio2

ejercicio1: ejercicio1.o busqueda.o permutaciones.o
	gcc -o ejercicio1 ejercicio1.o busqueda.o permutaciones.o

ejercicio2: ejercicio2.o busqueda.o permutaciones.o tiempos.o
	gcc -o ejercicio2 ejercicio2.o busqueda.o permutaciones.o tiempos.o

ejercicio1.o: ejercicio1.c
	gcc -c -g  -Wall ejercicio1.c

ejercicio2.o: ejercicio2.c
	gcc -c -g -Wall ejercicio2.c
	
tiempos.o: tiempos.c tiempos.h
	gcc -c -g -Wall tiempos.c
	
busqueda.o: busqueda.c busqueda.h
	gcc -c -g -Wall busqueda.c
	
ordenacion.o: ordenacion.c ordenacion.h
	gcc -c -g -Wall ordenacion.c

	
permutaciones.o: permutaciones.c permutaciones.h
	gcc -c -g -Wall permutaciones.c

clean:
	rm -f *.o *~ 
