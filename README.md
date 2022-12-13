# EC327Project 2022.
Final Project for EC327 - Connect 4 Game

Team Unorganised
----------------
Elizabeth Avery: averye@bu.edu
JiaLin Sui: suijs@bu.edu
Stefan Meier: stefanjm@bu.edu


Overview
----------

A classic game of Connect Four written in C++.
Played with a user and the computer AI.

Text-based UI and with ASCII components to
represent the board and the Connect Four dots.


***************Important***************

***************************************
**Please compile only the 2Player.cpp**
***if you want something functional***
***************************************


Build Instructions
--------

Just do:

g++ 2Player.cpp

.a/.out

in order to build the game.

Below is our original method to compile the game:

Please use the provided makefile to link all the files together using
your chosen compiler.

Or alternatively link the files manually:

If you have g++:

Due to complications, we were unable to finish th AIPlayer class. Therefore, we built the game as a two player game.

Demonstration
------------

Please find the YouTube link below for a demo:
↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓

https://youtu.be/uUTxFFQAhp8     //This is our working demo.

https://youtu.be/ItgK1tPu5DE     //This is our demo with the AI that does not work well.

Instructions and Interface
-------

In this version of Connect Four the 'checkers' are represented by 'X' and 'O'
respectively and it juggles between the two as each move gets played.\
After each move the board will update the new placement of the checker.

The board can be set to whatever dimensions but the default is (6,7)
i.e. 7 columns and 6 rows
Common standard variations of Connect Four are 5x4, 6x5, 8x7, 9x7, 10x7, 8x8.

To send an instruction to drop a 'checker' ('X' or 'O') you simply enter
the column number into the input (1 - number of columns set). It will
throw an error if the input is invalid.

The game finishes if there are 4 of the same checker in a row either
diagonally, vertically or horizontally just like in standard Connect
four.

If you are having issues, please let us know using the emails above.
