#include <stdlib.h>
#include "vector.c"

typedef struct states{
	int input;
	Vector * result;
	struct states * next; 
}Transitions;

//Si leo X, entonces se vuelve Q y se crea S