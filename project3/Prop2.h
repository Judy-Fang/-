#ifndef PROP2_H
#define PROP2_H

#include <QGraphicsRectItem>
#include <QObject>
class Prop2: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Prop2();
public slots:
    void touch();

};


#endif // PROP2_H
