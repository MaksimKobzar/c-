/*
 ============================================================================
 Name        : mail3.c
 Author      : Maksim
 Version     :
 Copyright   :
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

 #define FILENAME_COUNT 7
 #define FILENAME_WIDTH 20


char goldenPictFilename[FILENAME_WIDTH];
char filenameBase[FILENAME_COUNT][FILENAME_WIDTH];

char isEqual(int index) {
	FILE 	*goldenHandler 	= fopen(goldenPictFilename, "r");
	FILE 	*testHandler 		= fopen(filenameBase[index], "r");
	int goldenPiece, testPiece;
	
	if(testHandler != NULL && goldenHandler != NULL) {
		while((goldenPiece = fgetc(goldenHandler)) == (testPiece = fgetc(testHandler))) {
			if((goldenPiece == testPiece) && (goldenPiece == EOF)) {
				fclose(goldenHandler);
				fclose(testHandler);
				return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	int fileIndex;

	// initialization
	printf("Enter filename for etalon picture: \n");
	scanf("%s", goldenPictFilename);
	for(fileIndex = 0; fileIndex < FILENAME_COUNT; fileIndex++) {
		printf("Enter filename for test picture %d number: \n", fileIndex);
		scanf("%s", filenameBase[fileIndex]);
	}

	for(fileIndex = 0; fileIndex < FILENAME_COUNT;fileIndex++) {
		if(isEqual(fileIndex)) {
			printf("%s is equal to %s. \n", goldenPictFilename, filenameBase[fileIndex]);
			return 0;
		}
		else {
			printf("%s isnt equal to %s. \n", goldenPictFilename, filenameBase[fileIndex]);
		}
	}
	return 1;
}
