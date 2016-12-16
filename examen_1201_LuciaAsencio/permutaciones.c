/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */


#include "permutaciones.h"
#include <stdlib.h>
#include <stdio.h>

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
    int x, rn;
    if(inf<0 || inf>sup) return ERR;
    x=rand();
    rn = x%(sup - inf+1); /*genera un numero menor o igual que sup-inf*/
    return inf + rn;
    
}


/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int n){
 int i, temp, ran;
 int* perm = (int *)malloc((n)*sizeof(int));
 if(!perm) return NULL;
 for (i=0; i<n;i++){
     perm[i]=i+1;
 }
 
 for (i=0; i<n; i++){
     ran = aleat_num(i,n-1);
     temp=perm[i];
     perm[i]= perm[ran];
     perm[ran]=temp;
 }
 return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int tamanio: Numero de elementos de cada        */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int tam){
    int i, j;
    int **APerm;
    if(n_perms<0 || tam<0) return NULL;
    APerm = (int **) malloc (n_perms * sizeof(int *));
    if (!APerm)
        return NULL;
    for (i = 0; i< n_perms; i++){
        APerm[i] = genera_perm(tam);
	if(!APerm[i]){
		for(j = 0; j<i; j++){
			free(APerm[i]);
		}
	free(APerm);
	return NULL;
	}
    }

    return APerm;
}

