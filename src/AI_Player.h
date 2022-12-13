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


class AIPlayer{
    // Data Members:
public:
    int lookahead;                    //
    char checker;
    string tiebreak;
    int scores [7];

    
    // Member Functions:\

    AIPlayer(char checker, string tiebreak, int lookahead);      // AI Player Constructor
    int max_score_column(vector<int> scores);                            //
    int scores_for(Board board);                                     //
    string toString();
};

#endif
