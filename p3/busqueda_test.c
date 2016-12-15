
#include <stdio.h>
#include "busqueda.h"


int main(){
	int tabla[10], pos, i, ret;
	generador_claves_uniforme(tabla, 10, 10);
	
	printf("Generamos esta tabla con generador_claves_uniforme:\n");
	for(i = 0; i < 10; i++)
		printf("%d ", tabla[i]);
	printf("\n\n");
	
	ret = bbin(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con bbin\n", pos);
	ret = bbin(tabla, 0, 9, 1, &pos);
	printf("Clave 1 encontrada en la posición %d con bbin\n", pos);
	ret = bbin(tabla, 0, 9, 20, &pos);
	printf("Clave 20 encontrada en la posición %d con bbin\n\n", pos);
	
	ret = blin(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con blin\n", pos);
	ret = blin(tabla, 0, 9, 1, &pos);
	printf("Clave 1 encontrada en la posición %d con blin\n", pos);
	ret = blin(tabla, 0, 9, 20, &pos);
	printf("Clave 20 encontrada en la posición %d con blin\n\n", pos);
	
	
	ret = blin_auto(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con bbin\n", pos);
	ret = blin_auto(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con bbin\n", pos);
	ret = blin_auto(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con bbin\n", pos);
	ret = blin_auto(tabla, 0, 9, 5, &pos);
	printf("Clave 5 encontrada en la posición %d con bbin\n", pos);
	ret = blin_auto(tabla, 0, 9, 20, &pos);
	printf("Clave 20 encontrada en la posición %d con bbin\n\n", pos);
	
	printf("Tabla después de llamar a blin_auto:\n");
	for(i = 0; i < 10; i++)
		printf("%d ", tabla[i]);
	printf("\n\n");
	
	
	return 0;


}
