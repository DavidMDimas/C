#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define archgpio "/sys/class/gpio/export"
#define archivogpio60 "/sys/class/gpio/gpio60/direction"
#define archivovalue "/sys/class/gpio/gpio60/value"

void export_gpio(char * gpio_number);
void set_direction(char * direction);
void set_value(char * value);


int main(void){
	char gpio_number[] = "60";
	export_gpio(gpio_number);
	set_direction("out");

	while(1){
		sleep(1);
		set_value("1");
		sleep(1);
		set_value("0");
	}
	return(0);
}

void export_gpio(char * gpio_number){
	//abrir el archivo /sys/class/gpio/export
	int fd, tamanio;
	ssize_t cant;
	fd = open(archgpio,O_WRONLY);
	if(fd <0){
		perror("Archivo no encontrado");
	}
	tamanio = strlen(gpio_number);
	cant = write(fd,gpio_number, sizeof(char) *tamanio);
	close(fd);

}

void set_direction(char * direction){
	//abrir el archivo /sys/class/gpio/gpio60/direction
	int fd, tamanio;
	ssize_t cant;
	fd = open(archivogpio60 ,O_WRONLY);
	if(fd <0){
		perror("Archivo no encontrado");
	}
	tamanio = strlen(direction);
	cant = write(fd,direction, sizeof(char) *tamanio);
	close(fd);
}

void set_value(char * value){
	//Abrir el archivo /sys/class/gpio/gpio60/value
	int fd, tamanio;
	ssize_t cant;
	fd = open(archivovalue,O_WRONLY);
	if(fd <0){
		perror("Archivo no encontrado");
	}
	tamanio = strlen(value);
	cant = write(fd, value, sizeof(char )*tamanio);
	close(fd);
}
