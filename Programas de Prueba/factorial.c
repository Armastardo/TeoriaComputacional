#include <stdio.h>

int factorialR(int);
int factorialI(int);

int main(){
	int num;
	printf("Valor al que quieres sacar factorial: ");
	scanf("%i", &num);
	//num = 5;
	printf("El factorial recursivo de %i es %i\n", num, factorialR(num));
	printf("El factorial iterativo de %i es %i\n", num, factorialI(num));

	int arreglo [5] = {1,2,3,4,5};
	arreglo[5] = 6;
 
	int i = 0;

	for(i; i<6; i++){
		printf("Arreglo en posición %i: %i\n", i,arreglo[i]);
	}

	return 0;
}

int factorialR(int num){
	int valor;
	if(num == 1){
		valor = num;
	}else{
		valor = num*factorialR(num-1);
	}
	return valor;
}


int factorialI(int num){
	int valor = num;
	while(num>0){
		if(num>1)
			valor=valor*(num-1);
		num--;
	}
	return valor;
}