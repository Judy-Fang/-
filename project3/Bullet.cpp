#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;//有一個external global object 為game

Bullet::Bullet()
{
    setPixmap(QPixmap(":/res/bullet.png").scaled(30, 70));

    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Bullet::move()
{
    //bullet碰到怪獸，兩個都不見
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            //分數增加
            game->score->increase();
            //移除怪獸
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    //move bullet up
    setPos(x(),y()-10);
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
