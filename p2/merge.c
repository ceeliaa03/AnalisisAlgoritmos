#include <stdio.h>
#include "ordenacion.h"
int main(){
	int i;
	int arr[7]={4,7,1,3, 5, 6};

	for(i = 0; i<6; i++) printf("%d ", arr[i]);
	printf("\n");
	
	printf("\n");
	quicksort(arr, 0, 5, 2);
	
	for(i = 0; i<6; i++) printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
