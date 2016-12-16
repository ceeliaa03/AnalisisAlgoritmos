
/***************************************************/
/* Funcion: BubbleSort    Fecha: 25/09/2015        */
/* Autores:  				           */
/*                                                 */
/* Funcion que ordena una lista de menor a mayor   */
/* entre los indices pasados ip e iu, mediante     */
/* el algoritmo BubbleSort visto en teoria         */
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int :Numero de veces ejecutado la OB            */
/* o en caso de error ERR                          */

/***************************************************/

int BubbleSort(int* tabla, int ip, int iu)
{
	int i, j, cont = 0, flag = 1;
	assert(tabla != NULL);
	assert(ip <= iu);
	for (i = iu; (i > ip) && flag == 1; i--)
	{
		flag = 0;
		for (j = ip; j < i; j++, cont++)
		{
			if (tabla[j] > tabla[j+1])
			{
				swap(&tabla[j], &tabla[j+1]);	
				flag = 1;
			}
		}
	}
	return cont;
}

/***************************************************/
/* Funcion: BubbleSort2    Fecha: 25/09/2015       */
/* Autores:  				           */
/*                                                 */
/* Funcion que ordena una lista de menor a mayor   */
/* entre los indices pasados ip e iu, de manera    */
/* inversa a la realizada por el algoritmo BS, es  */
/* decir, yendo del último al primero.             */
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int :Numero de veces ejecutado la OB            */
/* o en caso de error ERR                          */

/***************************************************/

int BubbleSort2(int* tabla, int ip, int iu) {
    int Flag = 1, i = ip, j, OB = 0;
    if (ip > iu || !tabla || ip < 0)return ERR; /* CDE */

    while (Flag == 1 && i <= (iu - 1)) {
        Flag = 0;
        for (j = iu; j > i; j--) {
            OB++; /* contador numero veces ejecuta OB */
            if (tabla[j] < tabla[j - 1]) {
                swap(&tabla[j], &tabla[j - 1]);
                Flag = 1;
            }
        }
        i++;
    }
    return OB;
}


/***************************************************/
/* Funcion: BubbleSortInv Fecha: 25/09/2015        */
/* Autores:  				           */
/*                                                 */
/* Funcion que ordena una lista de mayor a menor   */
/* entre los indices pasados ip e iu, mediante     */
/* el algoritmo BubbleSort visto en teoria         */
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int : Numero de veces ejecutado el OB           */
/* o en caso de error ERR                          */

/***************************************************/

int BubbleSortInv(int* tabla, int ip, int iu)
{
	int i, j, cont = 0, flag = 1;
	assert(tabla != NULL);
	assert(ip <= iu);
  	for (i = iu; (i > ip) && flag == 1; i--)
	{
	
	flag = 0;
		for (j = ip; j < i; j++, cont++)
		{
			if (tabla[j] < tabla[j+1])
			{
				swap(&tabla[j], &tabla[j+1]);
				flag = 1;
			}
		}
	}
	return cont;
}
