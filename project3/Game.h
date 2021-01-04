#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "Player.h"
#include "Score.h"
#include "Platform.h"
#include "Break.h"
#include "Prop1.h"
#include "Prop2.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QTimer *m_Timer;

    //public methods
    void displayMainMenu();
    void loseMenu();
    void setPlatform();


    //public attributes
    QGraphicsScene *scene1;//場景1
    Player *player;
    Score  *score;
    Platform *platform[9];
    Break *breaks[2];
    Prop1 *prop1;
    Prop1 *prop12;
    Prop2 *prop2;
    int px[8]={0};
    int py[8]={560,500,440,380,260,200,140,80};
    int bx[2];
    int by[2]={320,20};
    int sy;
    float dy;
    int h;
    bool state;//1:上升,0:下降
    int scores;
    bool here=1;


public slots:
    void start();


};


#endif // GAME_H
