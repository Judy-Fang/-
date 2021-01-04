#include "Gameboard.h"
#include "Const.h"

/**
 * 構造方法
 * @param parent    父視窗
 */
GameBoard::GameBoard(QWidget* parent) :
    QWidget(parent),m_bitmap(Const::GAMEBOARD_WIDTH, Const::GAMEBOARD_HEIGHT)
{
}

/**
 * 構造方法
 * @param parent    父
 * @param x, y      左上角座標
 * @param nWidth    寬度
 * @param nHeight   高度
 */
GameBoard::GameBoard(QWidget* parent, int x, int y, int nWidth, int nHeight) :
    QWidget(parent),m_bitmap(nWidth, nHeight)
{
    this->move(x, y);
    this->setFixedSize(nWidth, nHeight);
}

/**
 * 獲取後台緩衝圖
 * @return 後台緩衝圖
 */
QPixmap* GameBoard::getBitmap()
{
    return &m_bitmap;
}

/**
 * 將後台緩衝圖重新繪製到前台。
 */
void GameBoard::paintEvent(QPaintEvent*)
{
    m_drawer.begin(this);
    m_drawer.drawPixmap(0, 0, m_bitmap);
	m_drawer.end();
}
