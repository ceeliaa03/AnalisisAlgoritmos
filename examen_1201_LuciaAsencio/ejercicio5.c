/***********************************************************/
/* Programa: ejercicio5                  Fecha:            */
/* Autores:  Simon y Lucia                                 */
/*                                                         */
/* Programa que escribe en un fichero                      */
/* los tiempos medios del algoritmo de                     */
/* ordenacion por Seleccion                                */
/*                                                         */
/* Entrada: Linea de comandos                              */
/* -num_min: numero minimo de elementos de la tabla        */
/* -num_max: numero minimo de elementos de la tabla        */
/* -incr: incremento\n                                     */
/* -numP: Introduce el numero de permutaciones a promediar */
/* Salida: 0 si hubo error                                 */
/* -1 en caso contrario                                    */
/***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordenacion.h"
#include "tiempos.h"

/*NUEVOS PARÁMETROS PARA EJ5: 		SIN FICHERO	 */
/* -num_min <int> -num_max <int> -incr <int> -numP <int> */
int main(int argc, char** argv)
{
  int i, num_min, num_max, incr, n_perms;
  short ret;

  srand(time(NULL));

  if (argc != 9) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -num_min <int> -num_max <int> -incr <int>\n", argv[0]);
    fprintf(stderr, "\t\t -numP <int> \n");
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, "-num_min: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-num_max: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-incr: incremento\n");
    fprintf(stderr, "-numP: Introduce el numero de permutaciones a promediar\n");
    exit(-1);
  }

  printf("Practica numero 1, apartado 5\n");
  printf("Realizada por: Simon y Lucia \n");
  printf("Grupo: 6\n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc ; i++) {
    if (strcmp(argv[i], "-num_min") == 0) {
      num_min = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-num_max") == 0) {
      num_max = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-incr") == 0) {
      incr = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-numP") == 0) {
      n_perms = atoi(argv[++i]);
    } else {
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }


	ret = genera_tiempos_ordenacion(quicksort, "quicksort_ip.log",num_min, num_max,incr, n_perms, 0);
	if (ret == ERR ) { /* ERR_TIME debera ser un numero negativo */
		printf("Error en la funcion Time_Ordena\n");
		exit(-1);
	}
	
	/*tiempos para insertquick con L=100 */
	ret = genera_tiempos_ordenacion(InsertQuickSort100, "insertquick100.log",num_min, num_max,incr, n_perms, 0);
	if (ret == ERR ) { /* ERR_TIME debera ser un numero negativo */
		printf("Error en la funcion Time_Ordena\n");
		exit(-1);
	}
	/*tiempos para insertquick con L = 200*/
	ret = genera_tiempos_ordenacion(InsertQuickSort200, "insertquick200.log",num_min, num_max,incr, n_perms, 0);
	if (ret == ERR ) { /* ERR_TIME debera ser un numero negativo */
		printf("Error en la funcion Time_Ordena\n");
		exit(-1);
	}
	/*tiempos para insertquick con L = 300*/
	ret = genera_tiempos_ordenacion(InsertQuickSort300, "insertquick300.log",num_min, num_max,incr, n_perms, 0);
	if (ret == ERR ) { /* ERR_TIME debera ser un numero negativo */
		printf("Error en la funcion Time_Ordena\n");
		exit(-1);
	}
	/*tiempos para insertquick con L = 400*/
	ret = genera_tiempos_ordenacion(InsertQuickSort400, "insertquick400.log",num_min, num_max,incr, n_perms, 0);
	if (ret == ERR ) { /* ERR_TIME debera ser un numero negativo */
		printf("Error en la funcion Time_Ordena\n");
		exit(-1);
	}
  
  printf("Salida correcta \n");

  return 0;
}


