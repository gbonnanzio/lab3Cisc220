/*
 * playGame.cpp
 *
 *  Created on: Mar 6, 2020
 *      Author: gbonn
 */
//adding comment
#include <iostream>
#include <time.h>
#include <stdlib.h>
void startGame(GameBoard *game);
void playGame(bool fp1, bool fp2, GameBoard *game, bool whoplaysfirstflag);


int main() {
	srand (time(NULL));int size = 0;
	getSize(size); // gets the size for the game board. Note we only do this once for this game.
	GameBoard *game = new GameBoard;// places a gameBoard struct object on the heap.
	game->size = size;//sets the gameboard's size
	game->totalct = 4;// the 4 middle squares are taken
	cout << "Size is " << game->size << endl;
	makeBoard(game,0,true);
	printBoard(game, 0);// for testing purposes
	startGame(game);
}
void playGame(bool fp1, bool fp2, GameBoard *game, bool whoplaysfirstflag) {
	bool s1 = true;
	bool s2 = true;
	if (fp1 && fp2 && (s1 || s2)) {
		7
		if (whoplaysfirstflag) {
			game->p = 'X';
			s1 = placepieceperson(game);
			printBoard(game, 0);
			game->p = 'O';
			s2 = placepieceperson(game);
			printBoard(game, 0);
		} else {
			game->p = 'O';
			s1 = placepieceperson(game);
			printBoard(game, 0);
			game->p = 'X';
			s2 = placepieceperson(game);
			printBoard(game, 0);
		}
	} else if (fp1 == false && fp2 == false && (s1 || s2)) {
		game->p = 'X';
		s1 = compplacepiece(game);
		printBoard(game, 0);
		game->p = 'O';
		s2 = compplacepiece(game);
		printBoard(game, 0);
	} else {
		if (whoplaysfirstflag) {
			game->p = 'X';
			s1 = placepieceperson(game);
			printBoard(game, 0);
			game->p = 'O';
			s2 = compplacepiece(game);
			printBoard(game, 0);
		} else {
			game->p = 'X';
			s1 = compplacepiece(game);
			printBoard(game, 0);
			game->p = 'O';
			s2 = placepieceperson(game);
			printBoard(game, 0);
		}
	}
	if (s1 == false && s2 == false
			|| game->totalct == game->size * game->size) {
		cout << "Game over" << endl;
		printBoard(game, 0);
		return;
	}
	playGame(fp1, fp2, game, whoplaysfirstflag);
}
void startGame(GameBoard *game) {
	cout << "How many players? (0,1, or 2)" << endl;
	int numplayers;
	8
	cin >> numplayers;
	if (numplayers == 0) {
		playGame(false, false, game, true);
	} else if (numplayers == 1) {
		bool whoplaysfirstflag;
		rand() % 2 == 0 ? whoplaysfirstflag = true : whoplaysfirstflag = false;
		playGame(true, false, game, whoplaysfirstflag);
	} else
		playGame(true, true, game, true);
	char w = ckwin(game);
	if (w != 'T') {
		cout << w << " WON!!!! " << endl;
	} else {
		cout << "Tie game. " << endl;
	}
	string s;
	cout << "Play again? (Y or N)" << endl;
	cin >> s;
	if (s == "Y") {
		game->totalct = 4;
		makeBoard(game, 0, false);
		cout << "STARTING OVER" << endl;
		printBoard(game, 0);
		startGame(game);
	} else {
		cout << "THANKS FOR PLAYING!" << endl;
	}
}
