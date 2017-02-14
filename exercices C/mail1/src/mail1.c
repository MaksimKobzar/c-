/*
 ============================================================================
 Name        : mail1.c
 Author      : Maksim
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

char checkSequence(char *someSequence) {
	int roundCounter = 0, bracesCounter = 0, squareCounter = 0, lessCounter = 0;
	int index = 0;
	char c = NULL;

	while(index < strlen(someSequence)) {
		c = *(someSequence + index++);

		if(c == '(') {
			roundCounter++;
		}
		else if(c == '{') {
			bracesCounter++;
		}
		else if(c == '[') {
			squareCounter++;
		}
		else if(c == '<') {
			lessCounter++;
		}
		else if(c == ')') {
			if(roundCounter > 0) {
				roundCounter--;
			}
			else {
				return 0;
			}
		}
		else if(c == '}') {
			if(bracesCounter > 0) {
				bracesCounter--;
			}
			else {
				return 0;
			}
		}
		else if(c == ']') {
			if(squareCounter > 0) {
				squareCounter--;
			}
			else {
				return 0;
			}
		}
		else if(c == '>') {
			if(lessCounter > 0) {
				lessCounter--;
			}
			else {
				return 0;
			}
		}
		else {
			printf("Unexpected symbol.\n");
			return 0;
		}
	}
	if((roundCounter + bracesCounter + squareCounter + lessCounter) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	char result = NULL;
	char randomSequence[1000] = "[{}<>";

	result = checkSequence(&randomSequence);
	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
