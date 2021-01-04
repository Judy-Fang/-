#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QPushButton>
#include "Game.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    static MainWindow *mutalUi;//使其他檔案能讀取Mainwindow內容的指標
    int num=0;//步數

private slots:
    void on_previous_clicked();//前一關
    void on_next_clicked();//後一關
    void on_restart_clicked();//重完本關
    void on_quit_clicked();//退出遊戲
    void on_quitButton_clicked();//退出
    void on_playButton_clicked();//開始

    //選關卡
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();


public slots:
    void add();//計算步數
    void reset();//步數歸零
    void display();//顯示隱藏按鈕
    void levelChange();//顯示的關卡數字改變
    void saved();

private:
    void keyPressEvent(QKeyEvent*);

private:
    Ui::MainWindow* ui;//界面
    Game m_game;//遊戲
};
