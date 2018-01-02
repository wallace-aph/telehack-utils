// This program is still incomplete!
// Don't expect anything to work.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * advance(FILE * in);

int main(int argc, char * argv[]){
	if(argc == 1)
		return -1;
	FILE * in = fopen(argv[1], "r");
	int count;
	while(!feof(in)){
		count++;
		if(!strcmp(advance(in), "4c")){
			printf("FOUND 4c at %d\n", count);
			if(!strcmp(advance(in), "4f")){
				printf("FOUND 4f at %d\n", count);
			}
		}
	}
	printf("Couldn't find an offset, is the data correct?");
	return -1;
}

char * advance(FILE * in){
	char a[3];
	int i;
	for(i = 0; i <= 1; i++){
		a[i] = fgetc(in);
	}
	fgetc(in);
	return a;
}