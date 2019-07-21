#include "board.h"
#include "cell.h"
#include "graphicaldisplay.h"
#include "textdisplay.h"
using namespace std;

// Accessors and Mutators of private fields
std::shared_ptr<GraphicalDisplay> Board::getGD() {
    return this->gd;
}
std::shared_ptr<TextDisplay> Board::getTD() {
    return this->td;
}
std::vector< std::vector<Cell> > & Board::getChessBoard() {
    return this->chessBoard;
}
// Constructors
Board::Board() {
    // Clear board if necessary
    chessBoard.clear();
    // Create empty board. 'E' refers as empty
    for (int i = 0; i < ROW; i++) {
        chessBoard.emplace_back();
        for (int j = 0; j < COLUMN; j++) {
            chessBoard[i].emplace_back(Cell{'E', i, j});
        }
    }
    // Create Dual Display for both graphical and text display
    gd = make_shared<GraphicalDisplay>();
    td = make_shared<TextDisplay>();
}
// Member functions
void Board::reset() {
    for (int m = 0; m < ROW; m++) {
        chessBoard.emplace_back();
        for (int n = 0; n < COLUMN; n++) {
            chessBoard[m][n].setOccupy('E'); // Set to empty
            chessBoard[m][n].notifyDualDisplay(gd, td);
        }
    }
}
void Board::init() {
    // Create empty board. 'E' refers as empty
    for (int i = 0; i < ROW; i++) {
        chessBoard.emplace_back();
        for (int j = 0; j < COLUMN; j++) {
            chessBoard[i][j].setOccupy('E'); // Set to empty
        }
    }

    // Set temporary constants
    const int firstRow = 0;
    const int lastRow = 7;

    // Set lowercase(Black) letters
    chessBoard[0][lastRow].setOccupy('r');
	chessBoard[1][lastRow].setOccupy('n');
	chessBoard[2][lastRow].setOccupy('b');
	chessBoard[3][lastRow].setOccupy('q');
	chessBoard[4][lastRow].setOccupy('k');
	chessBoard[5][lastRow].setOccupy('b');
	chessBoard[6][lastRow].setOccupy('n');
	chessBoard[7][lastRow].setOccupy('r');
    
    for (int j = 0; j < COLUMN; ++j){
		chessBoard[j][lastRow - 1].setOccupy('p');
	}

    // Set capital(White) letters
    chessBoard[0][firstRow].setOccupy('R'); 
	chessBoard[1][firstRow].setOccupy('N');
	chessBoard[2][firstRow].setOccupy('B');
	chessBoard[3][firstRow].setOccupy('Q');
	chessBoard[4][firstRow].setOccupy('K');
	chessBoard[5][firstRow].setOccupy('B');
	chessBoard[6][firstRow].setOccupy('N');
	chessBoard[7][firstRow].setOccupy('R');
	
	for (int j = 0; j < COLUMN; ++j){
		chessBoard[j][firstRow + 1].setOccupy('P');
	}

    // notifyDualDisplay
    for (int m = 0; m < ROW; m++) {
        for (int n = 0; n < COLUMN; n++) {
            chessBoard[m][n].notifyDualDisplay(gd, td);
        }
    }
}
Cell *Board::getOneCell(int x, int y) {
    return &chessBoard[x][y];
}
bool Board::checkOccupy(int x, int y) {
    return chessBoard[x][y].getOccupy() == 'E' ? false : true;
}
void Board::removePiece(int x, int y) {
    chessBoard[x][y].setOccupy('E'); // Set to empty
    chessBoard[x][y].notifyDualDisplay(gd, td);
}
void Board::placePiece(char type, int x, int y) {
    chessBoard[x][y].setOccupy(type); // Set to empty
    chessBoard[x][y].notifyDualDisplay(gd, td);
}
