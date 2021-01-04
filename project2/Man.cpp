#include "Const.h"
#include "Man.h"
#include "Gameboard.h"
#include "Game.h"

/**
 * 構造方法
 * @param type      類型
 * @param x, y      左上角座標
 * @param bitmap    遊戲區域圖
 * @param gameBoard 遊戲區域
 * @param back      背面對象
 */
Man::Man(Type type, int x, int y, QPixmap* bitmap, QWidget* gameBoard, Spirit* back) :
    Box(type, x, y, bitmap, back),
    m_gameBoard(gameBoard),
    m_image1(&m_imageDown1),
    m_image2(&m_imageDown2)
{
    // 加載所有圖片
    m_imageLeft1.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 2) );
    m_imageLeft2.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 3) );
    m_imageRight1.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 4) );
    m_imageRight2.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 5) );
    m_imageUp1.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 6) );
    m_imageUp2.load( QString(Const::IMAGE_FILE_PATH).arg(type * 10 + 7) );
}

/**
 * 跳舞(人會有動的感覺)
 */
void Man::dancing()
{
    if (m_currentImage == m_image1)
    {
        m_currentImage = m_image2;
    }
    else
    {
        m_currentImage = m_image1;
    }
    m_drawer.begin(m_bitmap);
    m_drawer.drawImage(m_x * Const::GRID_SIZE, m_y * Const::GRID_SIZE, *m_currentImage);
    m_drawer.end();
    m_gameBoard->update();
}

/**
 * 移動
 * @param nDirection 方向
 * @return 移動结果
 */
Box::MoveResult Man::move(int nDirection)
{
    Box::MoveResult manMoveResult = Box::NO_MOVE;   //小人移结果
    Box::MoveResult boxMoveResult = Box::NO_MOVE;   //箱子移结果
    int nDestX = m_x, nDestY = m_y;                 //新位置的座標

    // 根據方向，計算新位置的座標和圖像
    switch (nDirection)
    {
    case Qt::Key_A:
        nDestX--;
        m_image1 = &m_imageLeft1;
        m_image2 = &m_imageLeft2;
        break;
    case Qt::Key_D:
        nDestX++;
        m_image1 = &m_imageRight1;
        m_image2 = &m_imageRight2;
        break;
    case Qt::Key_W:
        nDestY--;
        m_image1 = &m_imageUp1;
        m_image2 = &m_imageUp2;
        break;
    case Qt::Key_S:
        nDestY++;
        m_image1 = &m_imageDown1;
        m_image2 = &m_imageDown2;
        break;
    }

    // 重新設置圖像
    m_currentImage = m_image1;

    // 先移動旁邊的精靈
    boxMoveResult = Game::s_spirits[nDestY][nDestX]->move(nDirection);
    if (boxMoveResult == Box::NO_MOVE)
    {
        return boxMoveResult;
    }

    // 移動小人
    manMoveResult = Box::move(nDirection);
    if (boxMoveResult != NO_MOVE)
    {
        return boxMoveResult;
    }

    return manMoveResult;
}


