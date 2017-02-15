/*
 ============================================================================
 Name        : mail3.c
 Author      : Maksim
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>

 #define FILENAME_COUNT 7
 #define FILENAME_WIDTH 16

char isEqual(int index, char *pFilenameBase) {
	int 	symbolIndex = 0;
	FILE 	*goldenHandler = fopen("golden.txt", "r");
	// char 	testFilename[] = *(pFilenameBase + index);
	FILE 	*testHandler = fopen(*(pFilenameBase + index), "r");
	char c1, c2;

	if(testHandler != NULL) {
		while((c1 = getc(goldenHandler)) == (c2 = getc(testHandler))) {
			printf("Compare golden: %c, test %c \n", c1, c2);
		}
		fclose(goldenHandler);
		fclose(testHandler);
		if((c1 == c2) && (c1 == EOF)) {
 			return 1;
		}
	}
	return 0;
}



int main(void) {
	char goldenPict[FILENAME_WIDTH] = "golden.txt";
	char filenameBase[FILENAME_WIDTH][FILENAME_COUNT];
	int fileIndex;
	char *pFilenameBase = &filenameBase[];

	*(pFilenameBase + 0) = "pict0.txt";
	*(pFilenameBase + 1) = "pict1.txt";
	*(pFilenameBase + 2) = "pict2.txt";
	*(pFilenameBase + 3) = "pict3.txt";
	*(pFilenameBase + 4) = "pict4.txt";
	*(pFilenameBase + 5) = "pict5.txt";
	*(pFilenameBase + 6) = "pict6.txt";


	for(fileIndex = 0; fileIndex < FILENAME_COUNT;fileIndex++) {
		if(isEqual(fileIndex, pFilenameBase)) {
			printf("golden.txt is equal to picture%c.txt \n");
			return 0;
		}
	}		
	return 1;
}
