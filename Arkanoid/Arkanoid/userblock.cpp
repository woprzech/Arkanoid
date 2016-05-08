#include "userblock.h"
#include <iostream>
#include <QDebug>

UserBlock::UserBlock(GameBoard *board) {
//    this->board = board;
}

void UserBlock::moveLeft(){
    setX(getX() - 1);

}

void UserBlock::moveRight(){
    setX(getX() + 1);
}
