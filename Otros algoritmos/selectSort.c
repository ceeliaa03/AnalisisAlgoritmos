/***************************************************/
/* Funcion: SelectSort Fecha: 17/09/2014        */
/* Autores: Javier Hernandez y Alvaro Clemente     */
/*                                                 */
/* Función que ordena los elementos de una tabla   */
/* buscando el minimo elemento de la tabla y lo    */
/* intercambia con el elemento de la ultima        */
/* posición y a continuación busca el anterior     */
/* mínimo de la lista y se intercambia con el      */
/* elemento en la penultima posición y así         */
/* sucesivamente                                   */
/* Entrada:                                        */
/* int * tabla: variable de tipo puntero que apunta*/
/*  a la tabla sin ordernar                        */
/* int ip: variable de tipo entero que indica      */
/* la posición del primer elemento de la tabla     */
/* int iu: variable de tipo entero que indica      */
/* la posición del último elemento de la tabla     */
/* Salida:                                         */
/* número de veces que se ejecuta la OB o error en */
/* caso de error.                                  */
 
/***************************************************/
 
 
int SelectSort(int* tabla, int ip, int iu) {
    int i=ip, min=0, ob = 0;
    if (tabla == NULL || ip > iu || ip < 0)
        return ERR;
     
    /*Recorre todos los elementos de la tabla llamando a la funcion minimo para ordenarlos*/
    while (i < iu) {
        min = minimo(tabla, i, iu, &ob);
        if (swap(&tabla[i], &tabla[min]) == ERR)
            return ERR;
        i++;
    }
    return ob;
}
/***************************************************/
/* Funcion: SelectSortInv Fecha: 17/09/2014           */
/* Autores: Javier Hernandez y Alvaro Clemente     */
/*                                                 */
/* Función que ordena los elementos de una tabla   */
/* buscando el maximo elemento de la tabla y lo    */
/* intercambia con el elemento de la primera       */
/* posición y a continuación busca el siguiente    */
/* maximo de la lista y se intercambia con el      */
/* elemento en la segunda posición y así           */
/* sucesivamente                                   */
/* Entrada:                        */
/* int * tabla: variable de tipo puntero que apunta*/
/*  a la tabla sin ordernar                        */
/* int ip: variable de tipo entero que indica      */
/* la posición del primer elemento de la tabla     */
/* int iu: variable de tipo entero que indica      */
/* la posición del último elemento de la tabla     */
/* Salida:                                         */
/* número de veces que se ejecuta la OB o error en */
/* caso de error.                                  */
 
/***************************************************/
 
int SelectSortInv(int* tabla, int ip, int iu) {
    int i=ip, max=0, ob = 0;
        if (tabla == NULL || ip > iu || ip < 0)
        return ERR;
     
    /*Recorre todos los elementos de la tabla llamando a la funcion maximo para ordenarlos*/
    while (i < iu) {
        max = maximo(tabla, i, iu, &ob);
        if (swap(&tabla[max],&tabla[i]) == ERR)
            return ERR;
        i++;
        }
    return ob;
}
