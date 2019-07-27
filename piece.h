#ifndef _PIECE_H_
#define _PIECE_H_
#include <vector>
#include <iostream>
#include "cell.h"

class Cell;
class Board;

class Piece {

protected:
    char chessType; // QKBNRP or qkbnrp
    bool isAlive; //whether removed or not
    int x; // x axis
    int x_prev; // x_prev axis
    int y; // y axis
    int y_prev; // y_prev axis
    std::shared_ptr<Board> gameboard;
    std::vector<Cell *> movelist;
    std::vector<Cell *> attacklist;
    std::vector<Cell> historylist;
public:
    Piece(bool isAlive, int x, int y, std::shared_ptr<Board> gameboard, char chessType) :
        isAlive{isAlive}, x{x}, y{y}, gameboard{gameboard}, chessType{chessType} {
        x_prev = x;
        y_prev = y;
    }
    char getType();
    void setX(int x);
    void setY(int y);
    void setX_prev(int x);
    void setY_prev(int y);
    int getX();
    int getY();
    int getX_prev();
    int getY_prev();
    std::vector<Cell *> &getMoveList();
    std::vector<Cell *> &getAttackList();
    bool alive();

    // execute a valid move to a cell that contained in movelist or attacklist
    virtual void moveto(int x, int y);

    // update_movelist() returns a pointer to a vector list of cells that the 
    // piece can move to. 
    virtual void update_movelist() = 0;

    // update_attacklist() returns a pointer to a vector list of cells that the
    // piece can capture an enemy piece.
    virtual void update_attacklist() = 0;

    // validmove(Cell) returns a bool that determines if the Cell is empty and
    // on the 8*8 gameboard.
    bool validmove(Cell);

    // validattack(Cell) returns a bool that determines if the Cell is occupied
    // by an enemy piece and on the 8*8 gameboard.
    bool validattack(Cell);

    // validcastling(Cell) returns a bool that determines if the piece can have a
    // castling move
    // parameter is one of the four corner of the gameboard
    virtual bool validcastling(Cell);

    // see if cell blocks the way
    virtual bool blockCell(int r, int c) = 0;
};



#endif
