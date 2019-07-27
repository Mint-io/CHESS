#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <vector>
#include "piece.h"

class Queen : public Piece {
    public:
    void update_movelist() override;
    void update_attacklist() override;
};

#endif