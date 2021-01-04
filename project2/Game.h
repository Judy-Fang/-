#pragma once

#include <QPainter>
#include <QTimer>
#include "Man.h"
#include "Const.h"

class Game : public QObject
{
    Q_OBJECT

public:
    enum Status
    {
        END,//结束
        PLAYING// 遊戲中
    };

    Game();
    ~Game();
    void create(QWidget*, QWidget*, QPixmap*);
    void gotoLevel(int);
    void replay();
    void quit();
    void onKeyPress(int);
    int  m_nLevel=0;//關卡
    int m_nrecord=0;
    QWidget* m_gameBoard;//遊戲區域

private slots:
    void onTimer();

private:
    void checkWon();
    void deleteAllSpirits();

public:
    static Spirit* s_spirits[Const::GAMEBOARD_GRID_COUNT_V][Const::GAMEBOARD_GRID_COUNT_H];//所有精靈

private:
    QWidget*    m_mainWindow;   //主窗口
    QPainter    m_drawer;       //繪圖者
    QPixmap*    m_bitmap;       //遊戲區域圖
    Status      m_status;       //遊戲狀態
    Man*        m_man;          //小人
    int         m_nBoxCount;    //未到達目的地的箱子數
    QTimer      m_timer;        //時鐘
};
