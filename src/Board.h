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
        int get_width();
        void draw_Board();                              // creates a string representation of the Board
        int get_Value(int column);                      // gets slot number to put checker
        void reset();                                   // resets board
        bool can_add_to(int column);                    // returns true if column can be added
        void add_checkers(int columns);                 // alternates between the 'X' and 'O'
        void add_checker(char checker, int column);     // adds checker to the board
        bool check_win(char checker);
        void win(bool wincon);
        bool is_full(Board* board);                      // returns True if the called Board object is completely full of checkers
        int get_column();

};

#endif
