#include <stdlib.h>
#include <stdio.h>
#include "path.c"
#include "ndfaFile.c"
#include "readInput.c"

Vector * splitInts(char *);
Automat * createAutomat(char *);
void showInfo(Automat *);
void evaluateInput(char *, Automat *);
Vector * validatePaths(Path *, Vector *);

int main(){

	printf("Escribe el nombre del archivo (con extensio'n): ");
	char * name = readStringInput();
	printf("\n");
	Automat * automat= createAutomat(name);
	showInfo(automat);
	printf("\nEscribe la cadena: ");
	char * a = readStringInput();
	printf("\n");
	evaluateInput(a, automat);
}

Vector * splitInts(char * buff){

	char * auxS = malloc(250);
	Vector * states = NULL;

	int i = 0;
	int j = 0;

	while(buff[i]){
		if(buff[i] == ','){
			auxS[j+1] = '\0';
			if(sizeString(auxS) > 0){
				addState(&states, atoi(auxS));	
			}
			free(auxS);
			char * auxS = malloc(250);
			j = 0;

		}else{	
			auxS[j] = buff[i];
			j++;
		}
		i++;
	}
	
	auxS[j+1] = '\0';

	if(sizeString(auxS) > 0){
		addState(&states, atoi(auxS));
		free(auxS);
		char * auxS = malloc(250);
	}

	return states;
}

Automat * createAutomat(char * name){
	FILE * fp;
	fp = fopen(name, "r");
	char buff[250];

	//Lo primero que se lee del archivo son los estados
	fscanf(fp, "%s", buff);
	Vector * temp = splitInts(buff);

	//Agregamos los estados a una estructura
	
	State * states = NULL;
	State * auxS = states;

	while(temp){
		State * auxS = states;

		State * new = malloc(sizeof(State));
		new -> value = temp -> value;
		new -> table = NULL;
		new -> next = NULL;
		
		if(!states){
			states = new;
		}else{
			
			while(auxS -> next){
				auxS = auxS -> next;
			}
			
			auxS -> next = new;
			//auxS = states;
		}

		temp = temp -> next;
	}

	//Hacemos un segundo fscanf para hacer un skip al
	//alfabeto (porque no estoy usando esa información...)
	fscanf(fp, "%s", buff);

	//El tercer fscanf me dice la pocisión inicial
	fscanf(fp, "%s", buff);
	int start = atoi(buff);

	//El cuarto me dice las pocisiones finales
	fscanf(fp, "%s", buff);
	Vector * final = splitInts(buff);

	Automat * automat = malloc(sizeof(Automat));
	automat -> start = start;
	automat -> states = states;
	automat -> end = final;

	//Ahora sí llenamos esa tabla de transiciones
	while(fscanf(fp, "%s", buff)!= EOF){
		int i = 0;
		int j = 0;

		char * auxB = malloc(sizeof(250));

		int stateNumber;
		char accepted;
		int newState;


		while(buff[i] != ','){
			auxB[j] = buff[i];
			j++;
			i++;
		}
		
		auxB[j+1] = '\0';
		stateNumber = atoi(auxB);

		i++;
		accepted = buff[i];
		i+=2;

		j = 0;
		free(auxB);
		auxB = malloc(sizeof(250));

		while(buff[i]){
			auxB[j] = buff[i];
			j++;
			i++;
		}
		auxB[j] = '\0';		
		newState = atoi(auxB);

		auxS = automat -> states;
		while(auxS -> value != stateNumber){
			auxS = auxS -> next;
		}

		if(auxS -> table){
			Transitions * auxT = auxS -> table;

			while(auxT){
				if(auxT -> accepted == accepted) break;
				auxT = auxT -> next;
			}

			if(auxT){
				addState(&(auxT -> result), newState);

			}else{
				auxT = auxS -> table;

				Vector * result = NULL;
				addState(&result, newState);

				Transitions * new = malloc(sizeof(Transitions));
				new -> accepted = accepted;
				new -> result = result;
				new -> next = NULL;

				while(auxT -> next){
					auxT = auxT -> next;
				}
				auxT -> next = new;
			}

		}else{
			Vector * result = NULL;
			addState(&result, newState);

			Transitions * new = malloc(sizeof(Transitions));
			new -> accepted = accepted;
			new -> result = result;
			new -> next = NULL;

			auxS -> table = new;

		}

	}

	fclose(fp);
	return automat;
}

void evaluateInput(char * a, Automat * automat){

	// Creamos el vector "v" que va a contener los estados
	Vector * v = NULL;

	// Creamos el camino que va registrando los pasos que sigue el autómata
	Path * paths = NULL;

	// Añadimos el primer paso a ambas estructuras, vector y camino
	addState(&v, automat -> start);
	addStep(&paths, 0, automat -> start);

	// Creamos un variable i para recorrer la cadena de entrada
	int i = 0;

	// Empezamos a evaluar la cadena de entrada
	while(a[i]){

		// Limpiamos el vector "new" que es de donde se agregan los nuevos estados.
		Vector * new = NULL;
		Vector * deleteP = NULL;

		// Creamos la variable "j" para llevar un conteo de cuál vector se está evaluando ahora.
		int j = 0;

		// Recorremos los vectores dentro de v
		while(v){

			/* Buscamos en nuestros estados el estado actual, para ello recorremos
			todos los estados que tenemos hasta encontrar el que concuerde con el
			del valor del vector v*/

			State * current = NULL;
			State * auxS = automat -> states;
			while(auxS){
				if(auxS -> value == v -> value){
					current = auxS;
				}
				auxS = auxS -> next;
			}

			/* Verificamos que dicho estado existe. En un archivo estructurado
			de la forma correcta, esta comprobación nunca debería ser 0*/
			if(current){

				/* Esta variable value es la que se le va a dar al autómata para
				que la evalúe con la tabla de transiciones */
				int value = a[i];
				Transitions * aux = current -> table;
				
				/* Recorremos la tabla de transiciones para revisar si es un valor aceptado
				y registramos una bandera para saber si es necesario eliminar el camino o no*/
				int valueAccepted = 0;

				while(aux){
					if(value == aux -> accepted){
						// Valor aceptado 			
						addStates(&new, aux -> result);
						valueAccepted = 1;


						/* Las agregamos además, al camino, pero primero hay que verificar
						cuántos resultados tenemos */
						if(getSize(aux -> result) > 1){
							/*Si es más de uno, tenemos que duplicar el camino que estamos
							actualmente por cada entrada adicional y agregarlo a ese camino */
							
							int times = getSize(aux -> result);
							while(times > 1){
								duplicatePath(&paths, 0);
								times--;

							}
							// Y ahora sí, agregamos los pasos a los caminos
							Vector * auxP = aux -> result;
							while(auxP){
								addStep(&paths, j, auxP -> value);
								auxP = auxP -> next;
								j++;
							}
						}else{
							/*Si es sólo uno, lo agregamos en el índice que corresponde
							(el cual estamos llevando con j)*/
							addStep(&paths, j, (aux -> result) -> value);
						}



					}
					aux = aux -> next;
				}
				if(!valueAccepted){
					addState(&deleteP, j);
				}
	
			}
			
			v = v-> next;
			j++;

		}
		
		deleteVector(v);
		deletePaths(&paths, deleteP);
		v = NULL;
		addStates(&v, new);
		
		i++;
	}

	printf("Los caminos recorridos son:\n");
	printPaths(paths, a);

	Vector * validPaths = validatePaths(paths, automat -> end);

	if(validPaths){
		printf("\nEs una cadena va'lida\n");
	}else{
		printf("\nNo es una cadena va'lida\n");
	}
	printf("Los caminos va'lidos son:\n");

	printPathsI(paths, validPaths, a);

}

void showInfo(Automat * automat){
	//Información del autómata
	printf("Los estados del auto'mata son: ");
	State * auxS = automat -> states;
	while(auxS){
		printf("[q%i] ", auxS -> value);
		auxS = auxS -> next;
	}
	printf("\nLa posicio'n inicial es: [q%i]\n", automat -> start);
	printf("Las posiciones finales son: ");
	Vector * auxV = automat -> end;
	while(auxV){
		printf("[q%i] ", auxV -> value);
		auxV = auxV -> next;
	}

	printf("\n\n== Transiciones ==\n");
	
	auxS = automat -> states;
	while(auxS){
		Transitions * auxT = auxS -> table;
		while(auxT){
			auxV = auxT -> result;
			while(auxV){
				printf("S(%i, %c) -> [q%i]\n", auxS -> value, auxT -> accepted, auxV -> value);
				auxV = auxV -> next;
			}
			auxT = auxT -> next;
		}
		auxS = auxS -> next;
	}
}

Vector * validatePaths(Path * paths, Vector * valid){
	Vector * validPaths = NULL;

	Path * auxP = paths;
	int i = 0;

	while(auxP){
		Vector * auxV = auxP -> vector;
		
		while(auxV -> next){
			auxV = auxV -> next;
		}

		Vector * auxValid = valid;
		while(auxValid){
			if(auxValid -> value == auxV -> value){
				addState(&validPaths, i);
			}
			auxValid = auxValid -> next;
		}

		i++;
		auxP = auxP -> next;
	}

	return validPaths;

}