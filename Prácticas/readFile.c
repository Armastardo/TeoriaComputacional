#include <stdlib.h>
#include <stdio.h>
#include "string.c"
#include "ndfaFile.c"

Vector * splitInts(char *);

int main(){
	FILE * fp;
	fp = fopen("test.txt", "r");
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

	//Información del autómata
	printf("Los estados del auto'mata son: ");
	auxS = automat -> states;
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

	printf("\n== Transiciones ==\n");
	
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

	fclose(fp);
}

Vector * splitInts(char * buff){

	char * auxS = malloc(250);
	Vector * states = NULL;

	int i = 0;
	int j = 0;

	while(buff[i]){
		//printf("Lei un %c\n", buff[i]);
		if(buff[i] == ','){
			auxS[j+1] = '\0';
			if(sizeString(auxS) > 0){
				//printf("Voy a agregar un %s\n", auxS);
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