#include <stdio.h>
#include <stdlib.h>
#include "leng.c"

void menu();

int main(){

	printf(" == Bienvenido == \n");
	printf("Este programa tiene diversas herramientas para trabajar con lenguajes.\n");

	printf("Para empezar, te pido que decidas que llenes dos lenguajes.\n");


	printf("\n == Llenado de lenguajes ==\n");
	Nodo * lenguajeU = createList();
	//Nodo * lenguajeV = createList();

	while(1){
		printf("Escribe la potencia: ");
		int pow = readIntegerInput();

		printf("== Resultado de la potencia ==\n");
		Nodo * potenciaLenguaje = NULL;

		if(pow < 0){
			potenciaLenguaje = listPow(lenguajeU, pow*-1);
			printList(reverseList(potenciaLenguaje), 'P');
		}else{
			potenciaLenguaje = listPow(lenguajeU, pow);
			printList((potenciaLenguaje), 'P');
		}	

		free(potenciaLenguaje)
	}
	

	/*int opc = 0;
	while(opc != 8){
		printf("\n == Elige una opcio'n del menu ==");
	}*/

	

	//printList(lenguajeU, 'U');
	//printList(lenguajeV, 'V');

	/*printf("\n== Unio'n de las listas ==\n");
	printList(listUnion(lenguajeU ,lenguajeV), 'J');

	printf("\n== Resultado de la inversio'n U ==\n");
	Nodo * inverted = reverseList(lenguajeU);
	printList(reverseListElements(inverted), 'I');*/

	/*printf("\n== Concatenacio'n UV == \n");
	printList(concatLists(lenguajeU, lenguajeV), 'C');
	
	printf("\n== Concatenacio'n VU == \n");
	printList(concatLists(lenguajeV, lenguajeU), 'C');

	printf("\n== Resultado de la inversio'n U ==\n");
	Nodo * inverted = reverseListyElementos(lenguajeU);
	printList(inverted, 'I');


	printf("\n== Resultado de la inversio'n V ==\n");
	inverted = reverseListyElementos(lenguajeV);
	printList(inverted, 'I');*/

	/*while(1){
		printf("Escribe la potencia: ");
		int pow = readIntegerInput();

		printf("== Resultado de la potencia ==\n");

		if(pow < 0){
			Nodo * potenciaLenguaje = listPow(lenguajeU, pow*-1);
			printList(reverseList(potenciaLenguaje), 'P');
		}else{
			Nodo * potenciaLenguaje = listPow(lenguajeU, pow);
			printList((potenciaLenguaje), 'P');
		}	
	}
*/
	return 0;

}
