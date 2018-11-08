#include <stdio.h>
#include <stdlib.h>
#include "vector.c"

int main(){
	Vector * states= NULL;

	addState(&states, 1);
	addState(&states, 3);
	addState(&states, 2);

	printVector(states);

	printf("\n==== Borramos la posicio'n 0 ====\n");
	
	deleteState(&states, 0);

	printVector(states);
	printf("El tamaño del vector es: %i\n", getSize(states));

	return 0;
}