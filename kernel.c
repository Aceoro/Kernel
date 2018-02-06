/*
*  kernel.c
*  probably won't ever be anything
*  https://www.youtube.com/watch?v=27PphV5wqdk
*/
#include "kernel.h"

unsigned int written = 0;
void print(const char *prnt, char *vidptr) {
	unsigned int i = 0;
	unsigned int j = 0;

	while (prnt[j] != '\0') {
                vidptr[i] = prnt[j];
                vidptr[i+1] = 0x07;
                ++j;
                i = i + 2;
	}
	++written;
	return;
}


void clear(void) {
	char *vidptr = (char*)0xb8000;
	unsigned int j = 0;
	while (j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;


	return;
}

void disperr(const char *error) {
	clear();
	char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j =  0;
        while (error[j] != '\0') {
                vidptr[i] = error[j];
		vidptr[i+1] = 0x04;
		++j;
                i = i + 2;
        }

	return;
}


void kmain(void) {
	clear(); // clear() used here to remove all qemu strings
	print("ur mom big gay", (char*)0xb8000);
	//disperr("an error has occured"); // error test
	return;
}

