/*RFC

4 letras
6 dìgitos*/

#include <stdlib.h>
#include <stdio.h>

int esVocal(char);

int main(){
	char nombre[100];
	char fechaNac[10];
	char rfc[10];
	
	printf("Escribe el nombre: ");
	scanf("%[^\n]s" ,nombre);
	fflush(stdin);
	
	printf("Escribe la fecha de nacimiento DD/MM/AAAA: ");
	scanf("%[^\n]s" ,fechaNac);
	fflush(stdin);	
	//printf(nombre);
	//printf(fechaNac);
	
	int i = 0;
	int espacios = 0;
	
	//Contamos la cantidad de espacios en blanco para saber cuántos nombres tiene la persona
	while(nombre[i] != '\0'){
		if(nombre[i] == ' ') espacios++;
		i++;
	}
	
	/*Dos espacios significa un nombre y dos apellidos.
	Tres espacios son dos nombres y dos apellidos
	Cuatro espacios son tres nombres y dos apellidos*/
	
	/*La cuarta posición de la CURP es la primera letra del primer nombre
	así que no hay pierde*/
	rfc[3] = nombre[0];
	
	/*Necesitamos conseguir el primer y segundo apellido*/
	int espaciosContados = 0;
	
	i = 0;
	
	while(nombre[i] != '\0'){
		if(nombre[i] == ' '){
			
			espaciosContados++;
			
			if(espaciosContados == espacios-1){
				//Primer apellido
				rfc[0] = nombre[i+1];
				
				i++;
				while(!esVocal(nombre[i+1])){
					i++;
				}
				rfc[1] = nombre[i+1];
			}
			
			if(espaciosContados == espacios){
				rfc[2] = nombre[i+1];
			}
		}
		i++;
	}
	
	/*rfc[0] = 'a';
	rfc[1] = 'b';
	rfc[2] = 'c';
	rfc[3] = 'd';*/
	
	//No es una solución bonita, pero suponiendo que el input sea perfecto, funciona.
	rfc[4] = fechaNac[8];
	rfc[5] = fechaNac[9];
	rfc[6] = fechaNac[3];
	rfc[7] = fechaNac[4];
	rfc[8] = fechaNac[0];
	rfc[9] = fechaNac[1];
	
	printf(rfc);
}

int esVocal(char letra){
	
	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
		default:
			return 0;
	}
}