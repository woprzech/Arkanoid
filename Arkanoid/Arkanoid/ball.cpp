#include "ball.h"

Ball::Ball(GameBoard *board) {
    this->board = board;
    dx = 1;
    dy = -1;
}

void Ball::checkMoves(){
    bool isEndOfBoard = false;
    if(getY()+getDY() < 1){
        dy = -dy;
        isEndOfBoard = true;
    }
    if(getX()+getDX() < 0 || getX()+getDX() > 29){
        dx = -dx;
        isEndOfBoard = true;
    }
    if(isEndOfBoard){
        return;
    }
    if(!board->isCellEmpty(getX()+getDX(), getY()+getDY())){
        board->addPoint(getX()+getDX(), getY()+getDY());
        dx = -dx;
        dy = -dy;
    } else if(!board->isCellEmpty(getX()+getDX(), getY())){
        board->addPoint(getX()+getDX(), getY());
        dx = -dx;
    } else if (!board->isCellEmpty(getX(), getY()+getDY())){
        board->addPoint(getX(), getY()+getDY());
        dy = -dy;
    }

}

void Ball::updatePosition(){
    updateX(getX()+getDX());
    updateY(getY()+getDY());
}

void Ball::bounce(){
    dy = -dy;
}

QBrush Ball::getBrush(){
    QRadialGradient gradient = QRadialGradient(15, 15, 18, 15, 15);
    gradient.setColorAt(1, Qt::white);
    gradient.setColorAt(0, Qt::blue);
    return QBrush(gradient);
}
