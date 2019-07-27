#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <vector>
#include "piece.h"

class Knight : public Piece {
    public:
    void update_movelist() override;
    void update_attacklist() override;
};

#endif