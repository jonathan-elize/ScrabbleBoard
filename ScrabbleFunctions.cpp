#include "ScrabbleFunctions.h"

//----------------------------------------
//void loadBoard(char board[][9], int boardSize, ifstream &inF)
//Goal: places ino from inF into board
//---------------------------------------
void loadBoard(char board[][9], int boardSize, ifstream &inF)
{
    //Delcare and initialize variables
    int row,
        col;
    char letter;

    //Output header
    cout << "ROW COL LETTER" << endl;
    cout << "=== === =====" << endl;

    //while there's still info in file
    while(inF.peek() != EOF)
    {
        //input for row, col, then letter
        inF >> row;
        inF >> col;
        inF >> letter;
        //----------------------------
        //validate move
        //----------------------------
        //if row < 1 || row > boardSize
        if(row < 1 || row > boardSize)
            //output ERROR:  REJECTED CELL <row> <col> <symbol> BAD ROW
            cout << "ERROR:  REJECTED CELL " << row << " " <<  col << " "
                 << letter <<  " BAD ROW" << endl;
        //else if col < 1 || col > boardSize
        else if(col < 1 || col > boardSize)
            //output ERROR:  REJECTED CELL <row> <col> <symbol> BAD COL
            cout << "ERROR:  REJECTED CELL " << row << " " << col << " "
                 << letter <<  " BAD COL" << endl;
        //else if row, cell is not ' '
        else if(board[row-1][col-1] != ' ')
            //output ERROR:  REJECTED CELL <row> <col> <symbol> CELL MARKED
            cout << "ERROR:  REJECTED CELL " << row <<  " " << col << " "
                 << letter <<  " CELL ALREADY MARKED" << endl;
        //else if int(letter) < a || int(letter) >z
        else if(int(letter) < 'A' || int(letter) > 'Z')
            //output ERROR:  REJECTED CELL <row> <col> <symbol> NOT A LETTER
            cout << "ERROR:  REJECTED CELL " << row << " " <<  col << " "
                 << letter <<  " NOT A LETTER" << endl;
        //else
        else
        {
            //mark array at [row-1][col-1] with letter
            board[row-1][col-1] = letter;
            //output <row> <col> <letter>
            cout << " " << row << "   " << col <<  "    " << letter << endl;
        }
    }

    //Output footer
    cout << "=== === =====" << endl;
}

//--------------------------------------------------------------------
//void showBoard(char board[][9], int boardSize)
//Goal: displays board in a gameboard format with the boardSize size
//restriction with the following format:
//         1 2 3 4 5
//       + - - - - - +
//row1=> |           |
//row2=> |           |
//row3=> |           |
//row4=> |           |
//row5=> |           |
//       + - - - - - +
//         1 2 3 4 5
//--------------------------------------------------------------------
void showBoard(char board[][9], int boardSize)
{
    //showBoardHeader
    showBoardHeader(boardSize);

    //for board sizing to display row
    for(int i =0; i < boardSize; i++)
    {
        //output row<i>=> |
        cout << "row" << i+1 << "=> | ";
        //for boardSizing to display col
        for(int j = 0; j < boardSize; j++)
            //output board ' '
            cout << board[i][j] << " ";
        //output |
        cout << "|" << endl;
    }

    //showBoardFooter
    showBoardFooter(boardSize);
}

//------------------------------------
//void showBoardHeader(int boardSize)
//Goal: shows top portion of board
//------------------------------------
void showBoardHeader(int boardSize)
{
    //output setw(9) 1
    cout << setw(11) << "1 ";
    //for rest of boardSize
    for(int i =2; i <= boardSize; i++)
        //display the next number with a space
        cout << i << ' ';
    cout << endl;
    //output setw(9) +
    cout << setw(9) << "+ ";
    //for rest of boardSize
    for(int i = 0; i < boardSize; i++)
        //display -
        cout << "- ";
    //display +
    cout << "+" << endl;
}

//-------------------------------------
//void showBoardFooter(int boardSize)
//Goal: shows top portion of board
//-------------------------------------
void showBoardFooter(int boardSize)
{
    //output setw(9) +
    cout << setw(9) << "+ ";
    //for boardSize
    for(int i = 2; i <= boardSize + 1; i++)
        //display -
        cout << "- ";
    //display +
    cout << "+"  << endl;

    //output setw(9) 1
    cout << setw(11) << "1 ";
    //for rest of boardSize
    for(int i =2; i <= boardSize; i++)
        //display the next number with a space
        cout << i << ' ';
    cout << endl;
}
//------------------------------------------------
//void showWords(char board[][9], int boardSize);
//Goals: display word specs of board at boardSize
//------------------------------------------------
void showWords(char board[][9], int boardSize)
{
    //WORDS ON boardSizing x boardSizing SCRABBLE BOARD
    cout << "WORDS ON " << boardSize << " x " << boardSize << " SCRABBLE BOARD "
         << endl;

    //totalWords = horizontalWords + verticalWords
    int totalWords = horizontalWords(board, boardSize)
                     + verticalWords(board, boardSize);

    //output totalWords SCRABBLE WORDS
    cout << totalWords << " SCRABBLE WORDS" << endl;
}
//-------------------------------------------------
//int horizontalWords(char board[][9], int boardSize)
//Goal: display horizontal words in board
//-------------------------------------------------
int horizontalWords(char board[][9], int boardSize)
{
    //make temp string
    string temp = " ";
    //make amountWords = 0
    int horzWords = 0;

    //output HORIZONTAL:
    cout << "HORIZONTAL:";
    //for boardSize in row
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            //for boardSize col
            //if current column is a letter
            if(board[i][j] != ' ')
            {
                //if temp == ' '
                if(temp == " ")
                    //temp = board[i][j]
                    temp = board[i][j];
                //else
                else
                    //temp += board[i][j]
                    temp += board[i][j];
            }
            //else if current column is a space
            else if(board[i][j] == ' ' )
            {
                //if temp > 1
                if(temp.length() > 1)
                {
                    //increment amount of words
                    horzWords++;
                    //output temp
                    cout << " " << temp;
                }
                //temp = ' ';
                temp = " ";
            }
        }
        //if temp > 1
        if(temp.length() > 1)
        {
            //increment amount of words
            horzWords++;
            //output temp
            cout << " " << temp;
        }
        //temp = ' ';
        temp = " ";
    }
    cout << " " << horzWords  << " WORDS" << endl;
    return horzWords;
}
//-----------------------------------------------
//int verticalWords(char board[][], int boardSize)
//Goal: display vertical words in board
//-----------------------------------------------
int verticalWords(char board[][9], int boardSize)
{
    //make temp string
    string temp = " ";
    //make amountWords = 0
    int vertWords = 0;

    //ouptut VERTICAL:
    cout << "VERTICAL:";
    //for boardSize in row
    for(int i = 0; i < boardSize; i++)
    {
        temp = " ";
        for(int j = 0; j < boardSize; j++)
        {
            //for boardSize col
            //if current column is a letter
            if(board[j][i] != ' ')
            {
                //if temp == ' '
                if(temp == " ")
                    //temp = board[j][i]
                    temp = board[j][i];
                //else
                else
                    //temp += board[j][i]
                    temp += board[j][i];
            }
            //else if current column is a space
            else if(board[j][i] == ' ' )
            {
                //if temp > 1
                if(temp.length() > 1)
                {
                    //increment amount of words
                    vertWords++;
                    //output temp
                    cout << " " << temp;
                }
                //temp = ' ';
                temp = " ";
            }
        }
        //if temp > 1
        if(temp.length() > 1)
        {
            //increment amount of words
            vertWords++;
            //output temp
            cout << " " << temp;
        }
        //temp = ' ';
        temp = " ";
    }
    cout << " " << vertWords  << " WORDS" << endl;
    return vertWords;
}

//-----------------------------------------------
//int numTiles(char board[][9], int boardSize)
//Goal: return num of marks on board
//-----------------------------------------------
int numTiles(char board[][9], int boardSize)
{
    int tileCounter = 0;

    for(int i = 0; i < boardSize; i++)
    {
	for(int j = 0; j < boardSize; j++)
	{
	    if(board[i][j] != ' ')
		tileCounter++;
	}
    }

    return tileCounter;
}
