#ifndef PLATFORM_H
#define PLATFORM_H


#include <QGraphicsRectItem>
#include <QObject>
class Platform: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Platform();
public slots:
    virtual void touch();
    virtual void move();

};


#endif // PLATFORM_H
