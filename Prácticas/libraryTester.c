#include "orderedList.c"

int main(){
	OrderedList * one = NULL;
	addToList(&one, 7);
	addToList(&one, 3);
	addToList(&one, 2);

	OrderedList * two = NULL;
	addToList(&two, 7);
	addToList(&two, 3);
	addToList(&two, 1);

	printOrderedList(one);
	printOrderedList(two);

	if(compareLists(one, two)){
		printf("Equal\n");
	}else{
		printf("Different\n");
	}

	

}