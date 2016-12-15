
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
/***************************************************/
/* Funcion: merge            Fecha: 10/16          */
/* Entrada:                                        */
/* tabla de enteros a ordenar (descendente) entre  */
/* los indices ip (inferior) e iu (superior)       */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int merge(int* tabla, int ip, int iu, int mitad){
	int i,j,k, ob=0;
	int tam = iu-ip+1;
	int *taux = (int *)malloc(tam * sizeof(int));
	if(!taux)
		return ERR;
	i=ip;
	j=mitad +1;
	k=0;
	while(i<=mitad && j<=iu){
		ob++;
		if( tabla[i]<tabla[j]){
			taux[k]=tabla[i];
			i++;
		}
		else{
			taux[k]=tabla[j];
			j++;
		}
		k++;
	}
	if(i > mitad){
		while(j<=iu){
			taux[k]=tabla[j];
			j++;
			k++;
		}
	}else if(j > iu){
		while(i<=mitad){
			taux[k]=tabla[i];
			i++;
			k++;
		}
	}
	for(i=ip, k=0;i<=iu; tabla[i]=taux[k], i++,k++);
	free(taux);
	return ob;
	
}
/***************************************************/
/* Funcion: Mergesort        Fecha: 10/16          */
/* Entrada:                                        */
/* tabla de enteros a ordenar (descendente) entre  */
/* los indices ip (inferior) e iu (superior)       */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int mergesort(int* tabla, int ip, int iu, int pivote_inutil){
	int mitad;
	int ob=0;
	if(!tabla || ip>iu || ip<0)
		return ERR;
	mitad = (ip+iu)/2;
	if(ip == iu)
		return OK;
		
	ob +=mergesort(tabla, ip, mitad, pivote_inutil);
	ob+=mergesort(tabla, mitad + 1, iu, pivote_inutil);
	
	ob= ob + merge(tabla, ip, iu, mitad);
	return ob;
	
}





/***************************************************/
/* Funcion: Quicksort       Fecha: 10/16          */
/* Entrada:                                        */
/* tabla de enteros a ordenar (descendente) entre  */
/* los indices ip (inferior) e iu (superior)       */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int quicksort(int* tabla, int ip, int iu, int pivote){
	int ob=0, pos;
	if(!tabla || ip>iu || ip<0){
		return ERR;}
	if(ip==iu)
		return OK;
	ob+= partir(tabla, ip, iu, &pos, pivote);
	if(ip < pos-1)
		ob+=quicksort(tabla, ip, pos-1, pivote);
	 if(iu > pos+1)
	 	ob+=quicksort(tabla, pos+1, iu, pivote);
 	return ob;
	
	
}





/***************************************************/
/* Funcion: partir           Fecha: 10/16          */
/* Entrada:                                        */
/* Divide la tabla en dos mitades ordenadas una    */
/* con respecto a la otra. Pivote seguarda en pos  */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int partir(int* tabla, int ip, int iu,int *pos, int pivote){

	int i, m, k, aux, ob=0;	
        
	
	if(!tabla || ip<0 || ip>iu) return ERR;
	
	ob += medio(tabla, ip, iu, pos, pivote);
	m = *pos;
	k = tabla[m];

	/* Swap tabla[ip] y tabla[m] */
	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	m = ip;

	for (i=ip+1; i<=iu; i++){
		ob++;
		if (tabla[i] < k){
			m++;
			/* Swap tabla[i] y tabla[m] */
			aux = tabla[i];
			tabla[i] = tabla[m];
			tabla[m] = aux;
		}
	}

	/* Swap tabla[ip] y tabla[m] */
	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	*pos=m;

	return ob;

}

/***************************************************/
/* Funcion: medio            Fecha: 10/16          */
/* Entrada:                                        */
/* tabla de enteros a ordenar (descendente) entre  */
/* los indices ip (inferior) e iu (superior)       */
/* Salida:                                         */
/* Numero de veces que la OB ha sido ejecutada/ERR */
/***************************************************/
int medio(int *tabla, int ip, int iu,int *pos, int pivote){
	if(!tabla || ip>iu || ip<0 || pivote<0 || pivote >2)
		return ERR;
	int ob = 0, med = (ip+iu)/2;
	switch (pivote) {
		case 0:
			/*Pivote es el primer elemento*/
			*pos = ip;
			break;
		case 1:
			/*El pivote es el elemento medio*/
			*pos = med;
			break;
		case 2:
			/*El pivote es "medio_stat" del enunciado*/
			ob++;
			if(tabla[ip] < tabla[iu]){
				if(tabla[med] < tabla[ip]){
					ob++;
					*pos = ip;			
				}
				else if(tabla[med] > tabla[iu]){
					/*2 comparaciones: if ip<iu y if med>iu*/
					ob += 2;
					*pos = iu;
				}else{
					ob += 2;
					*pos = med;
				}
			}else{
				if(tabla[med] > tabla[ip]){
					ob++;
					*pos = ip;			
				}
				else if(tabla[med] < tabla[iu]){
					/*2 comparaciones: if ip<iu y if med>iu*/
					ob += 2;
					*pos = iu;
				}else{
					ob += 2;
					*pos = med;
				}
			
			}
			break;
		default: 
			ob = 0;
	}
	return ob;	
}




