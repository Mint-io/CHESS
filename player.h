#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "cell.h"
#include "board.h"
#include "piece.h"
#include "king.h"
#include "knight.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"

class Player {
    std::shared_ptr<Board> board;
    std::vector<std::shared_ptr<Piece>> theChess;
    bool isBlackParty;
    int level = 0;
    int playerNum = 2;
    int aliveNum = 0;
    Player *player = nullptr;
    // Update private fields

public:
    Player(Board *board, bool isBlackParty);
    // Accessors and Mutators of private fields
    void setLevel(std::string p);
    void setPlayer(Player *player);
    std::vector<std::shared_ptr<Piece>> &getTheChess();
    int getLevel();
    int getAliveNum();
    // Member functions
    bool setupPlayer(); // initiate a new player
    void resetTheChess(); // reset a new player
    void resetDefault(); // reset default piece
    void addPiece(char type, int x, int y); // add a piece
    void removePiece(int x, int y); // remove a piece
    // Move and attack
    void capture(int x, int y);
    bool ifCaptured(int x, int y);
    void CMove();
    void HMove(int xNew, int yNew, int x, int y, bool *moveSuccess, char promote = 'E');
    // Above 'E' is represented as a empty occupy
    void randomMove();
    void castling(int xNew, int yNew, bool *moveSuccess);
    void attackPiece();
    void attackPiece(int index);

    bool ifCheckAfterCurrentMove(int x, int y, std::shared_ptr<Piece>);
    bool ifStatlemate();
    // reserve pawn not implement
};

#endif
