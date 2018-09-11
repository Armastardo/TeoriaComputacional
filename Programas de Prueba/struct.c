#include <stdio.h>
#include <stdlib.h>

typedef struct ejemplo{
	int entero;
	char carac;
	char * string;
}Ejemplo;

/* Buscar referencias de:
operador ->
operador .
*/

int main(){
	Ejemplo * nodo;

	nodo = (Ejemplo*)malloc(sizeof(Ejemplo));

	printf("Escribe un número: ");
	scanf("%d", &nodo -> entero);
	getchar();

	printf("Escribe un caracter: ");
	scanf("%c", &nodo -> carac);
	getchar();

	nodo -> string = malloc(100);
	printf("Escribe una cadena: ");
	scanf("%[^\n]", nodo -> string);
	getchar();


	printf("\nEl entero es: %d\n", nodo -> entero);
	printf("El caracter es: %c\n", nodo -> carac);
	printf("La cadena es: %s\n", nodo -> string);	
	free(nodo -> string);
	free(nodo);
	printf("========= Memoria liberada =========\n");
	printf("El entero es: %d\n", nodo -> entero);
	printf("El caracter es: %c\n", nodo -> carac);
	printf("La cadena es: %s\n", nodo -> string);	
	
	return 0;
}