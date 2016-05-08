#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <random>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <block.h>
#include <userblock.h>
#include <ball.h>

class QPixmap;
class UserBlock;
class Ball;


class GameBoard : public QGraphicsScene {
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);
    ~GameBoard();
    void moveBall();
    void moveLeft();
    void moveRight();
    bool isCellEmpty(int xIndex, int yIndex);
signals:
    void updatePoints(int points);
    void gameOver();
private slots:
    void updateAnimation();

public slots:
//    void newGame();
//    void pauseGame();
//    void resumeGame();
    void keyboardEvent(char key);
    void addPoint(int x, int y);

private:
    void runAnimation(int x, int y, int x2, int y2, int baseTime);
    Block *cells[30][15];
    UserBlock *userBlock;
    Ball *ball;
    bool isStarted = false;
    int points = 0;
    //animation
    QGraphicsItemAnimation *animation;
    QTimeLine *timeLine;
};

#endif // GAMEBOARD_H
