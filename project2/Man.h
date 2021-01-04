#pragma once

#include "Box.h"

class Man : public Box
{
public:
    Man(Type, int, int, QPixmap*, QWidget*, Spirit*);
    void dancing();
    virtual MoveResult move(int);

private:
    QWidget*    m_gameBoard;    //遊戲區域
    QImage      m_imageLeft1;   //左圖像1
    QImage      m_imageLeft2;   //左圖像2
    QImage      m_imageRight1;  //右圖像1
    QImage      m_imageRight2;  //右圖像2
    QImage      m_imageUp1;     //上圖像1
    QImage      m_imageUp2;     //上圖像2
    QImage*     m_image1;       //目前圖像1
    QImage*     m_image2;       //目前圖像2
};
