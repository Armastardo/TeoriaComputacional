//Transiciones de la tabla de estados
typedef struct transitions{
	char accepted;
	Vector * result;
	struct transitions * next;
}Transitions;

//Estructura de la tabla de estados
typedef struct state{
	int value;
	Transitions * table;
	struct state * next; 
}State;

//Estructura del autómata
typedef struct automat{
	int start;
	Vector * end;
	State * states;
} Automat;

//Si leo X, entonces se vuelve Q y se crea S