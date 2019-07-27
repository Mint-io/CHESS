#ifndef _PAWN_H_
#define _PAWN_H_
#include <vector>
#include "piece.h"

class Pawn : public Piece {
    public:
    void update_movelist() override;
    void update_attacklist() override;
};

#endif