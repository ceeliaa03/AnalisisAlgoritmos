/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */

#include "permutaciones.h"
#include "tiempos.h"
#include "ordenacion.h"
#include "busqueda.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*Parametros: METODO de ordenacion a utilizar,	   */
/*NºPERMutaciones a probar y su TAManio		   */
/*						   */
/*PIVOTE: metodo de eleccion del pivote, 0, 1 o 2, */
/*solo se usa si metodo es quicksort		   */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int tamanio, 
                              PTIEMPO ptiempo, int pivote)
{
	int i, obBuff, obMed=0;
	float t1, t2, tDiff, tMed=0; 
	int **ArrPerm;

	ptiempo->n_perms=n_perms;
	ptiempo->tamanio= tamanio;
	ptiempo->min_ob= INT_MAX;
	ptiempo->max_ob= 0;

	if(!metodo || n_perms<1 || tamanio<1 || !ptiempo) return ERR;

	ArrPerm= genera_permutaciones( n_perms,  tamanio);
	if(!ArrPerm) return ERR;
    
	for(i=0; i<n_perms; i++){
			t1=clock();
		/*for (j=0; j<tamanio; j++) printf("%d ", ArrPerm[i][j]);
		printf("\n");*/

		/*Si metodo escogido es quicksort, añadimos parametro pivote*/
		/*if(metodo == quicksort){
			obBuff= metodo(ArrPerm[i], 0, tamanio-1, pivote);
		}
		else{*/
	      		obBuff= metodo(ArrPerm[i], 0, tamanio-1, pivote);	
		/*}*/

		/*for (j=0; j<tamanio; j++) printf("%d ", ArrPerm[i][j]);
		printf("\n\n");*/
		if(obBuff == ERR) return ERR;
			t2=clock();
		if(obBuff<ptiempo->min_ob){
			ptiempo->min_ob=obBuff;
		}
		if(ptiempo->max_ob<obBuff){
			ptiempo->max_ob=obBuff;
		}
		obMed+= obBuff;

		tDiff= (t2-t1)/CLOCKS_PER_SEC;
		tMed+=tDiff;

	} 
	ptiempo->tiempo=tMed/n_perms;
	ptiempo->medio_ob=obMed/n_perms;

	for(i=0; i<n_perms; i++){
		if(ArrPerm[i])
			free(ArrPerm[i]);
	}
	free(ArrPerm);

    return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*Parametros: METODO de ordenacion a utilizar, FICH*/
/*ero a escribir, tamaño MINimo y MAXimo de las per*/
/*mutaciones, y el INCRemento entre sus tamaños.   */
/*Nº PERMutaciones a probar con cada tamaño	   */
/*						   */
/*PIVOTE: metodo de eleccion del pivote, 0, 1 o 2, */
/*solo se usa si metodo es quicksort*/
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms, int pivote)
{
    
	int iter=0, i, j, tamanio;

	iter=((num_max-num_min)/incr)+1;
	PTIEMPO * pptiempo= (PTIEMPO *)malloc(sizeof(PTIEMPO)*iter);
 	if(!pptiempo) return ERR;

	if(!fichero || !metodo || num_min<1 || num_min>num_max || incr<1 || n_perms<1)
	return ERR;

	for(i=0; i<iter; i++){
		pptiempo[i]= (PTIEMPO) malloc(sizeof(TIEMPO));
		if(!pptiempo[i]){
			for(j = 0; j<i; j++){
				free(pptiempo[j]);
			}
		free(pptiempo);
		return ERR;
		}	
	}
	for(i=0, tamanio=num_min; i<iter; i++, tamanio+=incr){
		tiempo_medio_ordenacion( metodo, n_perms, tamanio, pptiempo[i], pivote);
		guarda_tabla_tiempos(fichero, pptiempo[i], 1);
	}    
	for(i = 0; i<iter; i++){
		if(pptiempo[i])
			free(pptiempo[i]);
		}
	free(pptiempo);

	return OK;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*Parametros: nombre del fichero a escribir,PTIEMPO*/
/*con la informacion a escribir, tamaño del array  */
/* de tiempos  			                   */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int N)
{
	FILE *f;
	if(!fichero || !tiempo || N<1) return ERR;
	f = fopen(fichero, "a");

	fprintf(f,"%d %f %d %d %d \n", tiempo->tamanio, tiempo->tiempo, 
			tiempo->medio_ob, tiempo->min_ob, tiempo->max_ob);
	fclose(f);
	return OK;
}

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/* Parametros: metodo de busqueda a utilizar, funci*/
/* generadora de claves, orden y tamaño del diccio */
/* nario a utilizar, numero de claves a buscar nve */
/* ces, ptiempo en el que gardar resultados	   */
/***************************************************/
short tiempo_medio_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador,
                              int orden, int tamanio, int n_claves, int n_veces,
                              PTIEMPO ptiempo){
        
        PDICC d = NULL;
        int* perm, claves[n_veces*n_claves];
        int i, pos, obBuff;
        long long obMed = 0;
        float t1, t2, tResta, tMed = 0;
        
        
	if(!metodo || !generador || (orden != 1 && orden != 0) || n_claves<1 
	|| tamanio<1 || n_veces<1 || !ptiempo) return ERR;
	
	/*Inicializamos valores conocidos de PTIEMPO*/
	ptiempo->n_perms=n_claves;
	ptiempo->tamanio= tamanio;
	ptiempo->n_veces = n_veces;
	ptiempo->min_ob= INT_MAX;
	ptiempo->max_ob= 0;
	
	/*Creamos dicc, 
	creamos permutacion y la insertamos, 
	creamos tabla de claves a buscar*/
	d = ini_diccionario(tamanio, orden);
	if(d == NULL) return ERR;
	perm = genera_perm(n_claves);
	if(perm == NULL){
		libera_diccionario(d);
		return ERR;
	}
	if(insercion_masiva_diccionario(d, perm, n_claves) == ERR){
		libera_diccionario(d);
		free(perm);
		return ERR;
	}
	generador(claves, n_claves*n_veces, n_claves);
	
	/*Bucle de llamadas a metodo*/
	for(i = 0; i < n_claves*n_veces; i++){
		/*LLamada a metodo, midiendo el tiempo de ejecucion*/
		t1 = clock();
		obBuff = busca_diccionario(d, claves[i], &pos, metodo);
		if(obBuff == ERR){
			libera_diccionario(d);
			free(perm);
			return ERR;
		}
		t2 = clock();
		
		/*Actualizacion de los valores de PTIEMPO*/
		if(obBuff<ptiempo->min_ob){
			ptiempo->min_ob=obBuff;
		}
		if(ptiempo->max_ob<obBuff){
			ptiempo->max_ob=obBuff;
		}
		obMed+= obBuff;
		tResta = (t2 - t1);
		tMed+=tResta;	
	}
	
	ptiempo->tiempo=tMed/(n_claves * n_veces);
	ptiempo->medio_ob=obMed/(n_claves * n_veces);
	
	/*Liberamos recursos*/
	libera_diccionario(d);
	free(perm);
	return OK;	
}





/***************************************************/
/* Funcion: genera_tiempos_busqueda   Fecha:       */
/*Parametros: metodo de busqueda, funcion generado */
/*ra de claves a usar, orden del diccionario a cre */
/*ar, fichero en el que escribir resultados, num_m */
/*in y num_max los tamaños entre los que varia el  */
/*diccionario, incremento entre sus tamaños.	   */
/* numero de veces que se buscara cada clave	   */
/***************************************************/
short genera_tiempos_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador, 
                                int orden, char* fichero, int num_min, int num_max, 
                                int incr, int n_veces){
                                
	int iter=0, i, j, tamanio;
	
	iter=((num_max-num_min)/incr)+1;
	PTIEMPO * pptiempo= (PTIEMPO *)malloc(sizeof(PTIEMPO)*iter);
 	if(!pptiempo) return ERR;
 	
 	if(!fichero || !metodo || !generador || (orden != 1 && orden != 0) || num_min<1
 	 || num_min>num_max || incr<1 || n_veces<1)
	return ERR;
	
	/*Generamos array de PTIEMPO*/
	for(i=0; i<iter; i++){
		pptiempo[i]= (PTIEMPO) malloc(sizeof(TIEMPO));
		if(!pptiempo[i]){
			for(j = 0; j<i; j++){
				free(pptiempo[j]);
			}
		free(pptiempo);
		return ERR;
		}	
	}
	
	/*Hacemos tantas llamadas a tiempo_medio_busqueda como iteraciones,
	guardamos los resultados*/
	for(i=0, tamanio=num_min; i<iter; i++, tamanio+=incr){
		tiempo_medio_busqueda( metodo, generador, orden, tamanio, tamanio,
		 n_veces, pptiempo[i]);
		guarda_tabla_tiempos(fichero, pptiempo[i], 1);
	} 
	
	/*Liberamos recursos*/   
	for(i = 0; i<iter; i++){
		if(pptiempo[i])
			free(pptiempo[i]);
		}
	free(pptiempo);
	return OK;                                
                                
}
