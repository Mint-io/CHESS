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
    std::vector< std::vector<Cell> > chessBoard;

public:
    // Accessors and Mutators of private fields
    std::shared_ptr<GraphicalDisplay> getGD();
    std::shared_ptr<TextDisplay> getTD();
    std::vector< std::vector<Cell> > &getChessBoard();
    // Constructors
    Board();
    // Member functions
    void reset();
    void init();
    Cell *getOneCell(int x, int y);
    bool checkOccupy(int x, int y);
    void placePiece(char type, int x, int y);
    void removePiece(int x, int y);
};

#endif
