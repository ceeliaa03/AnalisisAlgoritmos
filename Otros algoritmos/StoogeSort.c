
int StoogeSort(int *tabla,int P, int U){
    int M,a,b,c;
    
    if(!tabla || P>U)
	return ERR;

    /* Consideramos esta comparacion como CDC */
    if(tabla[P] > tabla[U])
        swap(&(tabla[P]),&(tabla[U]));

    if((P+1) >= U)
        return 1;

    M = (U-P+1)/3;

    a = StoogeSort(tabla,P,U-M);
    if(a == ERR) return ERR;

    b = StoogeSort(tabla,P+M,U);
    if(b == ERR) return ERR;
    c = StoogeSort(tabla,P,U-M);
    if(c == ERR) return ERR;

    

    return a + b + c + 1;
}

