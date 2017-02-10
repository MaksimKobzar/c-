//----------------------------------------------
// X / O game with bot
//----------------------------------------------

#include <stdio.h>
#include <ctype.h>
#define DIM 3


typedef enum {X_SYM, O_SYM, E_SYM} symbol_t;

symbol_t userSymbol, botSymbol;
symbol_t board[DIM][DIM];

void init_board(symbol_t *pBoard) {
	int shift;
	for(shift = 0; shift < DIM*DIM; shift++) {
		*(pBoard + shift) = E_SYM;
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

char isWinnerKnown(symbol_t *pBoard) {
	int pos;
	for(pos = 0; pos < DIM*DIM; pos++) {
		if((*(pBoard + pos) != E_SYM) && (
			((*(pBoard + pos) == *(pBoard + pos + 1) 				== *(pBoard + pos + 2)) 					&& (pos%DIM == 0)) || // {0, 1, 2}, {4, 5, 6} ...  
			((*(pBoard + pos) == *(pBoard + pos + DIM) 			== *(pBoard + pos + 2* DIM)) 			&& (pos < DIM) 	 ) || // {0, 3, 6}, {1, 4, 7} ...
			((*(pBoard + pos) == *(pBoard + pos + DIM + 1) 	== *(pBoard + pos + 2*(DIM + 1))) && (pos == 0) 	 ) || // {0, 4, 8}
			((*(pBoard + pos) == *(pBoard + pos + DIM - 1) 	== *(pBoard + pos + 2*(DIM - 1))) && (pos == DIM)  )  	// {2, 4, 6}
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
	int 	coordinate[2]; // 0 - Row 1 - Column

	while(!validCoordinates) {
		printf("Select 2 coordinates: first - column, second - row: \n");
    
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
			}
		}
		validCoordinates = countCoordinates == 2;
	}
	printf("MY_DBG: Get 2 valid coordinates: [%d: %d] \n");

	board[coordinate[0]][coordinate[1]] = userSymbol;
	
	printf("End user round \n");
}

void botRound() {
	int row, column;
	
	for(column = 0; column < DIM; column++) {
		for(row = 0; row < DIM; row++) {
			if(board[column][row] == E_SYM) {
				board[column][row] = botSymbol;
				return;
			}
		}
	}
}

void drawColumn(char boardColumnNum) {
	int row, column;
	char isFirstColumn = boardColumnNum == 0;

	if (isFirstColumn) {
		for(row = 0; row < DIM*(3+1) + 1; row++) {
			if ((row%(DIM+1)) == 2) {
				printf("%d",(row - 2)/(DIM+1));
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	for(column = 0; column < DIM + isFirstColumn; column++) {
		for(row = 0; row < DIM*(3+1) + 1; row++) {
			if((row%(DIM+1) == 2) && (column%(DIM + 1) == (1 + isFirstColumn))) {
				printf("%c", board[boardColumnNum][(row - 2)/(DIM+1)] == X_SYM ? 'X' : board[boardColumnNum][(row - 2)/(DIM+1)] == O_SYM ? 'O' : ' ');
			}
			else if ((row%(DIM+1) == 0) && ((column != 0) || ((column == 0) && !isFirstColumn))) {
				printf("|");
			}
			else if (((column == 0) && isFirstColumn) || (column == (DIM + isFirstColumn - 1))) {
				printf("_");
			}
			else {
				printf(" ");
			}
		}
		if(column%(DIM + 1) == (1 + isFirstColumn)) {
			printf(" %d ", boardColumnNum);
		}
		printf("\n", boardColumnNum);
	}
}

void drawBoard() {
	int column = 0;
	while(column < DIM){
		drawColumn(column++);
	}
}

void printWinner(char botIsWinner) {
	printf("Winner is %s\n", botIsWinner ? "bot." : "user.");
}




int main() {
	int rounds;
	int i, j;

	init_board(&board);

	// board[0][0] = X_SYM;
	// board[1][2] = X_SYM;
	// board[0][1] = O_SYM;
	// board[0][2] = O_SYM;
	// board[2][0] = O_SYM;
	// board[2][1] = X_SYM;
	// board[2][2] = O_SYM;

	// for(i = 0; i < DIM; i++) {
	// 	for(j = 0; j < DIM; j++) {
	// 		printf(" %c ", board[i][j] == X_SYM ? 'X' : board[i][j] == O_SYM ? 'O' : ' ');
	// 	}
	// 	printf("\n");
	// }



	// for(i = 0; i < DIM; i++){
	// 	drawColumn(i);
	// }
	printf("\n");
	rounds = (selectSymbol() == X_SYM);

	while(!isWinnerKnown(&board)) {
		if(rounds%2) 	userRound(&board); 	// odd round
		else 					botRound(); 	// even round

		printf("-----------------------------------------------------\n");
		for(i = 0; i < DIM; i++) {
			for(j = 0; j < DIM; j++) {
				printf(" %c ", board[i][j] == X_SYM ? 'X' : board[i][j] == O_SYM ? 'O' : ('0' + (i*DIM +j)));
			}
			printf("\n");
		}
		printf("-----------------------------------------------------\n");

		drawBoard();
		rounds++;
	}		

	printWinner(rounds%2);
	return 0;
}
