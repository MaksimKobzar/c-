/*
 ============================================================================
 Name        : mail3.c
 Author      : Maksim
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>

 #define FILENAME_COUNT 10
 #define FILENAME_WIDTH 10

int main(void) {
	char goldenPict[FILENAME_WIDTH] = "gold.txt";
	char filenameBase[FILENAME_WIDTH][FILENAME_COUNT];
	int index;
	char *pFilenameBase = &filenameBase[];

	for(index = 0; index < FILENAME_COUNT;index++) {
		*(pFilenameBase + index) = "pict%d.txt" , index;
	}


	for(index = 0; index < FILENAME_COUNT;index++) {
		isEqual()
	}		


	return 0;
}
