#include "block.h"

Block::Block(QObject *parent) : QObject(parent) {
    this->edge = 30;
    this->x = 0;
    this->y = 0;
    this->setRect(x*edge, y*edge, edge, edge);
}

Block::Block(int x, int y, QObject *parent) : QObject(parent) {
    this->edge = 30;
    this->x = x;
    this->y = y;
    this->setRect(0, 0, edge, edge);
}

void Block::setColor(QColor color) {
    this->color = color;
    pen.setColor(color);
    brush = getBrush();
    this->setPen(pen);
    this->setBrush(brush);
}

void Block::setX(int x) {
    this->x = x;
    setPos(x*edge, y*edge);
}

void Block::updateX(int x){
    this->x = x;
}

void Block::setY(int y) {
    this->y = y;
    this->setPos(x*edge, y*edge);
}

void Block::updateY(int y){
    this->y = y;
}

void Block::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    setPos(x*edge, y*edge);
}

QBrush Block::getBrush(){
    return QBrush(Qt::blue);
}
