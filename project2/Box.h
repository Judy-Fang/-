#pragma once

#include "Spirit.h"

class Box : public Spirit
{
public:
    Box(Type, int, int, QPixmap*, Spirit*);
    virtual ~Box();
    virtual MoveResult move(int);

protected:
    QImage  m_imageDown2;   // 2
    QImage* m_currentImage;	// 目前圖像

private:
    Spirit* m_back;			// 背面圖象
};
