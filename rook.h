#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"
#include <vector>

class Rook : public Piece {
    public:
    // constructor
    Rook(bool isAlive, int x, int y, std::shared_ptr<Board> gameboard, char chesstype) : 
        Piece{isAlive, x, y, gameboard, chessType} {
            update_movelist();
            update_attacklist();
        }
    void update_movelist() override;
    void update_attacklist() override;
    bool blockCell(int r, int c) override;
};


#endif