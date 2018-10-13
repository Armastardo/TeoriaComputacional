#include "vector.c"

typedef struc branch{

	struct branch * dad;

	int data;

	struct branch * sons;
	struct branch * next;

}Branch;