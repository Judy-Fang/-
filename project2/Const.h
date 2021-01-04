#pragma once

#include <QColor>

class Const
{
public:
    //狀態欄
    static const int STATUSBAR_PART_COUNT = 2;//格

    //格
    static const int GRID_SIZE = 30;//尺寸

    //游戲區域
    static const int GAMEBOARD_X = 0;//左上角 X 座標
    static const int GAMEBOARD_Y = 0;//左上角 Y 座標
    static const int GAMEBOARD_GRID_COUNT_H = 12;//横向格數
    static const int GAMEBOARD_GRID_COUNT_V = 12;//縱向格數
    static const int GAMEBOARD_WIDTH = GRID_SIZE * GAMEBOARD_GRID_COUNT_H;//寬度
    static const int GAMEBOARD_HEIGHT = (GRID_SIZE+10) * GAMEBOARD_GRID_COUNT_V;//高度
    static QColor GAMEBOARD_COLOR;//顏色

    //時鐘
    static const int TIMER_INIT = 500;//間隔


    //關卡
    static const char* LEVEL_FILE_PATH;//關卡文件名
    static const int LEVEL_COUNT = 5;//關卡總數
    static const char* RECORD_FILE_PATH;

    //圖片
    static const char* IMAGE_FILE_PATH;//圖像文件名

};
