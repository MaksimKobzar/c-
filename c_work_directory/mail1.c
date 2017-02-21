#include <stdio.h>


char checkSequence(char *someSequence) {
	int roundCounter = 0, bracesCounter = 0, squareCounter = 0, lessCounter = 0;
	char c = NULL;

	while(c != EOF) {
		c = *(someSequence + index);
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
			printf("Unexpected sign\n");
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
	char defaultPattern[1000] = "[{}]<>";		

	result = checkSequence(&defaultPattern);
	printf("%s\n", result);

	return 0;
}