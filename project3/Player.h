#ifndef PLAYER_H
#define PLAYER_H

#endif // PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
class Player: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);


public slots:
    void jump();//使player jump
    void spawn();//產生怪獸
    void setHole();//產生洞


};
