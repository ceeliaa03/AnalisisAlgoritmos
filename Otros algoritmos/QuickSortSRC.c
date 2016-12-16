int QuickSort_src(int* tabla, int ip, int iu)
{
    int medio;
    int OB = 0;
    
    if (tabla == NULL)
        return ERR;
    
    while (ip < iu){
        medio = partir(tabla, ip, iu, &OB);
        if (ip < medio - 1)
            OB += QuickSort_src(tabla, ip, medio - 1);
        ip = medio + 1;
    }
    
    return OB;
}

int QuickSort_sr(int* tabla, int ip, int iu)
{
    int prin = ip;
	int fin = iu;
    int OB = 0;
	int i = 0;
    int* m = (int *) malloc((iu-ip+1)*sizeof(m[0]));
    if (tabla == NULL)
        return ERR;
    
    
    while (prin < iu){
        m[i] = partir(tabla, prin, fin, &OB);
        if (prin < fin){
            fin = m[i] - 1;
            i++;
        }
        else {
            i--;
            prin = m[i] + 1;
            if (i > 0)
                fin = m[i - 1];
            else
                fin = iu;
        }
    }
    free(m);
    return OB;
}


/***************************************************/
/* Funcion: QuickSort_SRC Fecha: 23/10/2015        */
/* Autores: 				           */
/*                                                 */
/* Funcion que ordena una lista de menor a mayor   */
/* entre los indices pasados ip e iu, mediante     */
/* el algoritmo QuickSort eliminando la            */
/* recursión de cola.                              */
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int : Numero de veces ejecutado el OB           */
/* o en caso de error ERR                          */

/***************************************************/

int QuickSort_SRC(int* tabla, int ip, int iu) {
    int m,OB=0;
    if (!tabla || ip > iu)
        return ERR;
    while(ip < iu){
      m = partir(tabla, ip, iu);
      OB+=iu-ip;    
      if (ip<m-1)
          OB += QuickSort_SRC(tabla,ip,m-1);
      ip=m+1;
    }
    return OB;
}

/***************************************************/
/* Funcion: QuickSort_SRC2 Fecha: 23/10/2015        */
/* Autores: 				           */
/*                                                 */
/* Funcion que ordena una lista de menor a mayor   */
/* entre los indices pasados ip e iu, mediante     */
/* el algoritmo QuickSort eliminando la            */
/* recursión de cola quedandose con la tabal arriba*/
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int : Numero de veces ejecutado el OB           */
/* o en caso de error ERR                          */

/***************************************************/

int QuickSort_SRC2(int* tabla, int ip, int iu) {
    int m,OB=0;
    if (!tabla || ip > iu)
        return ERR;
    while(ip < iu){
      m = partir(tabla, ip, iu);
      OB+=iu-ip;    
      if (iu>m+1)
          OB += QuickSort_SRC2(tabla,m+1,iu);
      iu=m-1;
    }
    return OB;
}

/***************************************************/
/* Funcion: QuickSort_SRC3 Fecha: 23/10/2015        */
/* Autores: 				           */
/*                                                 */
/* Funcion que ordena una lista de menor a mayor   */
/* entre los indices pasados ip e iu, mediante     */
/* el algoritmo QuickSort eliminando la            */
/* recursión de cola quedandose con la tabal corta */
/*                                                 */
/* Entrada:                                        */
/* int *tabla: tabla permutada para ordenar        */
/* int ip: primer indice de la lista               */
/* int iu: ultimo indice de la lista               */
/* Salida:                                         */
/* int : Numero de veces ejecutado el OB           */
/* o en caso de error ERR                          */

/***************************************************/

int QuickSort_SRC3(int* tabla, int ip, int iu) {
    int m,OB=0;
    if (!tabla || ip > iu)
        return ERR;
    while(ip < iu){
      m = partir(tabla, ip, iu);
      OB+=iu-ip;
    /*(m-1)-ip-( iu-(m+1))*/ /* Si es negativo la parte de arriba es mayor */
    
    if((2*m-ip-iu)<0){  

      if (ip<m-1) /* Caso parte abajo recursion */
        OB += QuickSort_SRC(tabla,ip,m-1);
        ip=m+1;
      }
      else {
      if (iu>m+1) /* Caso parte arriba recursion o partes iguales */
          OB += QuickSort_SRC2(tabla,m+1,iu);
      iu=m-1;
      }
    }
    return OB;
}

