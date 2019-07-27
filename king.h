#ifndef _KING_H_
#define _KING_H_
#include "piece.h"
#include <vector>


class King : public Piece {
    bool checked;
    public:
    bool ischecked();
    void update_movelist() override;
    void update_attacklist() override;
    bool validcastling(Cell) override;
};


#endif