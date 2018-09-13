#include <stdio.h>
#include <stdlib.h>
#include "readInput.c"

typedef struct nodo{
	char * string;
	struct nodo * siguiente;
} Nodo;

void listAppend(Nodo *, Nodo *);

Nodo * llenarLista();
void imprimirLista(Nodo *, char);
Nodo * concatenar(Nodo *, Nodo *);
Nodo * potencia(Nodo *, int pow);
Nodo * invertirElementos(Nodo *);
Nodo * invertirLista(Nodo *);
Nodo * invertirListayElementos(Nodo *);
Nodo * unirListas(Nodo *, Nodo *);

int main(){
	Nodo * lenguajeU = llenarLista();
	Nodo * lenguajeV = llenarLista();

	//imprimirLista(lenguajeU, 'U');
	//imprimirLista(lenguajeV, 'V');

	imprimirLista(unirListas(lenguajeU ,lenguajeV), 'J');

	/*Invertir lista

	printf("== Resultado de la inversio'n ==\n");
	Nodo * inverted = invertirListayElementos(lenguajeU);
	imprimirLista(inverted, 'I');*/

	/*Potencia

	printf("Escribe la potencia: ");
	int pow = readIntegerInput();

	printf("== Resultado de la potencia ==\n");
	Nodo * potenciaLenguaje = potencia(lenguajeU, pow);
	imprimirLista(potenciaLenguaje, 'P');
	free(potenciaLenguaje);*/

	return 0;

}

Nodo * llenarLista(){
	Nodo * retorno = NULL;

	printf("Taman~o de la lista: ");
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

Nodo * concatenar(Nodo * lenguajeU, Nodo * lenguajeV){
	/* Ahora mismo:
	Concatenación de listas. Dada la lista U y lista V que contienen un
	lenguaje cada una, imprimir la concatenación de sus elementos.
	*/
	
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

Nodo * unirListas(Nodo * lenguajeU, Nodo *lenguajeV){
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
			listAppend(listasUnidas, nuevo);
		}
		aux = aux -> siguiente;
	}


	return listasUnidas;
}

Nodo * invertirElementos(Nodo * lenguaje){
	Nodo * aux = lenguaje;

	Nodo * invertida = NULL;

	while(aux){
		Nodo * nuevo = malloc(sizeof(Nodo));
		nuevo -> string = invert(aux -> string);
		if(!invertida){
				invertida = nuevo;
			}else{
				listAppend(invertida, nuevo);
			}
		aux = aux -> siguiente;
	}
	return invertida;
}

Nodo * invertirLista(Nodo * lenguaje){
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

Nodo * invertirListayElementos(Nodo * lenguaje){
	Nodo * listaInvertida = NULL;
	Nodo * aux = lenguaje;

	while(aux){
		if(!listaInvertida){
			listaInvertida = malloc(sizeof(Nodo));

			listaInvertida -> string = invert(aux -> string);
			listaInvertida -> siguiente = NULL;
		}else{
			Nodo * nuevo = malloc(sizeof(Nodo));
			nuevo -> siguiente = listaInvertida;
			nuevo -> string = invert(aux -> string);

			listaInvertida = nuevo;
		}
		aux = aux -> siguiente;

	}
	return listaInvertida;
}

Nodo * potencia(Nodo * lenguaje, int pow){

	Nodo * lenguajePotenciado = NULL;

	if(pow > 1){
		return concatenar(lenguaje, potencia(lenguaje, pow-1));
	}else{
		return lenguaje;
	}
}

void imprimirLista(Nodo * lista, char nombre){
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