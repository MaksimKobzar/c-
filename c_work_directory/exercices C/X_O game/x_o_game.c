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
	char userChoice, c;

	printf("----------------------------------------------------------------------\n");
	printf(" \tNew game starts!  \n");
	printf(" \tSelect what symbol do you want to play?  \n");
	printf(" \tEnter 'X' or 'O'  ! Player with 'X' moves first.  \n");
	printf(" \t(any character except 'X', will be regarded as 'O')  \n");
	printf("----------------------------------------------------------------------\n");
	scanf("%c", &userChoice);
	while ((c=getchar()) != EOF && c != '\n') {}

	if(userChoice == 'X' || userChoice == 'x') {
		userSymbol 	= X_SYM;
		botSymbol 	= O_SYM;
	}
	else {
		userSymbol = O_SYM;
		botSymbol = X_SYM;
	}
	return userSymbol;
}

char isWinnerKnown(symbol_t *pBoard) {
	int pos;

	for(pos = 0; pos < DIM*DIM; pos++) {
		if( (*(pBoard + pos) != E_SYM) && (
			( 
				(*(pBoard + pos) == *(pBoard + pos + 1)) 				&& (*(pBoard + pos + 1)	== *(pBoard + pos + 2)) 								&& (pos%DIM == 0)
			) || // {0, 1, 2}, {4, 5, 6} ...  
			(
				(*(pBoard + pos) == *(pBoard + pos + DIM)) 			&& (*(pBoard + pos + DIM) == *(pBoard + pos + 2* DIM)) 					&& (pos < DIM) 	 
			) || // {0, 3, 6}, {1, 4, 7} ...
			(
				(*(pBoard + pos) == *(pBoard + pos + DIM + 1)) 	&& (*(pBoard + pos + DIM + 1) == *(pBoard + pos + 2*(DIM + 1))) && (pos == 0) 	 
			) || // {0, 4, 8}
			(
				(*(pBoard + pos) == *(pBoard + pos + DIM - 1)) 	&& (*(pBoard + pos + DIM - 1) == *(pBoard + pos + 2*(DIM - 1))) && (pos == DIM - 1)  
			)  	// {2, 4, 6}
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
	int 	pos, pos1, countCoordinates = 0;
	char 	validCoordinates = 0;
	char 	userInput[16], c;
	int 	coordinate[2]; // 0 - Row 1 - Column

	printf("Select 2 coordinates: first - column, second - row: \n");
	while(!validCoordinates) {
    for (pos = 0; pos < sizeof(userInput) && ((c=getchar()) != EOF && c != '\n'); pos++) {
      userInput[pos++] = c;
    }

    for (; pos >= 0; pos--) {
			if(isDigit(userInput[pos])) {
				if(countCoordinates < 2) {
					coordinate[countCoordinates] = userInput[pos] - '0';
				}
				countCoordinates++;
			}
		}
		if(countCoordinates != 2) {
			printf("You enter more than 2 coordinates. Please try again.\n");
		}
		else if((coordinate[0] >= DIM) || (coordinate[1] >= DIM)) {
			printf("You enter invalid coordinates %d column %d row. Both coordinates should be less than %d. Please try another coordinates.\n",
																coordinate[0], coordinate[1], DIM);
		}
		else if(board[coordinate[0]][coordinate[1]] != E_SYM) {
			printf("Cell with coordinates %d column %d row has already taken. Please try another coordinates.\n", coordinate[0], coordinate[1]);
		}
		else {
			validCoordinates = 1;
		}
		countCoordinates = 0;
		for(pos = 0; pos < 16; pos++) {
			userInput[pos] = ' ';
		}
	}

	board[coordinate[0]][coordinate[1]] = userSymbol;
	printf("End user round. \n");
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
	printf("End computer round. \n");
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
	printf("\n");
	while(column < DIM){
		drawColumn(column++);
	}
}

void printWinner(char botIsWinner) {
	printf("%s is winner\n", botIsWinner ? "Computer." : "User.");
}

char continueGame() {
	char userChoice, c;

	printf("Do you want play next game? [Y/N] \n");
	scanf("%c", &userChoice);
	while ((c=getchar()) != EOF && c != '\n') {}

	if(userChoice == 'Y' || userChoice == 'y') {
		return 1;
	}
	return 0;
}

int main() {
	int rounds;
	char playGame = 1;

	while(playGame) {
		init_board(&board);

		rounds = (selectSymbol() == X_SYM);
		printf("\n");
		drawBoard();

		while(!isWinnerKnown(&board)) {
			if(rounds++%2) 	userRound(&board); 	// odd round
			else 						botRound(); 				// even round
			drawBoard();
		}		

		printWinner(rounds%2);
		playGame = continueGame();
	}
	return 0;
}
