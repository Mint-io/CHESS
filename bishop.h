#ifndef _BISHOP_H_
#define _BISHOP_H_
#include <vector>
#include "piece.h"

class Bishop : public Piece {
    public:
    void update_movelist() override;
    void update_attacklist() override;
};

#endif