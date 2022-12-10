// Board Class:

#include "Board.h"
#include <assert.h>
#include <cstring>
#include <iostream>
using namespace std;

// Default Constructor
Board :: Board() {
    row = 6;
    width = 6;
    column = 7;
    height = 7;
}

Board :: Board(int in_width, int in_height){
    row = width;
    column = height;
    width = in_width;
    height = in_height;
}

// Destructor
Board :: ~Board(){
    cout << "The destructor was called" << endl;
}

// FUNCTION TO DISPLAY THE CONNECT 4 BOARD 
void Board :: draw_Board() {

    // number of slots
    char slots [row][column] = {' '};

    cout << endl;
    // Display header of the board with column numbers
    for (int i = 1; i <= column; i++){
        cout << "   " << i <<  "   ";
    }
    cout << endl;
    cout << string(50,'-') << endl;

    // add one row of slots at a time
    for (int i = 0; i < row; i++){
        cout << "|  ";                                   // one vertical bar at the start
        for (int j = 0; j < column; j++){
            cout << slots[row][column]  << "   |  ";
        }
        cout << endl;
        cout << string(50,'-') << endl;
    }
}

// FUNCTION TO ADD A CHECKER TO THE BOARD
void Board :: add_checker(char checker, int column) {
    
    assert(checker == 'X' || checker == 'O');
    assert(0 <= column < board.column);

    
    row = 0
    while ((slots[row][col] == ' ') && (row < height-1) && (slots[row+1][col] == ' ')){
       row += 1 
    }

    slots[row][col] = checker;
        

}

// FUNCTION TO CHECK IF THERE IS A DIAGNOGNAL WIN (DOWN)
bool Board :: is_down_diagonal_win(char checker){
    return false;
}

// FUNCTION TO CHECK IF THERE IS A DIAGNOGNAL WIN (UP)
bool Board :: is_up_diagonal_win(char checker){
    return false;
}

// FUNCTION TO CHECK IF THERE IS A HORIZONTAL WIN
bool Board :: is_horizontal_win(char checker){
    return false;
}

// FUNCTION TO CHECK IF THERE IS A VERTICAL WIN
bool Board :: is_vertical_win(char checker){
    return false;
}


// Test and Debug
int main(){
    Board board;
    board.draw_Board();
    return 0;
}
