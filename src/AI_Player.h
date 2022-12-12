// AI_Player.h

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Board.h"
#include <cstring>


class AIPlayer{
    // Data Members:
    int lookahead;                    //
    char checker;
    string tiebreak;
    int scores [7];

    
    // Member Functions:
    AIPlayer(char checker, string tiebreak, int lookahead);      // AI Player Constructor
    int max_score_column(int scores);                            // 
    scores_for(Board board);                                     // 

};

#endif
