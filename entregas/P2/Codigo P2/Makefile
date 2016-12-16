all: ejercicio5 ejercicio4



ejercicio5: ejercicio5.o ordenacion.o permutaciones.o tiempos.o 
	    gcc -o ejercicio5 ejercicio5.o permutaciones.o ordenacion.o tiempos.o

ejercicio4: ejercicio4.o ordenacion.o permutaciones.o
	    gcc -o ejercicio4 ordenacion.o permutaciones.o ejercicio4.o


ejercicio5.o: ejercicio5.c
	      gcc -c -g -ansi -pedantic  ejercicio5.c

ejercicio4.o: ejercicio4.c
	      gcc -c -ansi -pedantic  ejercicio4.c

ordenacion.o: ordenacion.c ordenacion.h
	      gcc -c -g -ansi -pedantic ordenacion.c

permutaciones.o: permutaciones.c permutaciones.h
	      gcc -c -g -ansi -pedantic permutaciones.c

tiempos.o: tiempos.c tiempos.h
	   gcc  -c -g -ansi -pedantic tiempos.c

clean:
	rm -f *.o
