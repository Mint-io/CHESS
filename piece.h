#ifndef _PIECE_H_
#define _PIECE_H_
#include <vector>

class Cell;

class Board;

class Piece {
    char side; // 'b' for black, 'w' for white
    int x; // x axis
    int y; // y axis
    protected:
    std::shared_ptr<Board> gameboard;
    std::vector<Cell *> movelist;
    std::vector<Cell *> attacklist;
    std::vector<Cell> historylist;
    public:
    char getSide();
    int getX();
    int getY();

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
};



#endif