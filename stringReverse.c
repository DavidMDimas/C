#include<stdio.h>
#include <string.h>

void string_reverse(char *);

int main(void){
	char buffer[] = "Hola Mundo";
	puts(buffer);
	string_reverse(buffer);
	puts(buffer);

}

void string_reverse(char *buffer){
	int index_low, index_high;
	char aux;
	index_high = (strlen(buffer) - 1);

	for(index_low = 0; index_low < index_high; ++index_low){
		aux = buffer[index_low];
		buffer[index_low] = buffer[index_high];
		buffer[index_high] = aux;
		index_high--;
	}

}
