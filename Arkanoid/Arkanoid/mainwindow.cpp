#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QMessageBox>
#include <QString>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    board = new GameBoard();
    connect(this, SIGNAL(keyPressed(char)), board, SLOT(keyboardEvent(char)));
    connect(board, SIGNAL(updatePoints(int)), this, SLOT(setPoints(int)));
    connect(board, SIGNAL(gameOver()), this, SLOT(gameOver()));
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    board->setSceneRect(0, 0, 900, 450);
    ui->graphicsView->setScene(board);
    ui->centralWidget->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow() {
    delete ui;
    delete board;
}

void MainWindow::keyPressEvent(QKeyEvent *pressEvent) {
    switch(pressEvent->key()) {
        case Qt::Key_Space :
            emit keyPressed('s');
            break;
        case Qt::Key_Left :
            emit keyPressed('l');
            break;
        case Qt::Key_Right :
            emit keyPressed('r');
            break;
    }
}

void MainWindow::setPoints(int level) {
    ui->lcdNumber->display(level);
}

void MainWindow::gameOver() {
    QString tmp;
    tmp = "   Your score is " + QString::number(ui->lcdNumber->intValue()) + "   ";
    QMessageBox::information(this,"Game Over!",tmp,QMessageBox::Ok);
}

