
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boxman
TEMPLATE = app


SOURCES += Main.cpp\
    Mainwindow.cpp \
    Gameboard.cpp \
    Man.cpp \
    Const.cpp \
    Box.cpp \
    Spirit.cpp \
    Game.cpp

HEADERS  += \
    Gameboard.h \
    Box.h \
    Const.h \
    Man.h \
    Spirit.h \
    Game.h \
    Mainwindow.h \

FORMS    += \
    MainWindow.ui

RESOURCES += \
    Resource.qrc

TRANSLATIONS += Language.ts

DISTFILES +=
