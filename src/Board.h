// Board.h
#ifndef BOARD_H
#define BOARD_H

class Board{
    public:
        // Public Members
        int column;
        int row;
        char checker;
    
        // Functions:
        Board();                                        // default constructor
        ~Board();                                       // destructor
        void draw_Board();                              // creates a string representation of the Board
        int get_Value(int column);                      // gets slot number to put checker
        void add_checker(char checker, int column);     // adds checker to the board
        bool is_down_diagonal_win(char checker);        // check if diagonal down win
        bool is_up_diagonal_win (char checker);         // check if diagonal up win
        bool is_vertical_win (char checker);            // check if vertical win
        bool is_horizontal_win (char checker);          // check if horiztonal win

};

#endif
