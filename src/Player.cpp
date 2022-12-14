#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(char piece) {
	
//These are the default values of the Player
	checker = piece;
	num_moves = 0;
}

Player::~Player() {
	cout << "The player destructor was called" << endl;
}

string Player::get_string() {

//Returns Player with the piece they are playing as
	
	string name = "Player ";
	name.push_back(checker);
	return name;
}

char Player::get_checker() {
      char c = checker;
	return c;
}

int Player::get_moves() {
	return num_moves;
}

char Player::opponent_checker() {

//Returns a character that represents the opponent player

	if (checker == 'X')
		return 'O';
	else
		return 'X';
}



int Player::next_move(Board* b) {
	
//Takes in the board as a parameter and returns the column where the player makes the next move
//Increment the move of the player
	this -> num_moves++;

	int column;
	while (true) {

		cout << "Enter a column number (0 1 2 3 4 5 6): " << endl;
		cin >> column;

//Will check if the input is not an int
		if (cin.fail()) {
			
			cout << "Not a valid input" << endl;
			continue;
		}

//Will see if the column can be added to
		if (b -> can_add_to(column) || (column >= 0 && column <= 6))
			return column;
		else
			cout << "Can't add to this column. Please try again." << endl;

	}
}