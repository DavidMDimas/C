

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void my_strcpy (char *t, const char *s);

int main(int argc, char *argv[]){

	char s[] = "Hola Mundo";
	char *t = NULL;

	my_strcpy(t,s);
	puts(s);
	puts(t);
	return 0;
}

void my_strcpy(char *t, const char *s){
	int size;
	size = strlen(s);
	printf("%d\n", size);
	t = (char *)malloc(size * sizeof(char));
	if(t == NULL){
		perror("Error en asignacion de memoria");
		exit(-1);
	}
int i;
	for(i=0; i <size; i++){
		t[i] = s[i];
	}
t[size - 1]='\0';

}
