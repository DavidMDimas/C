#include <stdio.h>
#include <stdlib.h>
	FILE *archivo;
	char caracter;
 	FILE *fp;


void leer(){

		archivo = fopen("copiar.txt","r");

		if (archivo == NULL){
			printf("\nError... \n\n");
	        }else{
		    printf("\nLeyendo...\n\n");
		    while (feof(archivo) == 0)
		    {
			caracter = fgetc(archivo);
			printf("%c",caracter);
		    }
	        }
	        fclose(archivo);

}

void escribir(){

	archivo = fopen("copiar.txt","r");
 	fp = fopen ( "pegar.txt", "a+t" );
 	printf("%c", fputc(caracter, fp));
 	fclose ( fp );

}

int main()
{
	leer();
	escribir();
	return 0;
}
