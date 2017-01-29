/*
 ============================================================================
 Name        : project_eiler_20.c
 Author      : Maksim
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ASK SASHA как заменить деление на 10 на свдиг?
 ============================================================================
 */

#include <stdio.h>
#include <inttypes.h>
// #include <stdlib.h>

#define ARRAY_SIZE 200

const int MAX_VAL = 10;
short count = 0;

short fact_result[ARRAY_SIZE];

int int_pow(int base, int exp) {
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

int count_bits(int value) {
    int counter = 0;
    while (value / 10 > 0)
        counter++;
    return counter;
}

void count_fact(int val) {
	int carry = 0; 
	int i, j, z, temp_val;
	carry[0] = 1;

	// перебираю все множители факториала
	for(z = 1; z < val; z++) {
		temp_val = z;
		// перебираю все значения полученного множителя , т.е если я получаю 2154 я перебираю  4, 5, 1, 2.
		for(i = 0; i < count_bits(temp_val); i++) {
			// перебираю все значения массива, т.е. arr[0], arr[1], arr[2], arr[3] ....
			for(j = 0; j < ARRAY_SIZE; j++) {
				fact_result[j] *= (temp_val + carry) % 10;
				carry = fact_result[j] /= 10 ;
				// fact_result[j] /= 10;
			}
			temp_val /= 10;
		}
	}
}

int main(void) {
	// int i = 0;
	// int numeral;
	count_fact(MAX_VAL);

	printf("factorial = %d%d%d%d%d\n", fact_result[4], fact_result[3], fact_result[2], fact_result[1], fact_result[0]);
	// printf("fact / int_pow(10, i) = %ld\n", fact / int_pow(10, i));
	// printf("(numeral = (fact / int_pow(10, i))) != 0 is %d\n", (numeral = (fact / int_pow(10, i))) != 0);

	// while((numeral = (fact / int_pow(10, i))) != 0){
	// 	count += numeral%10;
	// 	i++;
	// }

	// printf("Summ numerals in number %d! is %d.\n", MAX_VAL, count);
	return 0;
}