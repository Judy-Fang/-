/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "Gameboard.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    GameBoard *centralWidget;
    QLabel *steps;
    QLabel *show;
    QPushButton *quitButton;
    QPushButton *playButton;
    QLabel *show_2;
    QLabel *level;
    QPushButton *previous;
    QPushButton *next;
    QPushButton *restart;
    QPushButton *quit;
    QLabel *record;
    QLabel *show_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(361, 450);
        MainWindow->setMinimumSize(QSize(360, 383));
        MainWindow->setMaximumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Boxman.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(240, 240, 240);"));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new GameBoard(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        steps = new QLabel(centralWidget);
        steps->setObjectName(QString::fromUtf8("steps"));
        steps->setGeometry(QRect(58, 340, 40, 20));
        show = new QLabel(centralWidget);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(15, 341, 41, 18));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(110, 190, 121, 41));
        quitButton->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Book Antiqua\";\n"
"font: 87 12pt \"Arial Black\";\n"
"font: 87 9pt \"Arial Black\";"));
        quitButton->setFlat(false);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(90, 90, 171, 81));
        playButton->setStyleSheet(QString::fromUtf8("font: 87 9pt \"Arial Black\";\n"
"font: 87 20pt \"Arial Black\";\n"
"font: 87 22pt \"Arial Black\";\n"
"font: 87 24pt \"Arial Black\";\n"
"font: 87 26pt \"Arial Black\";\n"
"font: 87 28pt \"Arial Black\";"));
        playButton->setAutoDefault(true);
        playButton->setFlat(false);
        show_2 = new QLabel(centralWidget);
        show_2->setObjectName(QString::fromUtf8("show_2"));
        show_2->setGeometry(QRect(253, 10, 81, 18));
        level = new QLabel(centralWidget);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(330, 9, 20, 20));
        previous = new QPushButton(centralWidget);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(10, 370, 60, 40));
        previous->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Book Antiqua\";\n"
"font: 75 7pt \"Arial\";\n"
"font: 75 8pt \"Agency FB\";\n"
"font: 87 12pt \"Arial Black\";\n"
"font: 87 9pt \"Arial Black\";"));
        previous->setFlat(false);
        next = new QPushButton(centralWidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(82, 370, 60, 40));
        next->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Book Antiqua\";\n"
"font: 87 12pt \"Arial Black\";\n"
"font: 87 9pt \"Arial Black\";"));
        next->setFlat(false);
        restart = new QPushButton(centralWidget);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(180, 370, 78, 40));
        restart->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Book Antiqua\";\n"
"font: 87 12pt \"Arial Black\";\n"
"font: 87 9pt \"Arial Black\";"));
        restart->setFlat(false);
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(270, 370, 78, 40));
        quit->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Book Antiqua\";\n"
"font: 87 12pt \"Arial Black\";\n"
"font: 87 9pt \"Arial Black\";"));
        quit->setFlat(false);
        record = new QLabel(centralWidget);
        record->setObjectName(QString::fromUtf8("record"));
        record->setGeometry(QRect(320, 340, 40, 20));
        show_3 = new QLabel(centralWidget);
        show_3->setObjectName(QString::fromUtf8("show_3"));
        show_3->setGeometry(QRect(240, 340, 75, 18));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IDS_APP_NAME", nullptr));
        steps->setText(QApplication::translate("MainWindow", "0", nullptr));
        show->setText(QApplication::translate("MainWindow", "\346\255\245\346\225\270:", nullptr));
        quitButton->setText(QApplication::translate("MainWindow", "QUIT", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "PLAY", nullptr));
        show_2->setText(QApplication::translate("MainWindow", "\347\225\266\345\211\215\351\227\234\345\215\241:", nullptr));
        level->setText(QApplication::translate("MainWindow", "0", nullptr));
        previous->setText(QApplication::translate("MainWindow", "\345\211\215\344\270\200\351\227\234", nullptr));
        next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\227\234", nullptr));
        restart->setText(QApplication::translate("MainWindow", "\351\207\215\347\216\251\346\234\254\351\227\234", nullptr));
        quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\351\201\212\346\210\262", nullptr));
        record->setText(QApplication::translate("MainWindow", "0", nullptr));
        show_3->setText(QApplication::translate("MainWindow", "\346\234\200\344\275\263\347\264\200\351\214\204:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
