#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Platform.h"
#include "Break.h"
#include "Hole.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QBrush>


Player::Player()
{
    setRect(0,0,20,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    setPos(185,570);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D){
        //setPixmap(QPixmap(":/res/doodle_right.png").scaled(70, 70));
        setPos(x()+5,y());
        if(x()>=400-20){
            setPos(0,y());
        }
    }else if(event->key() == Qt::Key_A){
        //setPixmap(QPixmap(":/res/doodle_left.png").scaled(70, 70));
        setPos(x()-5,y());
        if(x()<=0){
           setPos(380,y());
        }
    }else if(event->key()==Qt::Key_Space){
        //setPixmap(QPixmap(":/res/doodle_up.png").scaled(70, 70));
        Bullet *bullet=new Bullet();
        scene()->addItem(bullet);//這邊的scene是現在的場景
        bullet->setPos(x()+10 - bullet->pixmap().width()/2,y());
    }
}


void Player::spawn()
{
    //產生怪獸
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);

}

void Player::setHole()
{
    Hole *hole=new Hole();
    scene()->addItem(hole);
}


