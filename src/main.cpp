// main.cpp

#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;

/* takes two parameters: a Player object p for the player whose move is being processed, and a Board object b for the board on 
which the game is being played.'''*/  
bool process_move(Player p, Board b){
    cout << p.get_string() << "'s turn" << endl;
    int nxt = p.next_move(b);
    b.add_checker(p.checker, nxt);
    b.draw_Board;

    if (b.is_win_for(p.checker)){
        cout << endl << p.get_string() << " wins in " << p.num_moves << " moves " << endl;
        cout << "Congratulations!";
        return true;
    } else if (is_full(b)){
        cout << endl << "It's a tie!";
        return true;
    } else {
        cout << endl;
        return false;
    }
}

/* Plays a game of Connect Four between the two specified players, and returns the Board object as it looks at the end of the game.
inputs: player1 and player2 are objects representing Connect Four players (objects of the Player class or a subclass of Player).
One player should use 'X' checkers and the other should use 'O' checkers.*/
Board connect_four(Player player1, Player player2){
    player1.num_moves = 0;
    player2.num_moves = 0;
    
    cout << "Welcome to Connect Four!" << endl;
    Board board;
    board.draw_Board();
    
    while (true){
        if (process_move(player1, board)){
            return board;
        }

        if (process_move(player2, board)){
            return board;
        }
    }
}

int main (){
    Player player1;
    Player player2;
    connect_four(player1, player2);
}
