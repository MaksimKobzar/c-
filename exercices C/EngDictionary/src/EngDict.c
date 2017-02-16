/*
 ============================================================================
 Name        : EngDict.c
 Author      : Maksim
 Version     :
 Copyright   :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_LINE_NUMBER 50
#define FILENAME_WIDTH 20
 #define STRING_BUFFER_SIZE 4096

int numberBigPage = 0;
int numberLetters = 0;
char dictFilename[FILENAME_WIDTH];



//------------------------------- MAIN FUNCTIONS ----------------------------------//
char isLetter(char symbol) {
	if('a' <= symbol && symbol <= 'z') {
		return 1;
	}
	return 0;
}

int getNumberLetters(char *checkString) {
	int numberLetters = 0, index = 0;
	char c = NULL;

	while((c = *(checkString + index++)) != "\n") {
		if(isLetter(c)) {
			numberLetters++;
		}
	}
	return numberLetters;
}

void getBigestPage() {
  FILE *fileHandler = fopen(dictFilename, "r");
  char *stringBuffer = (char*) malloc(sizeof(char) * (STRING_BUFFER_SIZE + 1));
  char c = NULL;
	int winner = 0, pageCount = 0,
			currLettersNumber = 0, maxLettersNumber = 0,
			stringCount = 0, readedCount = 0;

  if (fileHandler) {
  	while((readedCount = fgets(stringBuffer, STRING_BUFFER_SIZE, fileHandler)) != NULL) {
  		if(readedCount != STRING_BUFFER_SIZE) {
  			stringCount++;
  		}
  		currLettersNumber += getNumberLetters(&stringBuffer);
  		if(currLettersNumber > maxLettersNumber) {
  			maxLettersNumber = currLettersNumber;
  			winner = pageCount;
  		}
  		if(stringCount == PAGE_LINE_NUMBER) {
  			pageCount++;
  			currLettersNumber = 0;
  			stringCount = 0;
  		}
  	}
  	while((c = fgetc(stringBuffer)) != EOF) {
  		currLettersNumber += getNumberLetters(c);
  	}
  	if(currLettersNumber > maxLettersNumber) {
			maxLettersNumber = currLettersNumber;
			winner = pageCount;
		}
  }
  else {
  	printf("Failed to open file with name: %s!", dictFilename);
  	return;
  }
  fclose(fileHandler);
  free(stringBuffer);
  printf("Winner page with serial number %d contains %d english symbols. \n", winner, maxLettersNumber);
}

int main(void) {

	// initialization
	printf("Enter filename for English Dictionary: \n");
	scanf("%s", dictFilename);

  if(dictFilename == NULL) {
  	printf("Wrong name! \n");
		return 1;
  }

  getBigestPage();
	return 0;
}

