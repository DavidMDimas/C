#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define limite 1024


int main (int argc, char * argv[]){
	int fd, cant, cont_2, cont_h, cont;
	char caracter;
	char texto[1024];
	int longitud, total;
	float num;
	char * concatenacion;
	char cadena[50];

	longitud = strlen(argv[2]);
	concatenacion = (char *)malloc(total+1);
	strcat(concatenacion, argv[2]);
	printf("La cadena escrita es: %s\n",concatenacion);


	if(argc < 3){
		perror("Ingresa una cadena");
		exit(-1);
	}
	fd = open(argv[1],O_RDONLY);
	if(fd < 0){
		perror("Error al abrir el archivo");
		exit(-1);
	}


	do{
		cant = read(fd, (char *)&caracter, 1);
		printf("%c",caracter);
	//	fgets(cadena, limite, fd);
	//	puts(cadena);


		if(caracter == ' '){
			cont++;
		}
		if(caracter == texto[cont_2]){
			cont_h++;

		}
		/*if(cont_2 == 3){
			cont_2++;
			cont_h = 0;

		}*/

	}


	while(cant > 0);
	printf("%d\n",cont_h);
	return 0;
}
