// Board.h
#ifndef BOARD_H
#define BOARD_H

class Board{
    public:
        // Public Members
        int column;
        int height;
        int row;
        int slots;
    
        // Functions:
        Board();                                        // default constructor
        ~Board();                                       // deconstructor
        void draw_Board();                              // creates a string representation of the Board
        int get_Value(int column);                      // gets slot number to put checker
        void add_checker(char checker, int column);     // adds checker to the board
        

};

#endif
