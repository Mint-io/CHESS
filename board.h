#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <cstddef>
#include <memory>
#include <string>
#include "cell.h"

class TextDisplay;
class GraphicalDisplay;
class Cell;

class Board {
    std::shared_ptr<GraphicalDisplay> gd;
    std::shared_ptr<TextDisplay> td;
    std::vector< std::vector<Cell> > chessBoard; // the chess playground

public:
    // Accessors and Mutators of private fields
    std::shared_ptr<GraphicalDisplay> getGD();
    std::shared_ptr<TextDisplay> getTD();
    std::vector< std::vector<Cell> > &getChessBoard();
    // Constructors
    Board();
    // Member functions
    void reset(); // reset the chessBoard
    void init(); // initiate the chessBoard
    Cell *getOneCell(int x, int y); // get a single cell from the chessBoard
    bool checkOccupy(int x, int y); // check if a cell is occupied
    void placePiece(char type, int x, int y); // place a piece/cell
    void removePiece(int x, int y); // remove a piece/cell
};

#endif
