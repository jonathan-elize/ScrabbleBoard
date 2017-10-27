//-| --------------------------------------------------------------------------
//-| File name:   Scrabble.cpp
//-| Assign ID:   PROG2
//-| Due Date:    September 16, 2017
//-|
//-| Purpose:     Display gameboard based on data file
//-|
//-| Author:      (c) 2017, jelize Jonathan Elize
//-|
//-| --------------------------------------------------------------------------
#include "ScrabbleFunctions.h"

int main(){
    //----------------------------------
    //Declare and Initialize variables
    //----------------------------------
    const int BOARD_CAP = 9;            //max width and height of the board
    ifstream inF;                       //file handler to make board from
    string filename;                    //name of the file to be used
    int boardSize;                      //size of the board from the file
    char board[BOARD_CAP][BOARD_CAP];   //2d array corresponding to the board

    //intitialize each board space to ' '
    for(int i = 0; i < BOARD_CAP; i++)
    {
        for(int j = 0; j < BOARD_CAP; j++)
            board[i][j] = ' ';
    }

    //---------------------
    //prompt for file name
    //---------------------
    cout << "Enter name of input file: ";
    cin >> filename;

    //---------------------
    //open file for input
    //---------------------
    inF.open(filename.c_str());

    //If file failes
    if(!inF)
        cout << "FATAL ERROR: Can not open file '" << filename << "'" << endl;
    //else
    else
    {
	//-----------------------------
        //prompt for boardSize
	//-----------------------------
        cout << "Enter board size [1-9]: ";
        cin >> boardSize;

	//-----------------------------
        //loadBoard
	//-----------------------------
        loadBoard(board, boardSize, inF);

        //close file
        inF.close();

	//-----------------------------------
        //Display number of tiles on board
	//-----------------------------------
        cout << numTiles(board, boardSize) << " TILES on Scrabble Board" 
	     << endl;

	//---------------------------------------------
        //output boardSize x boardSize SCRABBLE BOARD
	//---------------------------------------------
        cout << boardSize << " x " << boardSize << " SCRABBLE BOARD" << endl
             << endl;
        showBoard(board, boardSize);

        //----------------------
        //Display Specs
        //----------------------
        showWords(board, boardSize);
    }

    //---------------------
    //Display Copyright
    //---------------------
    cout << endl << "(c) 2017, jelize Jonathan Elize" << endl << endl; 

    return 0;
}
