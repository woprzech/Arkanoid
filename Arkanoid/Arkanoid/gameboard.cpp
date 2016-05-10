#include "gameboard.h"

#include <QTime>

GameBoard::GameBoard(QObject * parent) : QGraphicsScene(parent) {
    qsrand(QTime::currentTime().msec());
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 15; j++) {
            cells[i][j]=nullptr;
        }
    }
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 6; j++) {
            if(((j % 2) == 0) || i%2 == 0){
                cells[i][j] = nullptr;
                continue;
            }
            cells[i][j] = new Block();
            cells[i][j]->setPosition(i, j);
            cells[i][j]->setColor(Qt::blue);
            cells[i][j]->setVisible(true);
            this->addItem(cells[i][j]);
        }
    }
    userBlock = new UserBlock(this);
    userBlock->setPosition(10, 14);
    userBlock->setColor(Qt::blue);
    userBlock->setVisible(true);
    this->addItem(userBlock);
    ball = new Ball(this);
    ball->setPosition(10, 13);
    ball->setColor(Qt::white);
    ball->setVisible(true);
    this->addItem(ball);
}

GameBoard::~GameBoard() {
}

void GameBoard::moveBall() {
    if(ball->getY() == 13 && ball->getDY() > 0){
        if(ball->getX() == userBlock->getX()){
            ball->bounce();
        } else{
            emit gameOver();
            return;
        }
    } else{
           ball->checkMoves();
    }
    runAnimation((ball->getX())*30,
                 (ball->getY())*30,
                 (ball->getX()+ball->getDX())*30,
                 (ball->getY()+ball->getDY())*30,
                 500);
    ball->updatePosition();
}

void GameBoard::moveLeft() {
    userBlock->moveLeft();
}

void GameBoard::moveRight() {
    userBlock->moveRight();
}

void GameBoard::keyboardEvent(char key) {
    switch (key) {
        case 's' :
            moveBall();
            break;
        case 'l' :
            moveLeft();
            break;
        case 'r' :
            moveRight();
            break;
    }
}

void GameBoard::runAnimation(int x, int y, int x2, int y2, int time) {
    timeLine = new QTimeLine(time);
    timeLine->setEasingCurve(QEasingCurve::Linear);
    animation = new QGraphicsItemAnimation;
    animation->setItem(ball);
    animation->setTimeLine(timeLine);
    animation->setPosAt(0.f, QPointF(x, y));
    animation->setPosAt(1.f, QPointF(x2, y2));
    connect(timeLine, SIGNAL(finished()), this, SLOT(updateAnimation()));
    timeLine->start();
}

void GameBoard::updateAnimation() {
    disconnect(timeLine, SIGNAL(finished()), this, SLOT(updateAnimation()));
    moveBall();
}

bool GameBoard::isCellEmpty(int xIndex, int yIndex) {
    if(xIndex < 0 || xIndex > 29 || yIndex < 0 || yIndex > 14){
        return false;
    }
    return cells[xIndex][yIndex] == nullptr;
}

void GameBoard::addPoint(int x, int y){
    this->removeItem(cells[x][y]);
    delete cells[x][y];
    cells[x][y] = nullptr;
    points++;
    emit updatePoints(points);
}
