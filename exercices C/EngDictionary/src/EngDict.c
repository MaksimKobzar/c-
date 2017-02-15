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

#define PAGE_LINE_NUMBER 50


int numberBigPage = 0;
int numberLetters = 0;



//------------------------------- MAIN FUNCTIONS ----------------------------------//
char isLastPage(FILE *fileHandler, int handlerOffset) {
	int countLines = 0;
	int symbolIndex = 0;

	while(countLines < PAGE_LINE_NUMBER) {
		if(getc(*(fileHandler + handlerOffset + symbolIndex++)) == EOF) {
			return 1;
		}
		else if(*(fileHandler + handlerOffset + symbolIndex++) == '\n') {
			countLines++;		
		}
	}
	return 0;
}

char isLetter(char symbol) {
	if('a' <= symbol && symbol <= 'z') {
		return 1;
	}
	return 0;
}

int getNumberLetters(FILE *fileHandler, int handlerOffset) {
	int numberLetters = 0, countLines = 0, symbolIndex = 0;
	char symbol = NULL;

	while(countLines < PAGE_LINE_NUMBER) {
		symbol = getc(*(fileHandler + handlerOffset + symbolIndex++));
		if(isLetter(symbol)) {
			numberLetters++;
		}
		else if(symbol == '\n') {
			countLines++;
		}
		else if(symbol == EOF) {
			break;
		}
	}
	return numberLetters;
}

getPageSize(FILE *fileHandler, int handlerOffset) {
	int pageSize = 0, countLines = 0, symbolIndex = 0;
	char symbol = NULL;

	while(countLines < PAGE_LINE_NUMBER) {
		pageSize++;
		symbol = getc(*(fileHandler + handlerOffset + symbolIndex++));
		if(symbol == '\n') {
			countLines++;
		}
		else if(symbol == EOF) {
			break;
		}
	}
	return pageSize;
}

// maybe do it char return to say about copy status
void copy2Buffer(FILE *fileHandler, int handlerOffset, char *pageBuffer) {
	char symbol;
	int symbolIndex = 0, countLines = 0;

	while(countLines < PAGE_LINE_NUMBER) {
		symbol = getc(fileHandler);
		*(pageBuffer + symbolIndex++) = symbol;
		if(symbol == '\n') {
			countLines++;
		}
		else if(symbol == EOF) {
			break;
		}
	}
}

char* getBigPage(char *filename)
{
  char foundEOF = 0;
  int pageSize, currNumberLetters, pageIndex = 0, handlerOffset = 0;
  char *pageBuffer = NULL;
  FILE *fileHandler = fopen(filename, "r");

  if (fileHandler)
  {		
  	while(foundEOF == 0) {
  		foundEOF = isLastPage(fileHandler, handlerOffset);
  		currNumberLetters = getNumberLetters(fileHandler, handlerOffset);
  		if(numberLetters < currNumberLetters) {
  			// free previous pointer
  			free(pageBuffer);
  			// get size of current page and allocate space in heap for that
  			pageSize = getPageSize(fileHandler, handlerOffset);
  			pageBuffer = (char*) malloc(sizeof(char) * (pageSize + 1));
  			// copy current page to heap
  			copy2Buffer(fileHandler, handlerOffset, &pageBuffer);
  			
  			// Save the serial number and letters number of current winner
  			numberLetters = currNumberLetters;
  			numberBigPage = pageIndex;
  		}
  		pageSize = getPageSize(fileHandler, handlerOffset);
  		handlerOffset += pageSize;
  		pageIndex++;
  	}
    fclose(fileHandler);
  }
  return(pageBuffer);
}


void printPage(char *page) {
	int countLineEnding = 0, symbolIndex = 0;
	char symbol = NULL;

	printf("The biggest amount of letters %d on the %d page. \n", numberLetters, numberBigPage);
	while(countLineEnding < PAGE_LINE_NUMBER) {
		symbol = *(page + symbolIndex++);
		printf("%c", symbol);
		if (symbol == '\n') {
			countLineEnding++;
		}
	}
}


int main(void) {
  char *pageContent = getBigPage("EngDict.txt");
  if(pageContent == NULL) {
  	printf("Failed openning file! \n");
		return 1;
  }
  else {
  	printPage(&pageContent);
  	free(pageContent);
		return 0;
  }
}

