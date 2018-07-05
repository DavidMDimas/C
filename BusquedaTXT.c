#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main (int argc, char * argv[]){
	int fd, cont = 0, indice = 0, cont_linea = 1, linea;
	char caracter;
	ssize_t cant;

	/*cantidad de argumentos que usaremos*/
	if(argc <3){
		exit(0);
	}
	/*Abrimos el archivo, leido por el argumento argv en la posicion 1*/
	fd = open(argv[1],O_RDONLY);
	if(fd < 0){
		perror("Error al abrir el archivo");
		exit(-1);
	}
	do{
		/*devuelve la cantidad de bytes que leyo*/
		cant = read(fd, (char *)&caracter, 1);
		if(caracter == '\n')
			cont_linea++;
		if(caracter == argv[2][indice]){
			indice++;
			if(argv[2][indice] == '\0'){
				indice = 0;
				cont++;
				linea = cont_linea;
				printf("Frase detectada en linea %d\n",linea);
			}
		}
		else{
			indice = 0;
		}

	}


	while(cant > 0);
	printf("La cantidad de veces que encontro la frase es %d\n",cont);

	return 0;
}

