#ifndef USERBLOCK_H
#define USERBLOCK_H
#include <block.h>
#include <gameboard.h>
class GameBoard;
class UserBlock : public Block {
public:
    UserBlock(GameBoard *board);
    void moveLeft();
    void moveRight();

private:
    GameBoard *board;
};

#endif // USERBLOCK_H
