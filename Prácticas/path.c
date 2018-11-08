#include "vector.c"

typedef struct path{
	Vector * vector;
	struct path * next;
}Path;

void addStep(Path ** path, int index, int value){
	if(!*path){
		*path = malloc(sizeof(Path));
		(*path) -> vector = NULL;
		(*path) -> next = NULL;
	}

	int i = 0;
	if(index == 0){
		addState(&((*path) -> vector), value);
	}else{
		Path * aux = *path;
		while(index > i){
			aux = aux -> next;
			i++;
		}
		addState(&(aux -> vector), value);
	}
}

void duplicatePath(Path ** path, int index){
	Path * new = malloc(sizeof(Path));
	new -> vector = NULL;
	new -> next = NULL;

	int i = 0;
	if(index == 0){
		addStates(&(new -> vector), (*path) -> vector);
		new -> next = (*path) -> next;
		(*path) -> next = new;
	}else{
		Path * aux = *path;
		while(index > i){
			aux = aux -> next;
			i++;
		}
		addStates(&(new -> vector), aux -> vector);
		new -> next = aux -> next;
		aux -> next = new;
	}
}

Vector * getPath(Path * path, int index){
	if(index == 0){
		return path -> vector;
	}else{
		int i = 0;
		while(index > i){
			path = path -> next;
			i++;
		}
		return path -> vector;
	}
}


void deletePath(Path ** path, int index){
	int i = 0;
	if(index == 0){
		Path * aux = *path;
		(*path) = (*path) -> next;
		free(aux);
	}else{
		int i = 0;
		Path * aux = *path;
		while(index-1 > i){
			aux = aux -> next;
			i++;
		}
		Path * delete = aux -> next;
		aux -> next = delete -> next;
		free(delete);
	}
}

void deletePaths(Path ** path, Vector * indexes){
	int i = 0;
	while(indexes){
		deletePath(path, (indexes -> value) - i);
		i++;
		indexes = indexes -> next;
	}
}

void printPath(Path * path, int index, char * input){
	int i = 0;
	Path * aux = path;
	while(index > i){
		aux = aux -> next;
		i++;
	}

	Vector * auxV = aux -> vector;

	i = 0;
	while(auxV){
		if(input[i]){
			printf("[q%i] - %c -> ", auxV -> value, input[i]);	
		}else{
			printf("[q%i]\n", auxV -> value);
		}
		auxV = auxV -> next;
		i++;
	}

}

void printPaths(Path * path, char * input){
	
	if(!path){
		printf("No hay ningu'n camino\n");
	}else{
		Path * auxP = path;
		while(auxP){
			Vector * auxV = auxP -> vector;
			int i = 0;
			while(auxV){
				if(auxV -> next){
					printf("[q%i] - %c -> ", auxV -> value, input[i]);	
				}else{
					printf("[q%i]\n", auxV -> value);
				}
				auxV = auxV -> next;
				i++;
			}
			auxP = auxP -> next;
		}
	}
}

void printPathsI(Path * path, Vector * indexes, char * input){
	while(indexes){
		printPath(path, indexes -> value, input);
		indexes = indexes -> next;
	}
}