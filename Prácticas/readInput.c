#include <stdlib.h>
#include <stdio.h>
#include "string.c"

char * readStringInput();
char readCharInput();
int readIntegerInput();
void cleanStdin();

char * readStringInput(){
	char input[100];
	char * string;

	if(!scanf("%[^\n]s" , input)){
		//printf("Cadena vacía!");
		string = malloc(sizeString(input));
		copyString("\u03BB", string);

	}else{
		string = malloc(sizeString(input)+1);
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

void cleanStdin(){
    int c;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}