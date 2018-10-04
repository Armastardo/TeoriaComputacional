#include <stdio.h>
#include <stdlib.h>
#include "leng.c"
#include "vector.c"


int main(){
	
	/*Generación de estados, así como al que debe llegar*/
	char * qStates = {"012"};
	int start = 0;
	int final = 2;

	/*Declaración de los estados*/
	Vector * states = malloc(sizeof(Vector));
	states -> value = start;
	states -> next = NULL;

	/*Lectura de la cadena*/
	Nodo * input = createList();
	Nodo * auxInput = input;

	/*Recorremos la entrada*/
	while(auxInput){

		char * mod = auxInput -> string;

		//printf("\nEl valor actual es %s\n", mod);
		Vector * auxState = states;
		Vector * delete = NULL;
		Vector * add = NULL;

		int i = 0;
		while(auxState){

			switch(auxState -> value){
				case 0:
					if(compareString(mod, "0")){
						auxState -> value = 1;
						addState(&add, 0);
					}else if(compareString(mod, "1")){
						//do nothig
					}else{
						addState(&delete, i);
					}
				break;
				case 1:
					if(compareString(mod, "1")){
						auxState -> value = 2;
					}else{
						addState(&delete, i);
					}
				break;
				case 2:
					addState(&delete, i);
				break;
			}
			i++;
			auxState = auxState -> next;
		}
		deleteStates(&states, delete);
		while(add){
			addState(&states, add -> value);
			add = add -> next;
		}
		auxInput = auxInput -> siguiente;
	}

	/*Verificamos si es una cadena válida e imprimimos el resultado*/
	printList(input, 'I');
	
	int valid = 0;

	while(states){
		int i = 0;
		int current = states -> value;
		printf("\nEstado final nu'mero [%i]: Q%i", i+1, current);
		if(current == final){
			valid = 1;
			break;
		}
		states = states -> next;
	}
	if(valid){
			printf("\nEs una cadena va'lida\n");
		}else{
			printf("\nNo es una cadena va'lida\n");
		}

	return 0;
}