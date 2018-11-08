#include "path.c"

int main(){
	Path * paths = NULL;
	addStep(&paths, 0, 1);

	duplicatePath(&paths, 0);


	printPath(paths, 0, "");
	printf("======\n");
	printPath(paths, 1, "");
//	printf("======\n");
	//printVector(getPath(paths, 2));
}