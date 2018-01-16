// This program is still incomplete!
// Don't expect anything to work.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VALUESIZE 1
const char values[5][10] = {
	{"414952"},
	{"424f4d42"},
};

char * advance(FILE * in);
int compare(char * a, char * b);

int main(int argc, char * argv[]){
	if(argc == 1)
		return -1;
	FILE * in = fopen(argv[1], "r");
	int i, j;
	char a[3];
	while(!feof(in)){
		strcpy(a, advance(in));
		for(j = 0; j <= VALUESIZE; j++){
			for(i = 0; compare(a, values[j]); i++){
				if(strlen(values[j]) == i){
					printf("Found match!\nDEBUG:\na=%s\nstring=%s\ni=%d\n", a, values[j], i);
					return 0;
				}
				strcpy(a, advance(in));
			}
		}
	}
	printf("Couldn't find an offset, is the data correct?");
	return -1;
}

int compare(char * a, char * b){
	if(a[0] == b[0] && a[1] == b[1])
		return 1;
	return 0;
}

char * advance(FILE * in){
	static char a[3];
	int i;
	for(i = 0; i <= 1; i++){
		a[i] = fgetc(in);
	}
	fgetc(in);
	return a;
}