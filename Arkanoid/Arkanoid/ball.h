#ifndef BALL_H
#define BALL_H
#include <block.h>
#include <gameboard.h>

class GameBoard;

class Ball : public Block {
public:
    Ball(GameBoard *board);
    void checkMoves();
    inline int getDX() const { return dx; }
    inline int getDY() const { return dy; }
    void updatePosition();
    void bounce();
private:
    virtual QBrush getBrush();
    GameBoard *board;
    int dx;
    int dy;
};

#endif // BALL_H
