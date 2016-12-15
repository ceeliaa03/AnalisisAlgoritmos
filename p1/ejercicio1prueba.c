/***********************************************/
/* Programa: ejercicio1     Fecha:             */
/* Autores:                                    */
/*                                             */
/* Programa que genera numeros aleatorios      */
/* entre dos numeros dados                     */
/*                                             */
/* Entrada: Linea de comandos                  */
/* -limInf: limite inferior                    */
/* -limSup: limite superior                    */
/* -numN: cantidad de numeros                  */
/* Salida: 0: OK, -1: ERR                      */
/***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutaciones.h"

/*******************************************/
/* Funcion: aleat_num              Fecha:  */
/* Autores:                                */
/*                                         */
/*  Rutina que genera un numero aleatorio  */
/*  entre dos numeros dados                */
/*                                         */
/*  Entrada:                               */
/*     int inf: limite inferior            */
/*     int sup: limite superior            */
/*  Salida:                                */
/*     int:  numero aleatorio              */
/*******************************************/

int main(int argc, char** argv){


  int *frec; /*Usaremos como tabla para comprobar aleatoriedad*/ 
  int i, aleat;
  unsigned int inf, sup, num, j;

  srand(time(NULL));

  if (argc != 7) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -limInf <int> -limSup <int> -numN <int>\n", argv[0]);
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, " -limInf : Limite inferior.\n");
    fprintf(stderr, " -limSup : Limite superior.\n");
    fprintf(stderr, " -numN : Cantidad de numeros a generar.\n");
    exit(-1);
  }
  printf("Practica numero 1, apartado 1\n");
  printf("Realizada por: Simon y Lucia\n");
  printf("Grupo: Grupo 6 \n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-limInf") == 0) {
      inf = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-limSup") == 0) {
      sup = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-numN") == 0) {
      num = atoi(argv[++i]);
    } else {
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }
  if (inf<1 || sup<1){
      printf("Solo admite parametros positivos");
      return ERR;
  }
  
    if (inf>sup){
      printf("El Inf ha de ser menor que el Sup");
      return ERR;
  }
  

  
  frec = (int *)malloc((sup - inf + 1) *sizeof(int));
  if(!frec)
	return ERR;
  /* obtenemos los numeros y guardamos la frecuencia con que aparecen en un array */
  for(j = 0; j < num; j++) { 
    aleat = aleat_num(inf, sup);
    frec[aleat - inf]++;
  }
  /*Imprimimos información del array*/
  for(j=0; j<(sup - inf + 1); j++){
    printf("Nº %d: %d veces\n", inf+j, frec[j]);
  }

  free(frec);
  return 0;
}
