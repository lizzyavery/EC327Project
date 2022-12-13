
#include <string>
#include "Board.h"
#include "AI_Player.h"

using namespace std;

AIPlayer::AIPlayer(char in_checker, string in_tiebreak, int in_lookahead)
{
    num_moves = 0;
    checker = in_checker;
    tiebreak = in_tiebreak;
    lookahead = in_lookahead;
}

char AIPlayer::opponent_checker()
{
    return 'X';
}

string AIPlayer::toString()
{
    string player = "Player " + to_string(this->checker) + " (" + this->tiebreak + ", " + to_string(this->lookahead) + ")";
    return player;
}

int AIPlayer::max_score_column(vector<int> scores)
{
    vector<int> max_scores;
    for (int x = 0; x < scores.size(); x++)
    {
        if (scores[x] == *max_element(scores.begin(), scores.end()))
        {
            max_scores.push_back(x);
        }
    }

    if (this->tiebreak == "LEFT")
    {
        return max_scores[0];
    }
    else if (this->tiebreak == "RIGHT")
    {
        return max_scores[max_scores.size() - 1];
    }
    else
    {
        srand(time(NULL));
        return max_scores[rand() % max_scores.size()];
    }
}

vector<int> AIPlayer::scores_for(Board board)
{
    vector<int> scores(board.get_width(), 50);

    for (int col = 0; col < board.get_width(); col++)
    {
        if (board.can_add_to(col) == false)
        {
            scores[col] = -1;
        }
        else if (board.is_win_for(this->opponent_checker(), col) == true)
        {
            scores[col] = 0;
        }
        else if (board.is_win_for(this->checker, col) == true)
        {
            scores[col] = 100;
        }
        else if (this->lookahead == 0)
        {
            scores[col] = 50;
        }
        else
        {
            board.add_checker(this->checker, col);
            AIPlayer opp(this->opponent_checker(), this->tiebreak, (this->lookahead - 1));
            vector<int> opp_score = opp.scores_for(board);
            if (*max_element(opp_score.begin(), opp_score.end()) == 0)
            {
                scores[col] = 100;
            }
            else if (*max_element(opp_score.begin(), opp_score.end()) == 100)
            {
                scores[col] = 0;
            }
            else if (*max_element(opp_score.begin(), opp_score.end()) == 50)
            {
                scores[col] = 50;
            }

        }
    }

    return scores;
}

int AIPlayer::next_move(Board board)
{
    this->num_moves++;
    vector<int> scores = this->scores_for(board);
    return this->max_score_column(scores);
}