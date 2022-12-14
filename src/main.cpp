// main.cpp

#include "Board.h"
#include "AI_Player.h"
#include "Player.h"
#include <iostream>
using namespace std;

char slots[6][7] =
{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',' ',
 ' ',' ',' ',' ',' ',' ',' ',' ',' ' };

/* takes two parameters: a Player object p for the player whose move is being processed, and a Board object b for the board on 
which the game is being played.'''*/  
void process_move(Player* p, Board* b) {
    cout << p->get_string() << "'s turn" << endl;
    int col;
    cin >> col;
    //int nxt = p -> next_move(b);
    b->add_checkers(p->get_checker(), col);
}

void process_move(AIPlayer* p, Board* b) {
    int col;
    col = p->next_move(*b);
    //int nxt = p -> next_move(b);
    b->add_checkers(p->get_checker(), col);


    if (b->check_win(p->get_checker())) {
        cout << "Congratulations!";
        exit(0);
    }
    else if (b->is_full(b)) {
        cout << endl << "It's a tie!";
        exit(0);
    }
    else {
        cout << endl;
        exit(0);
    }
}

/* Plays a game of Connect Four between the two specified players, and returns the Board object as it looks at the end of the game.
inputs: player1 and player2 are objects representing Connect Four players (objects of the Player class or a subclass of Player).
One player should use 'X' checkers and the other should use 'O' checkers.*/
/*Board* connect_four(Player* player1, Player* player2) {

    cout << "Welcome to Connect Four!" << endl;
    Board* board;
    board->draw_Board();
    
    while (true){
        if (process_move(player1, board)){
            return board;
        }

        if (process_move(player2, board)){
            return board;
        }
    }
}*/

int main (){

    

    Player* player1 = new Player('X');
    string tiebreak;
    int *head = new int;
    AIPlayer* player2 = new AIPlayer('O', tiebreak, *head);

    cout << "Welcome to Connect Four!" << endl;
    Board* board = new Board;
    board->draw_Board();

    while (true) {
        process_move(player1, board);



            process_move(player2, board);

     
    }

}
