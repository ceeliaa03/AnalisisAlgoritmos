all: ejercicio5

ejercicio5: ejercicio5.o ordenacion.o permutaciones.o tiempos.o 
	    gcc -o ejercicio5 ejercicio5.o permutaciones.o ordenacion.o tiempos.o


ejercicio5.o: ejercicio5.c
	      gcc -c -g -pedantic -O3 ejercicio5.c

ordenacion.o: ordenacion.c ordenacion.h
	      gcc -c -g  -O3 -pedantic ordenacion.c

permutaciones.o: permutaciones.c permutaciones.h
	      gcc -c -g  -O3 -pedantic permutaciones.c

tiempos.o: tiempos.c tiempos.h
	   gcc  -c -g  -O3 -pedantic tiempos.c

clean:
	rm -f *.o
