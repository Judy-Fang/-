#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QBrush>
#include <stdlib.h>
#include <time.h>
#include "Break.h"
#include "Game.h"
#include <QDebug>

extern Game * game;

Break::Break()
{
    setRect(0,0,70,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(touch()));
    timer->start(0);
}

void Break::touch(){
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player) && game->state==0){
            game->state=1;
            game->dy=0;
            scene()->removeItem(this);

        }
    }

}
