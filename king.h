#ifndef _KING_H_
#define _KING_H_
#include "piece.h"
#include <vector>


class King : public Piece {
    bool checked;
    public:
    // constructor
    King(bool isAlive, int x, int y, std::shared_ptr<Board> gameboard, char chesstype) : 
        Piece{isAlive, x, y, gameboard, chessType} {
            checked = false;
            update_movelist();
            update_attacklist();
        }
    bool ischecked();
    void update_movelist() override;
    void update_attacklist() override;
    bool validcastling(Cell) override;
    bool blockCell(int r, int c) override;
};


#endif