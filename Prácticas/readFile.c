#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE * fp;
	fp = fopen("test.txt", "r");
	char buff[250];

	int i = 1;

	while(fscanf(fp, "%s", buff)!= EOF){	
		printf("%i - %s\n", i, buff);
		i++;
	}

	fclose(fp);
}