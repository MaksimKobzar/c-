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

// char isEqual(int index, char *pFilenameBase) {
// 	FILE 	*goldenHandler 	= fopen("golden.txt", "r");
// 	FILE 	*testHandler 		= fopen(*(pFilenameBase + index), "r");
// 	int goldenPiece, testPiece;

// 	if(testHandler != NULL) {
// 		while((goldenPiece = fgetc(goldenHandler)) == (testPiece = fgetc(testHandler))) {
// 			printf("Compare golden: %c, test %c \n", goldenPiece, testPiece);
// 		}
// 		fclose(goldenHandler);
// 		fclose(testHandler);
// 		if((goldenPiece == testPiece) && (goldenPiece == EOF)) {
//  			return 1;
// 		}
// 	}
// 	return 0;
// }


int main(void) {
	char goldenPict[FILENAME_WIDTH] = "golden.txt";
	int fileIndex;
	char filenameBase[FILENAME_COUNT][FILENAME_WIDTH] {
		"pict0.txt", "pict1.txt", "pict2.txt", "pict3.txt", "pict4.txt", "pict5.txt", "pict6.txt"
	};
	filenameBase *pFilenameBase;

	for(index = 0; index < FILENAME_COUNT; index++) {
		printf("filenameBase[%d] = %s", filenameBase[index]);
	}


	// for(fileIndex = 0; fileIndex < FILENAME_COUNT;fileIndex++) {
	// 	if(isEqual(fileIndex, pFilenameBase)) {
	// 		printf("golden.txt is equal to picture%c.txt \n");
	// 		return 0;
	// 	}
	// }
	return 1;
}
