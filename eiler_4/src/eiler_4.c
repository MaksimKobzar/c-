/*
 ============================================================================
 Name        : eiler_4.c
 Author      : Maksim
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 			Ask Sasha about not less than 900 constraint for each opearnds
 ============================================================================
 */

#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
// ASK libs eat mem space

#define DIMENSION 	6
#define FOLD 		11

const short max3_val = 999;
int results[200];
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
	int i = 0;
	short op1 = max3_val;
	// short op1 = max3_val - (max3_val%FOLD);
	short op2 = max3_val;

	while ((op1 > 100) || (op2 > 100)) {
	// while (is_palindrome(op1, op2)) {
		/*if(op1 == op2) {
			op1 -= FOLD;
			op2 = max3_val;
		}
		else
			--op2;*/
		if(is_palindrome(op1, op2)) {
			if((op1 > 500 )&& (op2 > 500)) {
				if(results[0] < op1*op2) {
					results[0] = op1 * op2;
					results[1] = op1;
					results[2] = op2;
				}
			}
		}

		if(op2 == 100) {
			op2 = max3_val;
			--op1;
		}
		else {
			op2--;
		}
	}
	printf("Result: %d * %d = %d.\n", results[1], results[2], results[0]);
	return 0;
}
