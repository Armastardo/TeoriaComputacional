#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	int value;
	struct vector * next;
}Vector;

void printVector(Vector * states){
	Vector * aux = states;
	int i = 0;

	while(aux){
		printf("Valor en la posicio'n %i: [%i]\n", i, aux -> value);
		i++;
		aux = aux -> next;
	}
}

void addState(Vector ** states, int state){
	Vector * new = malloc(sizeof(Vector));
	new -> value = state;
	new -> next = NULL;

	if(*states == NULL){
		*states = new;
	}else{
		Vector * aux = *states;
		while(aux -> next){
			aux = aux -> next;
		}
		aux -> next = new;	
	}
}

void addStates(Vector ** states, Vector * add){
	while(add){
		addState(states, add -> value);
		add = add -> next;
	}
}

void deleteState(Vector ** states, int position){
	if(position == 0){
		//printf("La posicio'n es 0\n");
		*states = (*states) -> next;
		//printf("El nuevo valor inicial es [%i]\n", (*states) -> value);
	}else{
		int i = 0;
		Vector * aux = *states;
		while(i < position-1){
			aux = aux -> next;
			i++;
		}
		aux -> next = aux -> next -> next;
	}
}

void deleteStates(Vector ** states, Vector * delete){
	int i = 0;
	while(delete){
		deleteState(states, (delete -> value)-i);
		delete = delete -> next;
		i++;
	}
}

void deleteVector(Vector * states){
	if(states){
		deleteVector(states -> next);
	}
	free(states);
}