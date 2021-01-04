#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


extern Game * game;

Enemy::Enemy()
{
    setPixmap(QPixmap(":/res/monster.png").scaled(70, 40));
    int x=rand()%330;
    int y=rand()%200;
    setPos(x,y);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(0);

}

void Enemy::move(){
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Player)){
            if(game->state==0){
                game->state=1;
                game->dy=0;
                scene()->removeItem(this);
                delete this;
            }else{
                 game->loseMenu();
            }
        }
    }
}


