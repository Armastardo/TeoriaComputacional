#include <stdio.h>
#include <stdlib.h>
#include "readInput.c"
#include "ndfa.c"

int main(){

	printf("Escribe la cadena: ");
	char * a = readStringInput();

	Vector * current = NULL;

	Vector * states = NULL;
	addState(&states, 1);
	addState(&states, 3);

	States * table = malloc(sizeof(States));
	table -> input = 1;
	table -> result = states;
	table -> next = NULL;

	//printf("El valor de entrada es %i\n", table -> input);

	int i = 0;
	while(a[i]){
		int value = a[i] - '0';
		if(value == table -> input){
			printf("Match! - ");
			addStates(&current, table -> result);
		}

		printf("El caracter nu'mero %i es %c.\n", i, a[i]);
		i++;
	}

	printVector(current);

	return 0;
}