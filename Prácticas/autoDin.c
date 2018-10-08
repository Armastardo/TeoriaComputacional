#include <stdio.h>
#include <stdlib.h>
#include "readInput.c"
#include "ndfa.c"

int main(){

	printf("Escribe la cadena: ");
	char * a = readStringInput();


	Vector * states = NULL;
	addState(&states, 1);
	addState(&states, 3);

	Transitions * table = malloc(sizeof(Transitions));
	table -> input = 1;
	table -> result = states;
	table -> next = NULL;

	//printf("El valor de entrada es %i\n", table -> input);


	int i = 0;
	while(a[i]){
		int value = a[i] - '0';
		if(value == table -> input){
			printf("Match! - ");
		}

		printf("El caracter n\243mero %i es %c.\n", i, a[i]);
		i++;
	}



	return 0;
}