#include "Prop1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QBrush>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include "Platform.h"
#include "Game.h"
extern Game * game;

Prop1::Prop1()
{
    setRect(0,0,30,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(touch()));
    timer->start(0);

}

void Prop1::touch(){
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player) && game->state==0){
                game->state=1;
                game->dy=-5;
        }
    }
}

