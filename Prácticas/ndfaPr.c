#include <stdio.h>
#include <stdlib.h>
#include "leng.c"
#include "vector.c"


int main(){
	
	/*Se especifica el estado inicial y el estado al que debe llegar*/
	int start = 0;
	int final = 2;

	/*Declaraci\242n de los estados*/
	Vector * states = malloc(sizeof(Vector));
	states -> value = start;
	states -> next = NULL;

	/*Lectura de la cadena*/


	//Nodo * input = createList();
	char * auxInput = readStringInput();


	printf("\n == Recorrido == \n");

	printf("\nEstado inicial: [q%i]\n", start);

	int espacio = 3;
	int nivel = 0;

	int j = 0;

	/*Recorremos la entrada*/

	while(auxInput[j]){

		printf("\n===== Evaluaci\242n n\243mero %i ======\n", nivel+1);

		char mod = auxInput[j];

		//printf("\nEl valor actual es %s\n", mod);
		Vector * auxState = states;
		Vector * delete = NULL;
		Vector * add = NULL;

		int i = 0;
		while(auxState){

			switch(auxState -> value){
				case 0:
					if(mod == '0'){
						printf("== El estado n\243mero %i es q0 == \n", i);
						auxState -> value = 1;
						addState(&add, 0);
						printf("La entrada fue 0\n");
						printf("=== El estado n\243mero %i pas\242 de q0 a q1\n", i);
						printf("=== Se creo el estado q0\n");
					}else if(mod == '1'){
						printf("La entrada fue 1\n");
						printf("=== El estado n\243mero %i pas\242 de q0 a q0\n", i);
						//do nothig
					}else{
						addState(&delete, i);
						printf("La entrada no fue reconocida\n");
						printf("=== El estado n\243mero %i (q0) fue eliminado\n", i);
					}
				break;
				case 1:
					printf("=== El estado n\243mero %i es q1 == \n", i);
					if(mod == '1'){
						auxState -> value = 2;
						printf("La entrada fue 1\n");
						printf("=== El estado n\243mero %i pas\242 de q1 a q2\n", i);
					}else{
						addState(&delete, i);
						printf("La entrada no fue reconocida\n");
						printf("=== El estado n\243mero  %i (q1) fue eliminado\n", i);
					}
				break;
				case 2:
					if(mod == '2'){
						printf("La entrada fue 2\n");
						printf("=== El estado n\243mero %i pas\242 de q2 a q2\n", i);
					}else{
						addState(&delete, i);
						printf("La entrada no fue reconocida\n");	
						printf("=== El estado n\243mero %i (q2) fue eliminado\n", i);
					}
				break;
			}
			i++;
			auxState = auxState -> next;
		}

		printf("\n");
		deleteStates(&states, delete);
		while(add){
			addState(&states, add -> value);
			add = add -> next;
		}

		j++;
		nivel++;
	}

	/*Verificamos si es una cadena válida e imprimimos el resultado*/
	//printList(input, 'I');
	
	int valid = 0;

	if(states == NULL){
		printf("\nNo hay ning\243n estado\n");
	}else{
		while(states){
			int i = 0;
			int current = states -> value;
			printf("\nEstado final n\243mero [%i]: Q%i", i+1, current);
			if(current == final){
				valid = 1;
			}
			states = states -> next;
		}
	}
	if(valid){

			printf("\nEs una cadena válida\n");
		}else{
			printf("\nNo es una cadena válida\n");
		}

	return 0;
}