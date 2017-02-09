//----------------------------------------------
// X / O game with bot
//----------------------------------------------

#include <stdio.h>
#include <ctype.h>
#define DIM 3


typedef enum {X_SYM, O_SYM, E_SYM} symbol_t;

symbol_t userSymbol, botSymbol;
symbol_t board[DIM][DIM];

void init_board(char *pBoard) {
	int i;
	for(i = 0; i < DIM*DIM; i++) {
		*(pBoard + i) = E_SYM;
	}
}

symbol_t selectSymbol() {
	char userChoice;
	printf("----------------------------------------------------------------------\n");
	printf(" \tSelect what symbol do you want to play?  \n");
	printf(" \tEnter 'X' or 'O'  ! Player with 'X' moves first.  \n");
	printf(" \t(any character except 'X', will be regarded as 'O')  \n");
	printf("----------------------------------------------------------------------\n");
	scanf("%c", &userChoice);
	getchar();
	printf("MY_DBG: userChoice = %c \n", 	userChoice);
//	printf("MY_DBG: *userChoice = %c \n", 	*userChoice);
	if(userChoice == 'X' || userChoice == 'x') {
		userSymbol 	= X_SYM;
		botSymbol 	= O_SYM;
		printf("MY_DBG: user X\n");
	}
	else {
		userSymbol = O_SYM;
		botSymbol = X_SYM;
		printf("MY_DBG: user O\n");
	}
	return userSymbol;
}

char isWinnerKnown(char *pBoard) {
	int i;
	for(i = 0; i < DIM*DIM; i++) {
		if((*(pBoard + i) != E_SYM) && (
			((*(pBoard + i) == *(pBoard + i + 1) 				== *(pBoard + i + 2)) 					&& (i%DIM == 0)) || // {0, 1, 2}, {4, 5, 6} ...  
			((*(pBoard + i) == *(pBoard + i + DIM) 			== *(pBoard + i + 2*DIM)) 			&& (i < DIM) 	 ) || // {0, 3, 6}, {1, 4, 7} ...
			((*(pBoard + i) == *(pBoard + i + DIM + 1) 	== *(pBoard + i + 2*(DIM + 1))) && (i == 0) 	 ) || // {0, 4, 8}
			((*(pBoard + i) == *(pBoard + i + DIM - 1) 	== *(pBoard + i + 2*(DIM - 1))) && (i == DIM)  )  	// {2, 4, 6}
		))
			return 1;
	}
	return 0;
}

char isDigit(char someSymbol) {
	if(('0' <= someSymbol) && (someSymbol <= '9')) {
		return 1;
	}
	return 0;
}

void userRound(char *pBoard) {
	int 	pos, countCoordinates = 0;
	char 	validCoordinates = 0;
	char 	userInput[16], c;
	int 	coordinate[2];

	while(!validCoordinates) {
		printf("Select 2 coordinates: first - row, second - column: \n");
    
    // while (((c = getchar()) != '\n') || (pos < 16)) {
    // 	scanf(" %c", &userInput[pos++]);
    //   c = getchar();
    // }

		// scanf("%s", userInput);

    for (pos = 0; pos < sizeof(userInput) && ((c=getchar()) != EOF && c != '\n'); pos++) {
      userInput[pos++] = c;
    }

  //   for (; pos >= 0; pos--) {
		// 	printf("MY_DBG: userInput[%d] = %c \n", pos, userInput[pos]);
		// 	printf("MY_DBG: (int)userInput[%d] = %d\n", pos, (int)userInput[pos]);
		// }

		// printf("MY_DBG: DIM %d, (char)DIM %c,  DIM - '0' %c\n", DIM, (char)DIM, DIM - '0');
		
		// for(pos = 0; pos < sizeof(userInput); pos++) {
    for (; pos >= 0; pos--) {
			
			printf("MY_DBG: [%d] isDigit %d, userInput[pos] < DIM %d , result %d\n",
												pos,		isDigit(userInput[pos]) , ((userInput[pos] - '0') < DIM),  (isDigit(userInput[pos]) && ((userInput[pos] - '0') < DIM)));
			if(isDigit(userInput[pos]) && ((userInput[pos] - '0') < DIM)) {
				if(countCoordinates < 2) {
					coordinate[countCoordinates] = userInput[pos] - '0';
				}
				countCoordinates++;
				printf("countCoordinates++  \n");
			}
		}
		if(countCoordinates == 2) {
			validCoordinates = 1;
			printf("validCoordinates = 1;  \n");
		}
		else {
			countCoordinates = 0;
		}
	}

	*(pBoard + coordinate[1]*DIM + coordinate[0]) = userSymbol;
	
	printf("End user round \n");
}

void botRound() {
	int row, column;
	
	for(row = 0; row < DIM; row++) {
		for(column = 0; column < DIM; column++) {
			if(board[row][column] == E_SYM) {
				board[row][column] = botSymbol;
				break;
			}
		}
	}
}

void drawCell(symbol_t anySymbol) {
	int row, column;
	
	for(column = 0; column < DIM; column++) {
		for(row = 0; row < DIM+2; row++) {
			if((row == (DIM+2)/2) && (column == DIM/2)) {
				printf("%c", anySymbol);
			}
			else if ((row == 0 || row == DIM+1) && (column != 0)) {
				printf("|");
			}
			else if (column == 0 || column == DIM-1) {
				printf("_");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void drawBoard() {
	int row, column;
	
	for(row = 0; row < DIM*(DIM + 1) + 1; row++) {
		for(column = 0; column < DIM; column++) {

			// if((row%(DIM+1) == 0) && (column%(DIM+1) == 0)) {
			// 	printf

			// }

			switch(board[row][column]) {
				case(X_SYM) : printf(" X ");
				break;

				case(O_SYM) : printf(" O ");
				break;

				default : 		printf("   ");
			}

			if(column == DIM - 1) {
				printf("\n");
			}
		}
	}
}

void printWinner(char botIsWinner) {
	printf("Winner is %s", botIsWinner ? "bot." : "user.");
}




int main() {
	int rounds;

	init_board(&board);

	drawCell(X_SYM);
	printf("\n");
	drawCell(O_SYM);
	printf("\n");
	drawCell(E_SYM);
	printf("\n");
	drawCell(X_SYM);
	// rounds = (selectSymbol() == X_SYM);

	// while(!isWinnerKnown(&board)) {
	// 	if(rounds%2) 	userRound(&board); 	// odd round
	// 	else 					botRound(); 	// even round
	// 	drawBoard();
	// 	rounds++;
	// }		

	// printWinner(rounds%2);
	return 0;
}
