#include <stdio.h>
#include <stdlib.h>

int sizeString(char *);
void copyString(char *, char*);
int compareString(char*, char*);
int emptyString(char *);
char * concat(char *, char *);
char * prefix(char *, int);
char * sufix(char *, int);
char * subString(char *, int, int);
char * subSecuence(char*, char *);
char * invert(char *);
char * stringPow(char *, int);

void copyString(char * origin, char *copy){
	int i = 0;
	while(origin[i]){
		copy[i] = origin[i];
		i++;
	}
	copy[i] = '\0';
}

int compareString(char * stringOne, char* stringTwo){
	int result;

	if(sizeString(stringOne) == sizeString(stringOne)){
		result = 1;
		int i = 0;
		while(stringOne[i]){
			if(stringOne[i] != stringTwo[i]){
				result = 0;
			}
			i++;
		}
	}else{
		result = 0;
	}
	return result;
}

int emptyString(char * string){
	return compareString(string, "\u03BB");

}

int sizeString(char * string){
	int i = 0;
	while(string[i]){
		i++;
	}
	return i;
}

char * concat(char * one, char * two){
	//Concatenación (Tiene que mostrar uv y vu)

	char * conc;

	if(emptyString(one)){
		conc = two;
	}else if(emptyString(two)){
		conc = one;
	}else{
		conc = malloc(sizeString(one) + sizeString(two));
		int i = 0;
		int j = 0;
		while(one[i]){
			conc[j] = one[i];
			i++;
			j++;
		}

		i = 0;
		
		while(two[i]){
			conc[j] = two[i];
			i++;
			j++;
		}
		conc[j] = '\0';
	}

	return conc;
}

char * prefix(char * string, int value){
	//Prefijo (eliminar 0 o más del final, para ambas cadenas)
	char * newString;

	int newLength = sizeString(string)-value;

	if(newLength <= 0){
		newString = malloc(2);
		copyString("\u03BB", newString);
	}else{
		newString = malloc(newLength+1);

		int i = 0;
		while(i < newLength){
			newString[i] = string[i];
			i++;
		}
	}


	return newString;
}

char * sufix(char * string, int value){
	//Sufijo (eliminar 0 o más del inicio, para ambas cadenas)
	char * newString;

	int newLength = sizeString(string)-value;

	if(newLength <= 0){
		newString = malloc(2);
		copyString("\u03BB", newString);

	}else{
		newString = malloc(newLength+1);

		int i = 0;
		while(value < sizeString(string)){
			newString[i] = string[value];
			value++;
			i++;
		}
		
		newString[i] = '\0';
		
	}
	return newString;
}

char * subString(char * string, int pre, int su){
	//Subcadena (eliminar un prefijo y eliminar un sufijo, hay que pedir la longitud del prefijo y del sufijo, para ambas cadenas)
	if(sizeString(string) - pre - su <= 0){
		return "\u03BB";
	}else{
		return prefix(sufix(string, su), pre);
	}
}

char * subSecuence(char* string, char * del){
	/*Subsecuencia (lee un entero y luego lee los símbolos que quieres eliminar)*/
	
	int size = sizeString(string);

	int i = 0;
	while(string[i]){
		int j = 0;
		while(del[j]){	
			if(string[i] == del[j]){
				size--;
			}	
			j++;
		}
		i++;
		j = 0;
	}

	char * subString = malloc(size);
	i = 0;
	int k = 0;
	while(string[i]){
		int j = 0;
		while(del[j]){	
			if(string[i] == del[j]){
				i++;
			}	
			j++;
		}
		subString[k] = string[i]; 
		i++;
		k++;
		j = 0;
	}


	return subString;
}

char * invert(char * string){
//Invertir (imprime las cadenas al revés)

	int aux = sizeString(string);
	char * reversed = malloc(aux+1);

	if(emptyString(string)){
		reversed = string;
	}else{	
		int i = 0;
		while(i < aux){
			reversed[i] = string[aux-1-i];
			i++;
		}
		reversed[i] = '\0';
	}

	return reversed;

}

char * stringPow(char * string, int value){
	//Potencia (recibe un entero (positivo o negativo), si es positivo se concatena el número de veces,
    //si es 0 se imprime lambda, si es negativo se imprime la cadena concatenada de forma inversa)
	if(value == 0 || emptyString(string)){
		return "\u03BB";
	}

	int neg = 0;
	
	if(value < 0){
		value = value*(-1);
		neg = 1;
	}

	int newSize = (sizeString(string)+1	 * value);
	
	printf("%d", newSize);

	char * powedString = malloc(newSize);

	int k = 1;
	int j = 0;

	while(k <= value){
		int i = 0;
		while(string[i]){
			powedString[j] = string[i];
			i++;
			j++;
		}
		k++;
	}
	powedString[j] = '\0';
	
	if(neg){
		return invert(powedString);
	}

	return powedString;	
}