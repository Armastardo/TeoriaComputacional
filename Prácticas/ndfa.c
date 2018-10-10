#include <stdlib.h>
#include "vector.c"

//Transiciones de la tabla de estados
typedef struct transitions{
	int accepted;
	Vector * result;
	struct transitions * next;
}Transitions;

//Estructura de la tabla de estados
typedef struct state{
	int value;
	Transitions * table;
	struct state * next; 
}State;

//Estructura del autómata
typedef struct automat{
	int start;
	int end;
	State * states;
} Automat;

//Si leo X, entonces se vuelve Q y se crea S

/*Electabuzz
Magmar
Likitung
Laptras
Snorlas*/