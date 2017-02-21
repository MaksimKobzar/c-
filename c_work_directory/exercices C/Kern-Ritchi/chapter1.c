//----------------------------------------------
//
//----------------------------------------------

#include <stdio.h>

int main() {


	// 1.6
	char symbol;
	while(symbol = (getchar() != EOF)) {
		printf("symbol is %d\n", symbol);
	}

	printf("EOF is %d", EOF);

	return 0;
}
