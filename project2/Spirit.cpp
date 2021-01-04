#include "Const.h"
#include "Spirit.h"

/**
 * 構造方法
 * @param type      類型
 * @param x, y      左上角座標
 * @param bitmap    遊戲區域圖
 */
Spirit::Spirit(Type type, int x, int y, QPixmap* bitmap) :
    m_type(type),
    m_x(x),
    m_y(y),
    m_bitmap(bitmap)
{
    // 加載圖片
    m_imageDown1.load( QString(Const::IMAGE_FILE_PATH).arg(type) );

    // 繪製自己
    this->draw();
}

/**
 * 建構子
 */
Spirit::~Spirit()
{
}

/**
 * 繪製自己
 */
void Spirit::draw()
{
    m_drawer.begin(m_bitmap);
    m_drawer.drawImage(m_x * Const::GRID_SIZE, m_y * Const::GRID_SIZE, m_imageDown1);
    m_drawer.end();
}

/**
 * 移動
 * @return 移動结果
 */
Spirit::MoveResult Spirit::move(int)
{
    if (m_type == WALL)
    {
        return NO_MOVE;
    }
    return CANNOT_MOVE;
}

/**
 * 獲取類型
 * @return 類型
 */
Spirit::Type Spirit::getType()
{
    return m_type;
}
