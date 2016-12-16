all: ejercicio5

ejercicio5: ejercicio5.o ordenacion.o permutaciones.o tiempos.o 
	    gcc -o ejercicio5 ejercicio5.o permutaciones.o ordenacion.o tiempos.o


ejercicio5.o: ejercicio5.c
	      gcc -c -g -pedantic  ejercicio5.c

ordenacion.o: ordenacion.c ordenacion.h
	      gcc -c -g -pedantic ordenacion.c

permutaciones.o: permutaciones.c permutaciones.h
	      gcc -c -g -pedantic permutaciones.c

tiempos.o: tiempos.c tiempos.h
	   gcc  -c -g -pedantic tiempos.c

clean:
	rm -f *.o
