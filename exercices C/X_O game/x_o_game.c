//----------------------------------------------
// X / O game with bot
//----------------------------------------------

#include <stdio.h>
#include <ctype.h>
#define DIM 3


typedef enum {X_SYM, O_SYM, E_SYM} symbol_t;

symbol_t user_symbol, bot_symbol;
symbol_t board[DIM][DIM];

void init_board() {
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

char is_winner_known() {
	return 0;
}

void user_turn() {
	int pos, get_row, get_column;
	char have_coordinates = 0;
	char user_in[3];

	while(!have_coordinates) {
		printf("Select 2 coordinates: first - row, second - column");
		scanf(%s, user_in);
		if((isdigit(user_in[0]) && (user_in[0] < (char)DIM)) 
			&&
			(isdigit(user_in[2]) && (user_in[2] < (char)DIM))
		{
			get_row = user_in[0];
			get_column = user_in[2];
			have_coordinates = 1;
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
	init_board();
	select_symbol();

	while(!is_winner_known()) {
		if(i%2) 	user_turn(); 	// odd
		else 			bot_turn() 		// even
		print_board();
		i++;
	}		

	print_winner(i%2);
}
