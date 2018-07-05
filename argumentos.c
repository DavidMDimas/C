#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	int i;
	if(argc < 2){
		perror("Iingrese algun parametro");
		exit(-1);
	}
	printf("La cantidad de argumentos ingresados es: %d\n", argc - 1);
	for(i = 0; i<argc; i++){
		puts(argv[i]);
	}
	return 0;
}
