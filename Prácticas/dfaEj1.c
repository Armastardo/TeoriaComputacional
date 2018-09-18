#include <stdio.h>
#include <stdlib.h>
#include "leng.c"

int main(){

	char * states = {"0123"};

	int current = 0;
	int final = 0;

	Nodo * input = createList();
	Nodo * aux = input;

	while(aux){

	int mod = atoi(aux -> string);
	printf("\nEl valor actual es %i\n", mod);
	printf("El estado actual paso' de ser q%i", current);

		switch(states[current]){
			case '0':
				if(mod == 1){
					current = 1;
				}else if(mod == 0){
					current = 2;
				}
			break;

			case '1':
				if(mod == 1){
					current = 0;
				}else if(mod == 0){
					current = 3;
				}
			break;
			
			case '2':
				if(mod == 1){
					current = 3;
				}else if(mod == 0){
					current = 0;
				}
			break;
			
			case '3':
				if(mod == 1){
					current = 2;
				}else if(mod == 0){
					current = 1;
				}
			break;
		}
		printf(" a ser q%i.\n", current);
		aux = aux -> siguiente;
	}

	printf("\nEstado final: Q%i - ", current);
	printList(input, 'I');
	if(current != final){
		printf("No es una cadena va'lida");
	}else{
		printf("Es una cadena va'lida");
	}



	return 0;
}