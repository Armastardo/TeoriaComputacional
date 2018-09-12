#include <stdio.h>
#include <stdlib.h>
#include "string.c"
#include "readInput.c"

typedef struct nodo{
	char * string;
	struct nodo * siguiente;
} Nodo;

void listAppend(Nodo *, Nodo *);

int main(){

	Nodo * lenguaje;

	printf("Taman~o de la lista: ");
	int listLen = readIntegerInput();

	int i = 0;	
	while(i < listLen){
		Nodo * nuevo;

		nuevo = malloc(sizeof(struct nodo));
		printf("Escribe la palabra %d: ",i+1);
		char * cad = readStringInput();

		nuevo -> string = cad;

		if(i == 0){
			printf("== Debug == Lista vacía, agregando la primera palabra.\n");
			lenguaje = nuevo;
			lenguaje -> siguiente = NULL;
		}else{
			listAppend(lenguaje, nuevo);
		}
		i++;
	}

	Nodo * aux = lenguaje;

	printf("Lista contiene: %s\n", aux -> string);
	while(aux -> siguiente){
		aux = aux -> siguiente;
		printf("Lista contiene: %s\n", aux -> string);
	}

	return 0;

}

void listAppend(Nodo * lista, Nodo * elemento){
	Nodo * aux = lista;
	while(aux -> siguiente != NULL){
		aux = aux -> siguiente;
	}
	aux -> siguiente = elemento;
}