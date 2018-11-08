#include "path.c"
#include "vector.c"

int main(){
	Path * paths = NULL;
	addStep(&paths, 0, 1);
	addStep(&paths, 0, 2);
	addStep(&paths, 0, 3);

	duplicatePath(&paths, 0);

	addStep(&paths, 0, 3);
	addStep(&paths, 1, 4);


	printPath(paths, 0, "abc");
	printf("======\n");
	printPath(paths, 1, "abc");
//	printf("======\n");
	//printVector(getPath(paths, 2));
}