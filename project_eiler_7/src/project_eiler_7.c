/*
 ============================================================================
 Name        : project_eiler_7.c
 Author      : Maksim
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define MIN_SIMPLE_VAL 2
#define MAX_SIMPLE_VAL 10001

int counter = 0;
int simple_val_arr[1000];

char is_simple(int value) {
	int j;
	if(counter > 0) {
		for(j = 0; j < counter-1; j++) {
			if(value % simple_val_arr[j] == 0)
				return 0;
		}
	}
	return 1;
}

int main(void) {
	int i;
	for(i = MIN_SIMPLE_VAL; i < MAX_SIMPLE_VAL; i++) {
		if(is_simple(i)){
			simple_val_arr[counter++] = i;
		}
	}

	printf("Simple numeric %d has %d serial number.\n", MAX_SIMPLE_VAL, ++counter);
	return 0;
}

