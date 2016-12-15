#include "busqueda.h"

void main(){

PDICC pd;
int in[5], i;
for(i=0; i<5; i++)
	in[i]=5-i;

pd= ini_diccionario (5, ORDENADO);
insercion_masiva_diccionario (pd,in, 5);
print_tabla(pd);
libera_diccionario(pd);


}
