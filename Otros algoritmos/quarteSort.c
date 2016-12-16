
/***************************************************/
/* Funcion: QuarterSort     Fecha: 7/12/2014       */
/* Autores: Javier Hernandez                       */
/*                                                 */
/* Ordena los primeros 1\4 de elementos con mergesort
*/
/* los 3/4 restantes con  quicksort.
   Y las dos subtablas se ordenan con merge.       */
/* Entrada:                                        */
/*                                                 */
/* int * tabla: variable de tipo puntero que apunta*/
/*  a la tabla sin ordernar                        */
/* int ip: variable de tipo entero que indica      */
/* la posición del primer elemento de la tabla     */
/* int iu: variable de tipo entero que indica      */
/* la posición del último elemento de la tabla     */
/* Salida:                                         */
/* numero de obs o ERR en caso de ERR.    */

/***************************************************/

int QuarterSort (int * tabla, int ip, int iu){ 

	int obq=0, obm=0, m1=0, obmm=0; 
	/*Control de errores*/ 
    	if(tabla==NULL || ip > iu || ip < 0) 
        	return ERR; 

	/*Dividimos la tabla en dos, exactamente 1/4 y el restante que son tres cuartos*/ 
	m1=(int)((iu+ip)/4); 

	/*Ordenamos con merge sort lo que se corresponderia a QuarterTable osea al primer cuarto de la tabla contando las obs*/ 
	obq=mergesort(tabla, ip, m1); 
	if(obq==ERR){ 
    		return ERR; 

	} 
	/*Ordenamos con quicksort lo que se corresponderia a ThreeQuartersTable osea a los tres cuartos restantes de la tabla*/ 
	obm=quicksort(tabla, m1+1,iu); 
	if(obm==ERR){ 
    		return ERR; 
	} 
	/*Hacemos las merge de las dos subtablas contando las obs que se utilizan para combinar ambas tablas*/ 
	obmm= merge(tabla,ip, iu, m1); 
	if(obmm==ERR) 
    		return ERR; 

	return obmm + obm +obq; 


} 

