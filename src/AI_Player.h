// AI_Player.h

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

extern char slots[6][7];

class AIPlayer{
    // Data Members:
public:
    int num_moves;
    int lookahead;                    //
    char checker;
    string tiebreak;
    int scores [7];

    
    // Member Functions:\
    
    AIPlayer(char checker, string tiebreak, int lookahead);      // AI Player Constructor
    int max_score_column(vector<int> scores);                          //
    vector<int> scores_for(Board board);                                     //
    string toString();
    char opponent_checker();
    int next_move(Board board);
    char get_checker();
};

#endif
