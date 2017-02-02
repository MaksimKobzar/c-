/*
 ============================================================================
 Name        : eiler_4.c
 Author      : Maksim
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 			TODO обдумать что можно делать не на степень 10ки а просто потсоняно на 10ки
 ============================================================================
 */

#include <stdio.h>

#define DIMENSION 6
#define FOLD 			11
#define MAX3_VAL 	999
#define MIN3_VAL 	900

int pal;

int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

char is_palindrome (short v1 , short v2) {
	int i;
	int multi = v1 * v2;

	for (i = 0; i < DIMENSION/2; i++) {
		if((multi/	int_pow(10, i)) 	% 10 != (multi/ int_pow(10, DIMENSION - 1 - i)) %10) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	short op1 = MAX3_VAL - (MAX3_VAL%FOLD);
	short op2 = MAX3_VAL;

	while ((op1 >= MIN3_VAL) && (op2 >= MIN3_VAL)) {
		if(is_palindrome(op1, op2) && (pal < op1*op2)) {
			pal = op1 * op2;
		}

		if(op2 == MIN3_VAL) {
			op2 = MAX3_VAL;
			--op1;
		}
		else {
			--op2;
		}
	}
	printf("Result: %d.\n", pal);
	return 0;
}
