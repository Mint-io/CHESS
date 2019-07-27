#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"
#include <vector>

class Rook : public Piece {
    public:
    void update_movelist() override;
    void update_attacklist() override;
};


#endif