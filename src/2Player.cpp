// Board Class:

#include "2Player.h"
#include <assert.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// number of slots
char slots[6][7] =
{' ',' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',' '};
// Default Constructor
Board :: Board() {
	row = 6;
	column = 7;
	checker =  'X';

	cout << "Board of size " << column << ' ' << row << " was generated" << endl;
}


// Destructor
Board :: ~Board(){
	cout << "The destructor was called" << endl;
}

// FUNCTION TO DISPLAY THE CONNECT 4 BOARD
void Board :: draw_Board() {

	cout << endl;
	// Display header of the board with column numbers
	for (int i = 1; i <= column; i++) {
		cout << "   " << i <<  "  ";
	}
	cout << endl;
	cout << string(45,'-') << endl;

	// add one row of slots at a time
	for (int i = 0; i < row; i++) {
		cout << "|  ";                                               // one vertical bar at the start
		for (int j = 0; j < column; j++) {
			cout << slots[i][j]  << "  |  ";
		}
		cout << endl;
		cout << string(45,'-') << endl;
	}
}


// FUNCTION TO ADD A CHECKER TO THE BOARD
void Board :: add_checker(char checker, int column) {

	assert(checker == 'X' || checker == 'O');
	assert(0 <= column < 7);

	//int row_num = 0;
	for (int i = row - 1; i >= 0; i--)
	{
		if(slots[i][column-1] == ' ')
		{
			slots[i][column-1] = checker;
			break;
		}
	}

	//slots[row][column] = checker;
	// redraw board with added checker:
	draw_Board();
	check_win(checker);
	win(check_win(checker));
}

void Board::reset()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; i < this->column; i++)
		{
			slots[i][j] = ' ';
		}
	}
}

void Board::add_checkers(int columns)
{
	bool boolval = can_add_to(columns);
	if (boolval) {
		if (this->checker == 'X')
		{
			Board::add_checker(checker, columns);
			this->checker = 'O';
		} else if(this->checker = 'O')
		{
			Board::add_checker(checker, columns);
			this->checker = 'X';
		}
	} else if (!boolval) {
		cout << "can't add" << endl;
	}
}


bool Board::can_add_to(int columns)
{
	bool returnval = false;
	for(int i = (this->row) - 1; i > 0; i--)
	{
		if (slots[i][columns - 1] == ' ')
		{
			returnval = true;
			break;
		}
	}
	//cout << returnval << "bool" << endl;
	return returnval;
}


bool Board::check_win(char checker)
{
	char checkercheck = checker;
	bool boolval = false;
	for( int i = 6; i >= 1; --i )
	{

		for( int ix = 7; ix >= 1; --ix )
		{

			if( slots[i][ix] == checkercheck   &&
			    slots[i-1][ix-1] == checkercheck &&
			    slots[i-2][ix-2] == checkercheck && //diagonal
			    slots[i-3][ix-3] == checkercheck )
			{
				boolval = true;
			}


			if( slots[i][ix] == checkercheck   &&
			    slots[i][ix-1] == checkercheck && //horizonjtal
			    slots[i][ix-2] == checkercheck &&
			    slots[i][ix-3] == checkercheck )
			{
				boolval = true;
			}

			if( slots[i][ix] == checkercheck   &&
			    slots[i-1][ix] == checkercheck &&
			    slots[i-2][ix] == checkercheck && //vertical
			    slots[i-3][ix] == checkercheck )
			{
				boolval = true;
			}

			if( slots[i][ix] == checkercheck     &&
			    slots[i-1][ix+1] == checkercheck &&
			    slots[i-2][ix+2] == checkercheck && //diagonal
			    slots[i-3][ix+3] == checkercheck )
			{
				boolval = true;
			}

			if ( slots[i][ix] == checkercheck   &&
			     slots[i][ix+1] == checkercheck &&
			     slots[i][ix+2] == checkercheck &&
			     slots[i][ix+3] == checkercheck )
			{
				boolval = true;
			}
		}

	}
	return boolval;
}

void Board::win(bool wincon)
{
	if(wincon)
	{
		cout << "Connect Four! Game Over" << endl;
		exit(0);
	}
}



// Test and Debug
int main(){
	int a;
	Board board;
	board.draw_Board();
	while(true)
	{
		cout << "select a columns: ";
		cin >> a;
		board.add_checkers(a);
	}
	return 0;
}
