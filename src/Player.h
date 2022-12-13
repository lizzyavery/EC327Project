#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>

#include "Board.h"
using namespace std;

extern char slots[6][7];
//Connect 4 Player class header

class Player {

private:

//Two attributes to the player: checker is to represent the game piece and num_moves stores the number of moves

    char checker;
    int num_moves;

public:

    //Constructor of the Player
    Player (char piece);
    ~Player();

    //Get the name of the player
    string get_string();

    char get_checker();

    int get_moves();

    //Returns the piece of the opponent
    char opponent_checker();
    
    //Returns the column where the next move should go
    int next_move(Board* b);
};

#endif