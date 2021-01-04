#ifndef BREAK_H
#define BREAK_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Platform.h"
class Break:public Platform
{
    Q_OBJECT
public:
    Break();
public slots:
    void touch();

};


#endif // BREAK_H
