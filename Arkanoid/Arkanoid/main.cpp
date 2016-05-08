#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setApplicationName("Tetris");
    a.setApplicationDisplayName("Tetris");
    a.setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    MainWindow w;
    w.show();

    return a.exec();
}
