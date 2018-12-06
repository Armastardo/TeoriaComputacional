#include <stdio.h>
#include <stdlib.h>

typedef struct charList{
	char value;
	struct charList * next;
}CharList;

void addChar(CharList ** list, char add){
 	CharList * new = malloc(sizeof(CharList));
 	new -> value = add;
	new -> next = NULL;

	if(!*list){
		*list = new;
	}else{
		CharList * auxL = *list;
		while(auxL -> next){
			auxL = auxL -> next;
		}
		auxL -> next = new;
	}
}

void printCharList(CharList * list){
	printf("Lista de caracteres: ");
	while(list){
		printf("[%c]", list -> value);
		if(list -> next){
			printf(", ");
		}else{
			printf("\n");
		}
		list = list -> next;
	}
}