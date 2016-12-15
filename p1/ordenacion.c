/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */


#include "ordenacion.h"
#include <stdlib.h>
#include <stdio.h>

/***************************************************/
/* Funcion: InsertSort    Fecha:10/2016            */
/* Entrada:                                        */
/* tabla de enteros a ordenar entre los indices ip */
/* (inferior) e iu (superior)                      */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int InsertSort(int* tabla, int ip, int iu)
{
    int i, j, k, ob=1;
	if(!tabla || ip<0 || ip<ip) return ERR;
    
    for(i = ip+1; i <= iu; i++){
        k = tabla[i];
        j = i-1;
        while( ip <= j && tabla[j] > k){
			ob++;
            tabla[j+1] = tabla[j];
            j--;
        }
        tabla[j+1] = k;
    }
    return ob;
}

/***************************************************/
/* Funcion: InsertSortInv    Fecha: 10/16          */
/* Entrada:                                        */
/* tabla de enteros a ordenar (descendente) entre  */
/* los indices ip (inferior) e iu (superior)       */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int InsertSortInv(int* tabla, int ip, int iu)
{
   int i, j, k, ob=1;
	if(!tabla || ip<0 || iu<ip) return ERR;
    
    for(i = ip+1; i <= iu; i++){
        k = tabla[i];
        j = i-1;
        while( ip <= j && tabla[j] < k){
			ob++;
            tabla[j+1] = tabla[j];
            j--;
        }
        tabla[j+1] = k;
    }
	return ob;
}
