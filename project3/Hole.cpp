#include "Hole.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;//有一個external global object 為game

Hole::Hole()
{
    setPixmap(QPixmap(":/res/hole.png").scaled(50, 50));
    int x=rand()%350;
    int y=rand()%300;
    setPos(x,y);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(0);
    QTimer *timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),this,SLOT(remove()));
    timer2->start(10000);
}



void Hole::move(){
    //碰到hole遊戲結束
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player)){
            //移除player
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            game->loseMenu();
        }
     }
}

void Hole::remove(){
    scene()->removeItem(this);
    delete this;
}
