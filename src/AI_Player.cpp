// AI_Player.cpp

#include "AI_Player.h"
#include "Board.h"
#include <assert.h>
#include <iostream>
using namespace std;


AIPlayer :: AIPlayer(in_checker, in_tiebreak, in_lookahead){
    assert(checker == 'X' or checker == 'O');
    assert(tiebreak == 'LEFT' or tiebreak == 'RIGHT' or tiebreak == 'RANDOM');
    assert(lookahead >= 0);

    checker = in_checker;
    tiebreak = in_tiebreak;
    lookahead = in_lookahead;
}

/* takes a list scores containing a score for each column of the board, and that returns the index of the column with the maximum score. 
If one or more columns are tied for the maximum score, the method should apply the called AIPlayer‘s tiebreaking strategy to break the tie.*/
int AIPlayer :: max_score_column(int scores){

    int max_scores[] = {0};
    int length = sizeof(max_scores)/sizeof(max_scores[0]);      //length calculation
    for (int x = 1; x <= length; x++){
        if scores[x] == max(scores){
            max_scores += [x];
        }
    }
        
    if (tiebreak == 'LEFT'){
        return max_scores[0];
    } else if (tiebreak == 'RIGHT'){
        return max_scores[-1];
    } else {
    }
}

// takes a Board object board and determines the called AIPlayer's scores for the columns in board. 
AIPlayer :: scores_for(Board board){

    scores = [50] * board.row
    for col in range(board.row){
        if board.can_add_to(col) == False:
            scores[col] = -1
        else if board.is_win_for(self.opponent_checker()):
            scores[col] = 0
        else if board.is_win_for(self.checker):
            scores[col] = 100
        else if self.lookahead == 0:
                scores[col] = 50
        else
            board.add_checker(self.checker, col)
            opp = AIPlayer(self.opponent_checker(), self.tiebreak, (self.lookahead -1))
            opp_score = opp.scores_for(board)
            if max(opp_score) == 0:
                scores[col] = 100
            else if max(opp_score) == 100:
                scores[col] = 0
            else if max(opp_score) == 50:
                scores[col] = 50
                
            board.remove_checker(col)

    return scores
    }
}

AIPlayer :: next_move(Board board){
    self.num_moves += 1
    scores = self.scores_for(board)
    return self.max_score_column(scores)
}
        
