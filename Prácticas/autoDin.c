#include <stdio.h>
#include <stdlib.h>
#include "readInput.c"
#include "ndfa.c"

int main(){

	printf("Escribe la cadena: ");
	char * a = readStringInput();

	Vector * result = NULL;
	addState(&result, 1);

	Transitions * transitions = malloc(sizeof(transitions));
	transitions -> accepted = 0;
	transitions -> result = result;
	transitions -> next = NULL;

	State * states = malloc(sizeof(State));
	states -> value = 0;
	states -> table = transitions;
	states -> next = NULL;

	Automat * automat = malloc(sizeof(Automat));
	automat -> start = 0;
	automat -> end = 1;
	automat -> states = states;

	printf("El estado inicial es q%i\n", automat -> start);
	
	Vector * v = NULL;
	addState(&v, automat -> start);
	addState(&v, 1);

	int i = 0;
	while(a[i]){

		//printVector(v);
		Vector * new = NULL;

		while(v){

			State * current = NULL;
			State * auxS = states;
			while(auxS){
				if(auxS -> value == v -> value){
					current = auxS;
				}
				auxS = auxS -> next;
			}


			if(current){
				printf("El estado actual es q%i\n", current -> value);
				int value = a[i] - '0';
				printf("El caracter nu'mero %i es %c.\n", i, a[i]);
				Transitions * aux = current -> table;
				
				while(aux){

					printf("== %i vs %i ==\n", aux -> accepted, value);
					
					if(value == aux -> accepted){
						printf("Valor aceptado\n");
						addStates(&new, aux -> result);
					}
					aux = aux -> next;
				}
	
			}
			
			v = v-> next;

		}
		
		deleteVector(v);
		v = NULL;
		addStates(&v, new);
		
		i++;
	}

	//printVector(new);

	return 0;
}