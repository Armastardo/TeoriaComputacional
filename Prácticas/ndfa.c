#include <stdio.h>
#include <stdlib.h>
#include "leng.c"

int main(){

	char * states = {"012"};

	int current = 0;
	int final = 2;

	int ceroCounter = 0;

	Nodo * input = createList();
	Nodo * aux = input;

	while(aux){

	char * mod = aux -> string;
	printf("\nEl valor actual es %s\n", mod);
	printf("El estado actual paso' de ser q%i", current);

		switch(states[current]){
			case '0':
				if(compareString(mod, "0")){
					if(ceroCounter == 1){
						current = 1;
					}else if(ceroCounter == 0){
						ceroCounter = 1;		
					}
				}else if(compareString(mod, "1")){
					ceroCounter = 0;
				}
			break;

			case '1':
				if(compareString(mod, "1")){
					current = 2;
				}
			break;
		}
		printf(" a ser q%i.\n", current);
		aux = aux -> siguiente;
	}

	printf("\nEstado final: Q%i - ", current);
	printList(input, 'I');
	if(current != final){
		printf("No es una cadena va'lida\n");
	}else{
		printf("Es una cadena va'lida\n");
	}



	return 0;
}