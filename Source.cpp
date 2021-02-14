/*

*IN thsu assigment we are going to see about the 
* Coonect 4 game.
* It seem liit bit tricky but lets do it .
* WE are going to play by two player X AND O
* The winner will be if it get 4 straight in vertcall, horizental and diagonal.
* LETS DO IT.
* 

*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<cmath>
using namespace std;
const int ROW = 6;
const int COLOMUN = 8;
char board[ROW][COLOMUN];
int n;
char players2 = 'X';
string names="Player 1";


	                   

void connectFourBoard() {
//	board[row][col];
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COLOMUN; col++) {
			board[row][col] = '-';
			}
		}
	
	

}
void printBoard() {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COLOMUN; col++) {
			cout << board[row][col];
		}
		cout << endl;
	}
}
void switchVariables() {
	if (players2=='X') {
		players2 = 'O';
	}


	else {
		players2 = 'X';
	}
}
void switchNames() {
	if (names == "Player 1") {
		names = "Player 2";
	}
	else {
		names = "Player 1";
	}
}
int WinningGame() {
	for (int row = 5; row > 0; row--) {
		for (int col = 0; col <= COLOMUN; col++) {
			//if (board[row][col] == board[row][col + 1])

			if (board[row][col] == players2 && board[row][col + 1] == players2 &&
				board[row][col + 1] == players2 && board[row][col + 2] == players2 &&
				board[row][col + 2] == players2 && board[row][col + 3]==players2)


			{
				return board[row][col];
			}
		}
	}
	for (int row = 5; row >0; row--) {
		for (int col = 0; col <= COLOMUN; col++) {
				if (board[row][col] == players2 && board[row-1][col] == players2 &&
						board[row-2][col] == players2 && board[row-3][col]==players2) {
						return board[row][col];
					}



			
		}
	}
	return 0;
}







void userinput(int &row,int &col) {
	int user;
	row = 5;
	while (true) {
		cout << "you must input between  1-8 of your colomun " << endl;
		cout << "Enter your input in from the colomun " << names << endl;
		cin >> user;
		if (cin.fail()) {
			cout << "EXIT" << endl;
			exit(0);
		}


		while (user <= 0 || user > 9) {
			cout << "WRONG INPUT--> Please follow the instruction " << endl;
			cout << "Your Input will be between 1-8 " << endl;
			cin >> user;
		}
		if (board[row][user - 1] == '-') {
			if (board[row + 1][user - 1] == '-' && row != 5) {
				while (board[row][user - 1] == '-' && row < 4) {
					row++;
				}
			}
			if (board[row + 1][user - 1] == '-') {
				board[row + 1][user - 1] = players2;
			}
			else {
				board[row][user - 1] = players2;
			}
			printBoard();

		}
		else {
			row--;
			board[row][user - 1] = players2;
			printBoard();
		}
		switchVariables();
		switchNames();

		if (WinningGame() == 'X') {
			printBoard();
			cout << "connected 4  " << names << "  Winnig the game " << endl;
			exit(0);
		}
		else if (WinningGame() == 'O') {
			printBoard();
			cout << "connected 4 " << names << "winnig the game " << endl;
			exit(0);
		}
		else if (WinningGame() == 0 && n == 48) {
			printBoard();
			cout << "The Game is Draw no one won " << "Game Over " << endl;
			exit(0);

		}

	}
	
		}
		
	
int main() {

	char board[ROW][COLOMUN];
	int row, col;


	connectFourBoard();

		

		printBoard();
		userinput(row, col);
	
	
}
	


	
