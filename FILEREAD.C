// Implemention of  reading of file in C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
// Driver code
void main()
{

	FILE *ptr;
	char ch;
	clrscr();
	// Opening file in reading mode
	ptr = fopen("newfile2.txt","r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");

	// Printing what is written in file
	// character by character using loop.
	do {
		ch = fgetc(ptr);
		printf("%c", ch);

		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch != EOF);

	// Closing the file
	fclose(ptr);
	getch();
}
