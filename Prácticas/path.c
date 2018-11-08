typedef struct path{
	Vector * vector;
	struct path * next;
}Path;

void addStep(Path ** path, int index, int value){
	if(!*path){
		*path = malloc(sizeof(Path));
		(*path) -> vector = NULL;
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