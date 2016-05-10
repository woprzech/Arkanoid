#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QRadialGradient>
#include <QPen>
#include <QBrush>
#include <QDebug>

class Block : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    explicit Block(QObject *parent = 0);
    Block(int x, int y, QObject *parent = 0);
    void setColor(QColor color);
    inline QColor getColor() const { return color; }
    void setX(int x);
    inline int getX() const { return x; }
    void setY(int y);
    inline int getY() const { return y; }
    void setPosition(int x, int y);
    void updateX(int x);
    void updateY(int y);
public slots:

private:
    virtual QBrush getBrush();
    int edge;
    int x;
    int y;
    QColor color;
    QBrush brush;
    QPen pen;
    QRadialGradient gradient;
};

#endif // BLOCK_H
