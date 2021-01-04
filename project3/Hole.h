#ifndef HOLE_H
#define HOLE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Hole: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hole();

public slots:
    void move();
    void remove();

};

#endif // HOLE_H
