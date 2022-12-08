// Board Class:

#include "Board.h"
#include <assert.h>
#include <cstring>
#include <iostream>
using namespace std;

// In a 6x7 board there are 42 slots ... this array represent them
char input[43];
// Default Constructor
Board :: Board() {
    row = 6;
    column = 7;
}

// Destructor
Board :: ~Board(){
    cout << "The destructor was called" << endl;
}

// FUNCTION TO DISPLAY THE CONNECT 4 BOARD 
void Board :: draw_Board() {

    // Display header of the board with column numbers
    cout << endl << "    1   " << "    2   " << "    3   " << "    4   " << "    5   " << "    6   " << "    7   " << endl;

    // In a 6x7 board there are 42 slots ... (input array already declared)
    int slots = 42;
    
    // i = number of spaces going down (<= 23 because doing divisible by 4)
    for(int i = 0 ; i<= 23 ; i++) {
        // if i is divisiable by 4 add a dashed line to start next row
        if(i % 4 == 0){
            cout << string(57,'-');
        } else {
            if((i - 2) % 4 == 0) {
                slots = 42 - (0.25*i + 0.5)*6 - ((0.25*i + 0.5)-1);
                for(int i = 0 ; i<=6 ; i++){
                    cout << "|" << "    " << input[slots] << "   ";
                    slots++;
                }
                cout << "|";
            } else {
                for(int i = 0 ; i<=6 ; i++){
                   cout << "|" << string(7,' '); 
                }
                cout << "|";
            }
        }
        cout << endl;
    }
    cout << string(57,'-') << endl;
}

// FUNCTION TO RETURN THE VALUE IN INPUT ARRAY FROM COLUMN INPUT
int Board :: get_Value(int column){
    // if column entered is too height - return 0 (will produce errow message)
    if(column > 7)
        return 0;
    
    // variable to hold the slot number
    int slot_num;

    // Iterate through the rows (bottom to top) to figure out where there is an opening
    for(int i = 0 ; i<= 6 ; i++)
    {
        // if the row is empty break to return that slot number, else go to next row
        if(input[column+7*i] == ' ')
        {
            slot_num = column+7*i;
            break;
        }
    }

    // if column is full/ no open slots - return 0 (will produce error message)
    if (slot_num > 42){
        return 0;
    }
    
    // return slot number found
    return slot_num;
}

// FUNCTION TO ADD A CHECKER TO THE BOARD
void Board :: add_checker(char checker, int column) {
    
    cout << endl << "where would you like to play (enter column number)" << endl;
    
    // variable to figure out what slot the checker will go
    int col;

    while(true)
    {
        cin >> col;
        // call GetValue to determine which slot it goes in
        col = get_Value(col);
        // If not 0 (aka error) put checker in slot
        if( col != 0 )
        {
            input[col] = checker;
            return;
        }
        else
            // assert that the column entered is valid
            cout << "ERROR" << endl;
    }

}

// Test and Debug
int main(){
    Board board;
    board.draw_Board();
    return 0;
}
