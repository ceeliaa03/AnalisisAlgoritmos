/**
 *
 * Descripcion: Implementacion funciones para busqueda 
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en 
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */
  
/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma 
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max){
  int i;

  for(i = 0; i < n_claves; i++) claves[i] = 1 + (i % max);

  return;
}

/**
 *  Funcion: generador_claves_potencial
 *               Esta funcion genera siguiendo una distribucion aproximadamente
 *               potencial. Siendo los valores mas pequenos mucho mas probables
 *               que los mas grandes. El valor 1 tiene una probabilidad del 50%,
 *               el dos del 17%, el tres el 9%, etc.
 */
void generador_claves_potencial(int *claves, int n_claves, int max){
  int i;

  for(i = 0; i < n_claves; i++) {
    claves[i] = (1+max) / (1 + max*((double)rand()/RAND_MAX));
  }

  return;
}

PDICC ini_diccionario (int tamanio, char orden){	
	if(tamanio<0) return NULL;
	int i=0;
	PDICC d;
	d= (PDICC) malloc(sizeof(DICC));
	d->tamanio=tamanio;
	d->orden=orden;
	d->n_datos=0;
	d->orden= orden;
	d->tabla= (int*) malloc(tamanio*sizeof(int));
	if(! d->tabla) return NULL;
	for(i=0; i>tamanio; i++)
		d->tabla[i]=0;

	return d;
	
}

void libera_diccionario(PDICC pdicc){
	if(!pdicc)
		return;
	if(pdicc->tabla)
		free(pdicc->tabla);
	free(pdicc);	
}

int inserta_diccionario(PDICC pdicc, int clave){
	int i=0, ob=0;
	if(!pdicc) return ERR;
	
	
	if(pdicc->orden== NO_ORDENADO){
		pdicc->tabla[++(pdicc->n_datos)-1]=clave;
		return 0;
	}
	else if(pdicc->orden==ORDENADO){
	
		pdicc->tabla[pdicc->n_datos] = clave;
		pdicc->n_datos ++;
		i = pdicc->n_datos-2;
		while(i >= 0 && pdicc->tabla[i]> clave){
			pdicc->tabla[i+1] = pdicc->tabla[i];
			i--;
			ob++;
		}
		pdicc->tabla[i+1] = clave;
		return ob+1;
	}
	return ERR;
	/*
		(pdicc->n_datos)++;
		pdicc->tabla[pdicc->n_datos-1]=clave;
		for(i=pdicc->n_datos-2; i>=0; i--){
				if(pdicc->tabla[i]<pdicc->tabla[i+1])
					return 1;
				if(i > 0)
					swap(pdicc->tabla, i, i-1);
			}
	}  
	
	if(i!=-1)
		return 0;
	else
		return 1;*/
	
}

void swap(int * arr, int p1, int p2){
	if(!arr) return;
	int i;
	i= arr[p1];
	arr[p1]= arr[p2];
	arr[p2]= i;
	return;
	

}

int insercion_masiva_diccionario (PDICC pdicc,int *claves, int n_claves){
	int i, ob=0, obbuff;
	if(!claves || !pdicc || n_claves<1) return 0;
	if(n_claves+pdicc->n_datos > pdicc->tamanio)
		return ERR;
		
		
	for(i=0; i<n_claves; i++){
		obbuff = inserta_diccionario(pdicc, claves[i]);	
		if(obbuff == ERR)
			return ERR;
		ob += obbuff;	
	}
	return ob;
}

void print_tabla(PDICC pdicc){

	int i;
	if(!pdicc) return;
	for(i=0; i<pdicc->n_datos; i++)
		printf("%d ", pdicc->tabla[i]);
		printf("\n");
}

int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo){
	if(!pdicc || !metodo) return ERR;
	
	return (* metodo)(pdicc->tabla, 0, pdicc->n_datos - 1, clave, ppos);
}

void imprime_diccionario(PDICC pdicc){
	if(pdicc) return;
	printf("Tamaño: %d\n", pdicc->tamanio);
	printf("Número de datos: %d\n", pdicc->n_datos);
	printf("Ordenado: %c\n", pdicc->orden);
	print_tabla(pdicc);
	
}

/* Funciones de busqueda del TAD Diccionario */
int bbin(int *tabla,int P,int U,int clave,int *ppos){
	int ob = 1;
	int medio;
	if(!tabla || P>U || U<0) return ERR;
	
	*ppos = NO_ENCONTRADO;
	medio = (P+U)/2;
	if (clave == tabla[medio])
		*ppos = medio+1;
	else if(clave < tabla[medio] )
		ob = 2 + bbin(tabla, P, medio-1, clave, ppos);
	else
		ob = 2 + bbin(tabla, medio+1, U, clave, ppos);
	return ob;
	
}

int blin(int *tabla,int P,int U,int clave,int *ppos){
	int ob = 0;
	int i;
	if(!tabla || P>U || U<0) return ERR;
	
	*ppos = NO_ENCONTRADO;
	for(i = P; i <= U ; ob ++, i++){
		if(clave==tabla[i]){
			*ppos = i+1;
			break;
		}
	}
	ob++;
	return ob;
}


/*Esta función no DEVUELVE en ppos la POSICION DE LA CLAVE en la tabla inicial,
 sino UNA VEZ SWAPEADA*/
int blin_auto(int *tabla,int P,int U,int clave,int *ppos){
	int ob = 1;
	int i;
	if(!tabla || P>U || U<0) return ERR;
	
	*ppos = NO_ENCONTRADO;
	for(i = P; i <= U; ob ++, i++){
		if(clave == tabla[i]){
			if(i>0){
			swap(tabla, i, i-1);
			*ppos = i-1;
			break;
			}else{
			*ppos=i;
			break;}

		}
	}
	return ob;
}


