#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <gameboard.h>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setPoints(int level);
    void newGame();
    void gameOver();

signals:
    void keyPressed(char key);

private:
    Ui::MainWindow *ui;
    GameBoard *board;
    void keyPressEvent(QKeyEvent * pressEvent);
};

#endif // MAINWINDOW_H
