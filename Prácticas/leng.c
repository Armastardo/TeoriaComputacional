#include <stdio.h>
#include <stdlib.h>
#include "readInput.c"

typedef struct nodo{
	char * string;
	struct nodo * siguiente;
} Nodo;

Nodo * createList();
void printList(Nodo *, char);

void listAppend(Nodo *, Nodo *);
Nodo * concatLists(Nodo *, Nodo *);
Nodo * listPow(Nodo *, int pow);
Nodo * reverseListElements(Nodo *);
Nodo * reverseList(Nodo *);
Nodo * listUnion(Nodo *, Nodo *);
int contains(Nodo *, char *);

Nodo * createList(){
	Nodo * retorno = NULL;

	printf("Cantidad de elementos en el lenguaje: ");
	int listLen = readIntegerInput();
	int i = 0;	

	while(i < listLen){
		Nodo * nuevo;

		nuevo = malloc(sizeof(struct nodo));
		printf("Escribe la palabra %d de %d: ",i+1, listLen);
		char * cad = readStringInput();

		nuevo -> string = cad;
		nuevo -> siguiente = NULL;

		if(!retorno){
			retorno = nuevo;
		}else{
			listAppend(retorno, nuevo);
		}
		i++;
	}
	return retorno;
}

Nodo * concatLists(Nodo * lenguajeU, Nodo * lenguajeV){
	Nodo * listConcat = NULL;

	Nodo * auxU = lenguajeU;

	while(auxU){
		Nodo * auxV = lenguajeV;
		while(auxV){
			Nodo * nuevo = malloc(sizeof(Nodo));
			nuevo -> string = concat(auxU -> string, auxV -> string);
			if(!listConcat){
				listConcat = nuevo;
			}else{
				listAppend(listConcat, nuevo);
			}
			auxV = auxV -> siguiente;
		}
		auxU = auxU -> siguiente;
	}
	return listConcat;
}

Nodo * listUnion(Nodo * lenguajeU, Nodo *lenguajeV){
	Nodo * listasUnidas = NULL;

	Nodo * aux = lenguajeU;
	while(aux){

		Nodo * nuevo = malloc(sizeof(Nodo));
		nuevo -> string = aux -> string;
		nuevo -> siguiente = NULL;

		if(!listasUnidas){
			listasUnidas = nuevo;
		}else{
			listAppend(listasUnidas, nuevo);	
		}
		aux = aux -> siguiente;
	}

	aux = lenguajeV;

	while(aux){

		Nodo * nuevo = malloc(sizeof(Nodo));
		nuevo -> string = aux -> string;
		nuevo -> siguiente = NULL;

		if(!listasUnidas){
			listasUnidas = nuevo;
		}else{
			if(!contains(listasUnidas, nuevo->string)){
				listAppend(listasUnidas, nuevo);	
			}
		}
		aux = aux -> siguiente;
	}
	return listasUnidas;
}

Nodo * reverseListElements(Nodo * lenguaje){
	Nodo * invertida = NULL;
	Nodo * aux = lenguaje;

	while(aux){
		
		Nodo * nuevo = malloc(sizeof(Nodo));
		
		nuevo -> string = invert(aux -> string);
		nuevo -> siguiente = NULL;
		
		if(!invertida){
			invertida = nuevo;
		}else{
			listAppend(invertida, nuevo);
		}
		aux = aux -> siguiente;
	}

	return invertida;
}

Nodo * reverseList(Nodo * lenguaje){
	Nodo * listaInvertida = NULL;
	Nodo * aux = lenguaje;

	while(aux){
		if(!listaInvertida){
			listaInvertida = malloc(sizeof(Nodo));

			listaInvertida -> string = aux -> string;
			listaInvertida -> siguiente = NULL;
		}else{
			Nodo * nuevo = malloc(sizeof(Nodo));
			nuevo -> siguiente = listaInvertida;
			nuevo -> string = aux -> string;

			listaInvertida = nuevo;
		}
		aux = aux -> siguiente;

	}
	return listaInvertida;
}

Nodo * listPow(Nodo * lenguaje, int pow){

	Nodo * lenguajePotenciado = NULL;

	if(pow > 1){
		return concatLists(lenguaje, listPow(lenguaje, pow-1));
	}else{
		return lenguaje;
	}
}

void printList(Nodo * lista, char nombre){
	Nodo * aux = lista;

	printf("Lista de elementos en %c = {", nombre);
	while(aux){
		if(aux -> siguiente){
			printf("%s, ", aux -> string);
		}else{
			printf("%s", aux -> string);
		}
		aux = aux -> siguiente;
	}
	printf("}\n");
}

void listAppend(Nodo * lista, Nodo * elemento){
	Nodo * aux = lista;
	while(aux -> siguiente){
		aux = aux -> siguiente;
	}
	aux -> siguiente = elemento;
}

int contains(Nodo * lista, char * elemento){
	Nodo * aux = lista;
	while(aux){
		if(compareString(aux -> string, elemento)){
			return 1;
		}
		aux = aux -> siguiente;
	}
	return 0;

}