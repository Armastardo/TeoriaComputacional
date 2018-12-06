#include <stdio.h>
#include <stdlib.h>

typedef struct orderedList{
	int value;
	struct orderedList * next;
}OrderedList;

int alreadyContains(OrderedList *, int);
int getListLenght(OrderedList *);

void addToList(OrderedList ** list, int add){

	if(!(alreadyContains(*list, add))){
		OrderedList * new = malloc(sizeof(OrderedList));
		new -> value = add;
		new -> next = NULL;

		if(!*list){
			*list = new;
		}else{
			OrderedList * aux = *list; 
			if(new -> value < aux -> value){
				new -> next = aux;
				*list = new;
			}else{
				int inserted = 0;
				while(aux -> next){
					if(new -> value > (aux -> next) -> value){
						aux = aux -> next;
					}else{
						new -> next = aux -> next;
						aux -> next = new;
						inserted = 1;
						break;
					}
				}
				if(!inserted){
					aux -> next = new;
				}
			}
		}
	}
}

int alreadyContains(OrderedList * list, int value){
	int contains = 0;
	while(list){
		if(list -> value == value){
			contains = 1;
		}
		list = list -> next;
	}
	return contains;
}

int compareLists(OrderedList * one, OrderedList * two){
	int equal = 1;

	if(getListLenght(one) == getListLenght(two)){
		while(one){
			if(one -> value != two -> value){
				equal = 0;
			}
			one = one -> next;
			two = two -> next;
		}
	}else{
		equal = 0;
	}
	return equal;
}

int getListLenght(OrderedList * list){
	int i = 0;
	while(list){
		i++;
		list = list -> next;
	}
	return i;
}

void printOrderedList(OrderedList * print){
	printf("Elementos de la lista: ");
	while(print){
		printf("%i", print -> value);
		if(print -> next){
			printf(", ");
		}else{
			printf("\n");
		}
		print = print -> next;
	}
}
