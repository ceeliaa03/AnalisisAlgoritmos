/***************************************************/
/* Funcion: Minimo Fecha: 17/09/2014               */
/* Autores: Javier Hernandez y Alvaro Clemente     */
/*                                                 */
/* Función que calcula el mínimo en la tabla       */
/* (desde i hasta el último) y lo devuelve.        */
/*  Al encontrarse la OB de la función Select Sort */
/* se calcula también                              */
/*                                                 */
/* Entrada:                                        */
/* int ip: Variable de tipo entero que indica      */
/* la posición del primer elemento de los cuales no*/
/* han sido ordenados todavía.                     */
/* int iu: Variable de tipo entero que indica      */
/* la posición del último elemento de la tabla     */
/* int *ob: variable de tipo puntero que apunta a  */
/* la dirección de memoria donde se encuentra el   */
/* valor de la operación básica                    */
/* Salida:                                         */
/* m: El mínimo valor de los elementos aún no      */
/* ordenados                        */
/* ERR: En caso de producirse algun error          */
 
/***************************************************/
int minimo(int *tabla, int ip, int iu, int * ob) {
    int j=0, m=ip;
    if (tabla == NULL || ob == NULL || ip > iu)
        return ERR;
    /*La operación básica es o bien el número de veces que se ejecuta la comparación de elementos en la tabla
     * o bien la cantidad de veces que se incrementa la variable j en el bucle*/
     
    /*El bucle encuentra el minimo elemento en la tabla sin contar los elementos previamente ordenados*/
    for (j = ip + 1; j <= iu; j++, *ob = *ob + 1)
        if (tabla[j] < tabla[m])
            m = j;
    return m;
}
 
/***************************************************/
/* Funcion: Maximo Fecha: 5/10/2014               */
/* Autores: Javier Hernandez y Alvaro Clemente     */
/*                                                 */
/* Función que calcula el maximo en la tabla       */
/* (desde i hasta el ultimo) y lo devuelve.        */
/*  Al encontrarse la OB de la función Select Sort */
/* se calcula también                              */
/*                                                 */
/* Entrada:                                        */
/* int ip: Variable de tipo entero que indica      */
/* la posición del primer elemento de los cuales no*/
/* han sido ordenados todavía.                     */
/* int iu: Variable de tipo entero que indica      */
/* la posición del último elemento de la tabla     */
/* int *ob: variable de tipo puntero que apunta a  */
/* la dirección de memoria donde se encuentra el   */
/* valor de la operación básica                    */
/* Salida:                                         */
/* m: El maximo valor de los elementos aún no      */
/* ordenados                        */
/* ERR: En caso de producirse algun error          */
 
/***************************************************/
 
int maximo(int *tabla, int ip, int iu, int * ob) {
    int j=0, m=ip;
    if (tabla == NULL || ob == NULL || ip > iu)
        return ERR;
    /*La operación básica es o bien el número de veces que se ejecuta la comparación de elementos en la tabla
     * o bien la cantidad de veces que se incrementa la variable j en el bucle*/
     
    /*El bucle encuentra el minimo elemento en la tabla sin contar los elementos previamente ordenados*/
    for (j = ip + 1; j <= iu; j++, *ob = *ob + 1)
        if (tabla[j] > tabla[m])
            m = j;
    return m;
}
