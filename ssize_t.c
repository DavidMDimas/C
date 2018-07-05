
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int num_aleatorio, cantidad, min, max,fd, i, x, size;
int aleatorios, almacen;
ssize_t cant;
char b[1024];




int main(int argc, char * argv[]){

	if(argc < 4){
		printf("Ingresar parametros correctos\n");
		return(0);
	}

	fd = open(argv[4],O_WRONLY);
	if(fd < 0){
		perror("Error al abrir el archivo");
		exit(-1);
	}
	cantidad = atoi(argv[1]);
	min = atoi(argv[2]);
	max = atoi(argv[3]);


	for(i = 0; i < cantidad; i++){

		srand(clock());
		num_aleatorio = min + (rand()%(max - min));
		size = sprintf(b, "%d%c", num_aleatorio, ' ');

		write(fd, (char *)&b ,size);

	}

	close(fd);
	return 0;
}

//srand(time(NULL))

//printf("El rango maximo aleatorio: %d\n",RAND_MAX);

//printf("Numero aleatorio %d\n ", num_aleatorio);
