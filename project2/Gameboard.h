#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget*);
    explicit GameBoard(QWidget*, int, int, int, int);
    QPixmap* getBitmap();


private:
    void paintEvent(QPaintEvent*);

private:
    QPixmap     m_bitmap;   // 緩衝圖
    QPainter    m_drawer;   // 繪圖者
};
