#ifndef PROP1_H
#define PROP1_H

#include <QGraphicsRectItem>
#include <QObject>
class Prop1: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Prop1();
public slots:
    void touch();

};

#endif // PROP1_H
