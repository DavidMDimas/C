
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define archivDirection "/root/workspace/pre_examen/direction.txt"
#define archivValue "/root/workspace/pre_examen/value.txt"
//#define archivValue  "/sys/class/gpio/gpio60/value"
//#define archivDirection  "/sys/class/gpio/gpio60/direction"


void set_direction(int direction ){
	int fd;
	ssize_t cant;
	char caracterD[3] = "IN ";
	char caracterD_2[3] = "OUT";

	if(direction == 1){
		fd = open(archivDirection,O_WRONLY);
		cant = write(fd, (char *)&caracterD, 3);
		close(fd);
	}
	if(direction == 0){
		fd = open(archivDirection,O_WRONLY);
		cant = write(fd, (char *)&caracterD_2, 3);
		close(fd);
	}
}

void set_value(int value){
	int fd;
	int cambio;
	ssize_t cant;

	char caracterV[1] = "1";
	char caracterV_2[1] = "0";

	if(value == 1){
		fd = open(archivValue, O_WRONLY);
		cant = write(fd, (char *)&caracterV, 1);
		close(fd);
	}
	if(value == 0){
		fd = open(archivValue, O_WRONLY);
		cant = write(fd, (char *)&caracterV_2, 1);
		close(fd);
	}

}

int main(){
	int contador = 0;

	set_direction(0);
	set_value(0);
	while(contador < 999999){
		sleep(1);
		set_direction(1);
		set_value(1);
		sleep(1);
		set_direction(0);
		set_value(0);
		contador++;
	}
}


