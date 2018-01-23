/*
*  kernel.c
*  hopefully one day will be my crypto mining kernel
*/


unsigned int written = 0;
void print(const char *prnt) {
	// video memory starts at 0xb8000, +140 for new line
	// TODO: find some better way that doesn't use if statements
	// that is more programatic
	char *vidptr;
	if (written == 0) {
		vidptr = (char*)0xb8000;
	} else if (written == 1) {
		vidptr = (char*)0xb8140;
	} else if (written == 2) {
		vidptr = (char*) 0xb8280;
	} else {
		clear();
	}
	unsigned int i = 0;
	unsigned int j = 0;

	while(prnt[j] != '\0') {
                vidptr[i] = prnt[j];
                vidptr[i+1] = 0x07;
                ++j;
                i = i + 2;
	}
	++written;
	return;
}

void clear(void) {
	// used as an easy way to detect error within the print()
	// function, if used elsewhere, it isn't an error
	// but rather a way to clear the screen from all the garbage
	// I write
	char *vidptr = (char*)0xb8000;
	unsigned int j = 0;
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07; // 0x07 is light grey, 
		j = j + 2;
	}

	j = 0;


	return;
}

void kmain(void) {
	clear(); // clear() used here to remove all qemu strings
	print("string 1"); // I use these to test, they aren't special
	print("string 2");
	print("string 3");
	return;
}
