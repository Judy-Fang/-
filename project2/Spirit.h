#pragma once

#include <QImage>
#include <QPainter>
#include <QPixmap>

class Spirit
{
public:
    enum Type
    {
        NOTHING = 0,        //什麼都沒有
        WALL = 1,           //牆
        BOX = 2,            //箱子
        BACKGROUND = 3,     //背景
        DESTINATION = 4,    //箱子的目的地
        MAN = 5
    };

    enum MoveResult
    {
        CANNOT_MOVE,        //本身不具有移動能力
        NO_MOVE,            //沒有移
        NORMAL_MOVED,       //正常移動
        ARRIVED_ON_DEST,    //移動到目上
        LEFT_FROM_DEST      //離開目標
    };

    Spirit(Type, int ,int, QPixmap*);
    virtual ~Spirit();
    void draw();
    virtual MoveResult move(int);
    Type getType();

protected:
    Type        m_type;         //類型
    int         m_x;            //横向座標
    int         m_y;            //縱向座標
    QPixmap*    m_bitmap;       //遊戲區區域圖
    QPainter    m_drawer;       //繪圖者
    QImage      m_imageDown1;   //圖像
};
