#include <stdlib.h>

typedef struct tranTable{
	int hey;
}transitions;

typedef struct DFA{
	int initial;
	int final;
	char * leng;
	int * status;
}DetFinAut;