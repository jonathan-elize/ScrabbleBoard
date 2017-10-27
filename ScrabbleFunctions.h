#ifndef SCRABBLE_FUNCTIONS_H
#define SCRABBLE_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void loadBoard(char board[][9], int boardSize, ifstream &inF);
void showBoard(char board[][9], int boardSize);
void showBoardHeader(int boardSize);
void showBoardFooter(int boardSize);
void showWords(char board[][9], int boardSize);
int horizontalWords(char board[][9], int boardSize);
int verticalWords(char board[][9], int boardSize);
int numTiles(char board[][9], int boardSize);

#endif
