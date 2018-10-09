#include <stdlib.h>
#include "vector.c"

typedef struct transitions{
	int accepted;
	Vector * result;
	struct transitions * next;
}Transitions;

typedef struct states{
	int input;
	Vector * result;
	struct states * next; 
}States;

typedef struct automat{
	int start;
	int end;
	States * states;
} Automat;

//Si leo X, entonces se vuelve Q y se crea S