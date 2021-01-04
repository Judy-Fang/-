#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // draw the text
    setPlainText(QString("Score: ") + QString::number(game->scores)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",10));
}

void Score::increase(){
    game->scores+=2;
    setPlainText(QString("Score: ") + QString::number(game->scores)); // Score: 1
}

void Score::plus(){
    game->scores+=5;
    setPlainText(QString("Score: ") + QString::number(game->scores));
}


