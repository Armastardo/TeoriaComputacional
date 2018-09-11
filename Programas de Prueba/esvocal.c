#include <stdlib.h>
#include <stdio.h>

int esVocal(char);

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
