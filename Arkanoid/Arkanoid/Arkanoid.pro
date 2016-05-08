#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T09:52:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arkanoid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    block.cpp \
    gameboard.cpp \
    userblock.cpp \
    ball.cpp

HEADERS  += mainwindow.h \
    block.h \
    gameboard.h \
    userblock.h \
    ball.h

FORMS    += mainwindow.ui
