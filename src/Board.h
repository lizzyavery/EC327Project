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
        int get_Value(int column);   // gets slot number to put checker
        void reset(); //resets board
        bool can_add_to(int column); // returns true if column can be added
        void add_checkers(int columns);                  // alternates between the 'X' and 'O'
        void add_checker(char checker, int column);     // adds checker to the board
        bool check_win(char checker);
        void win(bool wincon);
        //bool is_down_diagonal_win(char checker);        // check if diagonal down win
        //bool is_up_diagonal_win (char checker);         // check if diagonal up win
        //bool is_vertical_win (char checker);            // check if vertical win
        //bool is_horizontal_win (char checker);          // check if horiztonal win

};

#endif
