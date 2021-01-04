#include "Const.h"
#include "Box.h"
#include "Game.h"

/**
 * @param type      類型
 * @param x, y      左上角座標
 * @param bitmap    遊戲區域圖
 * @param back      背面圖像
 */

Box::Box(Type type, int x, int y, QPixmap* bitmap, Spirit* back) :
    Spirit(type, x, y, bitmap),m_currentImage(&m_imageDown1),m_back(back)
{
    // 加載圖像2
    m_imageDown2.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 1) );
}

/**
 * 建構子
 */
Box::~Box()
{
    delete m_back;
}

/**
 * 移動
 * @param nDirection 方向
 * @return 移動结果
 */
Box::MoveResult Box::move(int nDirection)
{
    Box::MoveResult moveResult = Box::NO_MOVE;
    bool bLeftFromDest = false;

    int nDestX = m_x, nDestY = m_y;//小人要移動到的位置的座標
    switch (nDirection)
    {
    case Qt::Key_A:
        nDestX--;
        break;
    case Qt::Key_D:
        nDestX++;
        break;
    case Qt::Key_W:
        nDestY--;
        break;
    case Qt::Key_S:
        nDestY++;
        break;
    }

    //如果旁邊是牆或箱子，則直接返回
    if ( Game::s_spirits[nDestY][nDestX]->getType() <= Spirit::BOX )
    {
        return moveResult;
    }

    moveResult = Box::NORMAL_MOVED;

    //判斷是否要離開目的地
    if ( m_type == Spirit::BOX && m_back->getType() == Spirit::DESTINATION )
    {
        bLeftFromDest = true;
        moveResult = Box::LEFT_FROM_DEST;
        m_currentImage = &m_imageDown1;
    }

    //用背面對象擦除自己
    m_back->draw();
    Game::s_spirits[m_y][m_x] = m_back;

    //計算新位置
    m_x = nDestX;
    m_y = nDestY;

    //設置新的背面對象
    m_back = Game::s_spirits[m_y][m_x];

    //判斷是否到達目的地
    if ( m_type == Spirit::BOX && m_back->getType() == Spirit::DESTINATION )
    {
        if (bLeftFromDest)
        {
            moveResult = Box::NORMAL_MOVED;
        }
        else
        {
            moveResult = Box::ARRIVED_ON_DEST;
        }
        m_currentImage = &m_imageDown2;
    }

    //重繪自己
    m_drawer.begin(m_bitmap);
    m_drawer.drawImage(m_x * Const::GRID_SIZE, m_y * Const::GRID_SIZE, *m_currentImage);
    m_drawer.end();

    //將自己保存到陣列中
    Game::s_spirits[m_y][m_x] = this;

    return moveResult;
}
