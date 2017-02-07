//----------------------------------------------
// X / O game with bot
//----------------------------------------------

#include <stdio.h>
#include <ctype.h>
#define DIM 3


typedef enum {X_SYM, O_SYM, E_SYM} symbol_t;

symbol_t user_symbol, bot_symbol;
symbol_t board[DIM][DIM];

void init_board(char *board) {
	int i;
	for(i = 0; i < DIM*DIM; i++) {
		*(board + i) = E_SYM;
	}
}

void select_symbol() {
	char user_choice;
	printf("----------------------------------------------------------------\n");
	printf(" 				Select what you want to play?  \n");
	printf(" 				Enter 'X' or 'O'  !  \n");
	printf(" 				Player with 'X' moves first.  \n");
	printf(" 				(any character except 'X', will be regarded as 'O')  \n");
	printf("----------------------------------------------------------------\n");
	scanf(%s, user_choice);
	if(user_choice == 'X' || user_choice == 'x') {
		user_symbol = X_SYM;
		bot_symbol = O_SYM;
	}
	else {
		user_symbol = O_SYM;
		bot_symbol = X_SYM;
	}

}

char is_winner_known(char *board) {
	int i;
	for(i = 0; i < DIM*DIM; i++) {
		if( (*(board + i) != E_SYM) && (
			((*(board + i) == *(board + i + 1) == *(board + i + 2)) 								&& (i%DIM == 0)) || // {0, 1, 2}, {4, 5, 6} ...  
			((*(board + i) == *(board + i + DIM) == *(board + i + 2*DIM)) 					&& (i < DIM) 	 ) || // {0, 3, 6}, {1, 4, 7} ...
			((*(board + i) == *(board + i + DIM + 1) == *(board + i + 2*(DIM + 1))) && (i == 0) 	 ) || // {0, 4, 8}
			((*(board + i) == *(board + i + DIM - 1) == *(board + i + 2*(DIM - 1))) && (i == DIM)  )  	// {2, 4, 6}
		))
			return 1;
	}
	return 0;
}

char isdigit(char some) {
	if(some >= '0' && some <= '9')
		return 1;
	return 0;
}

void user_turn() {
	int pos, count_coordinates;
	char valid_coordinates;
	char user_in[16];
	int coordinate[2];

	while(!valid_coordinates) {
		printf("Select 2 coordinates: first - row, second - column");
		gets(user_in);

		for(pos = 0; pos < 10; pos++) {
			if(isdigit(user_in[pos]) && (user_in[0] < (char)DIM)) {
				if(count_coordinates < 2) {
					coordinate[count_coordinates] = user_in[pos];
				}
				count_coordinates++;
			}
		}
		if(count_coordinates == 2) {
			valid_coordinates = 1;
		}
		else {
			count_coordinates = 0;
		}
	}
}

void bot_turn() {
	int row, column;
	
	for(row = 0; row < DIM; row++) {
		for(column = 0; column < DIM; column++) {
			if(board[row][column] == E_SYM) {
				board[row][column] = bot_symbol;
				return 0;
			}
		}
	}
}

void print_winner( {
	int row, column;
	
	for(row = 0; row < DIM; row++) {
		for(column = 0; column < DIM; column++) {
			switch(board[row][column]) {
				case(X_SYM) : printf(" X ");
				break;

				case(X_SYM) : printf(" O ");
				break;

				default : 		printf("   ");
			}

			if(column == DIM - 1) {
				printf("\n");
			}
		}
	}
}

void print_winner(char bot_is_winner) {
	printf("Winner is %s", bot_is_winner ? "bot." : "user.");
}




int main() {
	int i = (user_symbol == X_SYM);
	init_board(board);
	select_symbol();

	while(!is_winner_known(board)) {
		if(i%2) 	user_turn(); 	// odd
		else 			bot_turn() 		// even
		print_board();
		i++;
	}		

	print_winner(i%2);
}
