#include <stdio.h>
#include <stdlib.h>
#include "string.c"

void showMenu();
void doOpc(int, char*, char*);
void cleanStdin();
char * readStringInput();
int readIntegerInput();
char readCharInput();

int main(){

	int opc = -1;

	printf(" == Bienvenido == \n");
	printf("Este programa tiene diversas herramientas para trabajar con cadenas.\n");

	printf("Para empezar, te pido que escribas dos cadenas.\n");
	
	printf("Escribe la cadena 1 (u): ");
	char *stringU = readStringInput();

	printf("Escribe la cadena 2 (v): ");
	char *stringV = readStringInput();
	
	while(opc != 8){
		showMenu();
		opc = readIntegerInput();
		doOpc(opc, stringU, stringV);
	}

	//Para imprimir lambda printf("\u03BB\u03BB\u03BB\n");

	/*printf("%s\n", concat("Hola ", "mundo!"));
	printf("%s\n", prefix("Falta", 1));
	printf("%s\n", sufix("Hey", 1));
	printf("%s\n", subString("Hola", 1, 1));
	printf("%s\n", invert("Howdy"));
	printf("%s\n", stringPow("Pru", -10));*/
}

void doOpc(int opc, char *stringU, char *stringV){
	switch(opc){
		case 1:
			printf("\n == Concatenar dos cadenas == \n");
			printf("uv = %s\n", concat(stringU, stringV));
			printf("vu = %s\n", concat(stringV, stringU));
		break;

		case 2:
		 	printf("\n == Obtener el sufijo de una cadena == \n");

			printf("Escribe la cantidad de caracteres: ");
			int value = readIntegerInput();

			printf("Sufijo de u: %s\n", sufix(stringU, value));
			printf("Sufijo de v: %s\n", sufix(stringV, value));
		break;

		case 3:
			printf("\n == Obtener el prefijo de una cadena == \n");
			
			printf("Escribe la cantidad de caracteres: ");
			value = readIntegerInput();

			printf("Prefijo de u: %s\n", prefix(stringU, value));
			printf("Prefijo de v: %s\n", prefix(stringV, value));
		break;

		case 4:
			printf("\n == Obtener las subcadenas == \n");
			
			printf("Escribe la cantidad de caracteres para el sufijo: ");
			int valueSufix = readIntegerInput();
			printf("Escribe la cantidad de caracteres para el prefijo: ");
			int valuePrefix = readIntegerInput();

			printf("Subcadena de u: %s\n", subString(stringU, valueSufix, valuePrefix));
			printf("Subcadena de v: %s\n", subString(stringV, valueSufix, valuePrefix));
		break;

		case 5:
			printf("\n == Obtener subsecuencias== \n");
			
			printf("Escribe la cantidad de caracteres a eliminar: ");
			value = readIntegerInput();

			printf("Escribe los caracteres que quieres eliminar: ");
			char * aux = readStringInput();
			char * delete = malloc(3);

			int i = 0;
			
			while(i < value){
				delete[i] = aux[i];
				i++;
			}


			printf("Subsecuencia de u: %s\n", subSecuence(stringU, delete));
			printf("Subsecuencia de v: %s\n", subSecuence(stringV, delete));
			
		break;
		
		case 6:
			printf("\n == Invertir las cadenas == \n");
			printf("u = %s | u invertida = %s\n", stringU, invert(stringU));
			printf("v = %s | v invertida = %s\n", stringV, invert(stringV));
		break;

		case 7:
			printf("\n == Elevar las cadenas a una potencia == \n");

			printf("Escribe la potencia a la cual elevar las cadenas: ");
			value = readIntegerInput();

			printf("Imprimir 1)u    2)v");
			int opcion = readIntegerInput();

			switch(opcion){
				case 1:
					printf("u elevado a la %i: %s\n", value, stringPow(stringU, value));
				break;

				case 2:
					printf("v elevado a la %i: %s\n", value, stringPow(stringV, value));
				break;
			}
		case 8:
			//printf("\n == Adio's ==");
		break;

		default:
			printf("ADVERTENCIA: No se reconoce la entrada, escribe una opcio'n va'lida.\n");
		break;
	}
}


char * readStringInput(){
	char input[100];
	char * string;

	if(!scanf("%[^\n]s" , input)){
		//printf("Cadena vacía!");
		string = malloc(sizeString(input));
		copyString("\u03BB", string);

	}else{
		string = malloc(sizeString(input));
		copyString(input, string);
	}
	cleanStdin();
	//printf("== Debug == El taman~o de la cadena es de : %d\n", sizeString(input));
	return string;
}

char readCharInput(){
	char input;

	if(!scanf("%c" , &input)){
		input = 0;
	}
	cleanStdin();
	printf("%c", input);
	//printf("== Debug == El taman~o de la cadena es de : %d\n", sizeString(input));
	return input;
}

int readIntegerInput(){
	int input;
	int result = scanf("%d", &input);

	if (result == EOF) {
	    input = 0;
	    printf("ADVERTENCIA: Error en la lectura. Se interpretara' como 0.\n");
	}
	if (result == 0) {
	    printf("ADVERTENCIA: No se reconoce el valor. Se interpretara' como 0.\n");
	    input = 0;
	}
	cleanStdin();
	return input;
}

void showMenu(){
	printf("\n === Menu principal ===\n");
	printf("1) Concatenar las cadenas\n");
	printf("2) Obtener el sufijo de las cadenas\n");
	printf("3) Obtener el prefijo de las cadenas\n");
	printf("4) Obtener una subcadena\n");
	printf("5) Obtener una subsecuencia de las cadena\n");
	printf("6) Invertir las cadena\n");
	printf("7) Elevar las cadenas a una potencia\n");
	printf("8) Salir\n");
	printf("Elige una opcion: ");
}

void cleanStdin(){
    int c;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}