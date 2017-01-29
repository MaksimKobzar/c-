/*
 ============================================================================
 Name        : eiler_4.c
 Author      : Maksim
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 			Ask Sasha about not less than MIN3_VAL == 900 constraint for each opearnds
 			обдумать что можно делать не на степень 10ки а просто потсоняно на 10ки
 ============================================================================
 */

#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
// ASK libs eat mem space

#define DIMENSION 	6
#define FOLD 		11

const short MAX3_VAL = 999;
const short MIN3_VAL = 900;
int results[3];
int result_index;


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

// ASK HOW RETURN BOOLEAN VALUE?!
char is_palindrome (short v1 , short v2) {
	int i; // ASK for(int i = 0; ...)!
	int multi = v1 * v2;

	printf("is_palindrome: %d * %d = %d.\n", v1, v2, v1 * v2);

	for (i = 0; i < DIMENSION/2; i++) {
		printf("left: %d (%d / %d = %d),  right: %d (%d / %d = %d),  result %d \n",
			(multi/	int_pow(10, i)) 	% 10, 		multi, 	int_pow(10, i), 		multi/	int_pow(10, i),
			(multi/	int_pow(10, DIMENSION -1 - i))	% 10, 		multi, 	int_pow(10, DIMENSION - 1 - i), 	multi/	int_pow(10, DIMENSION - 1 - i),
			(multi/	int_pow(10, i)) 	% 10 != (multi/ int_pow(10, DIMENSION - 1 - i)) %10);
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
		if(is_palindrome(op1, op2) && (results[0] < op1*op2)) {
			results[0] = op1 * op2;
			results[1] = op1;
			results[2] = op2;
		}

		if(op2 == MIN3_VAL) {
			op2 = MAX3_VAL;
			--op1;
		}
		else {
			--op2;
		}
	}
	printf("Result: %d * %d = %d.\n", results[1], results[2], results[0]);
	return 0;
}
