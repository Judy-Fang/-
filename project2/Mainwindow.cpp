#include "Mainwindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include <QKeyEvent>
#include <QInputDialog>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QMessageBox>
#include <QPalette>
#include <QFont>

/**
 * 構造方法
 * @param parent 父視窗
 */

MainWindow *MainWindow::mutalUi=nullptr;//初始化功能指標

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mutalUi=this;//功能指標=ui

    //一開始先隱藏遊戲功能按鈕
    ui->previous->hide();
    ui->next->hide();
    ui->restart->hide();
    ui->quit->hide();
    ui->show->hide();
    ui->show_2->hide();
    ui->show_3->hide();
    ui->steps->hide();
    ui->level->hide();
    ui->record->hide();
    m_game.create( this, ui->centralWidget, ui->centralWidget->getBitmap());
}

/**
 * 建構子
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * 將案件的訊號轉交给遊戲對象來處理
 * @param event 事件
 */
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    m_game.onKeyPress( event->key() );
}

void MainWindow::on_previous_clicked()
{
    if(m_game.m_nLevel==0)//還沒進入關卡前，點擊它不會有作用
    {
        return;
    }
    if(m_game.m_nLevel!=1)
    {
        m_game.gotoLevel(m_game.m_nLevel-1);
        ui->level->setNum(m_game.m_nLevel);
    }
    else
    {
        QMessageBox::information( m_game.m_gameBoard, NULL, tr("已經是最前面的關卡") );
    }
    this->reset();
}

void MainWindow::on_next_clicked()
{
    if(m_game.m_nLevel==0)//還沒進入關卡前，點擊它不會有作用
    {
        return;
    }
    if(m_game.m_nLevel!=5)
    {
        m_game.gotoLevel(m_game.m_nLevel+1);
        ui->level->setNum(m_game.m_nLevel);
    }
    else
    {
        QMessageBox::information( m_game.m_gameBoard, NULL, tr("已經是最後的關卡") );
    }
    this->reset();
}

void MainWindow::on_restart_clicked()
{
    m_game.replay();
    ui->level->setNum(m_game.m_nLevel);
    this->reset();
}

void MainWindow::on_quit_clicked()
{
    exit(0);
}

void MainWindow::add()
{
    num++;
    ui->steps->setNum(num);
}

void MainWindow::reset()
{
    num=0;
    ui->steps->setNum(num);
}

void MainWindow::saved()
{
    ui->record->setNum(m_game.m_nrecord);
}

void MainWindow::display()
{
    ui->previous->show();
    ui->next->show();
    ui->restart->show();
    ui->quit->show();
    ui->show->show();
    ui->show_2->show();
    ui->show_3->show();
    ui->steps->show();
    ui->level->show();
    ui->record->show();
}

void MainWindow::levelChange()
{
    ui->level->setNum(m_game.m_nLevel);
}

void MainWindow::on_quitButton_clicked()
{
    exit(0);
}

void MainWindow::on_button1_clicked()
{
    m_game.gotoLevel(1);
    ui->level->setNum(1);
}

void MainWindow::on_button2_clicked()
{
    m_game.gotoLevel(2);
    ui->level->setNum(2);
}

void MainWindow::on_button3_clicked()
{
    m_game.gotoLevel(3);
    ui->level->setNum(3);
}

void MainWindow::on_button4_clicked()
{
    m_game.gotoLevel(4);
    ui->level->setNum(4);
}

void MainWindow::on_button5_clicked()
{
    m_game.gotoLevel(5);
    ui->level->setNum(5);
}


void MainWindow::on_playButton_clicked()
{
    //刪除PLAY&QUIT
    delete(ui->playButton);
    delete(ui->quitButton);    
    //顯示關卡目錄標題
    QLabel* select = new QLabel("Select Level",this);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    select->setPalette(pe);
    QFont ft;
    ft.setPointSize(14);
    select->setFont(ft);
    //關卡選擇鈕
    QPushButton* button1 = new QPushButton("LEVEL1",this);
    QPushButton* button2 = new QPushButton("LEVEL2",this);
    QPushButton* button3 = new QPushButton("LEVEL3",this);
    QPushButton* button4 = new QPushButton("LEVEL4",this);
    QPushButton* button5 = new QPushButton("LEVEL5",this);
    //定位置跟大小
    select->setGeometry(120, 65, 130, 34);
    button1->setGeometry(120, 115, 112, 34);
    button2->setGeometry(120, 165, 112, 34);
    button3->setGeometry(120, 215, 112, 34);
    button4->setGeometry(120, 265, 112, 34);
    button5->setGeometry(120, 315, 112, 34);
    //顯示
    select->show();
    button1->show();
    button2->show();
    button3->show();
    button4->show();
    button5->show();
    //連接signal and slot
    connect(button1,SIGNAL(clicked()),this,SLOT(on_button1_clicked()));
    connect(button1,SIGNAL(clicked()),button1,SLOT(hide()));
    connect(button1,SIGNAL(clicked()),button2,SLOT(hide()));
    connect(button1,SIGNAL(clicked()),button3,SLOT(hide()));
    connect(button1,SIGNAL(clicked()),button4,SLOT(hide()));
    connect(button1,SIGNAL(clicked()),button5,SLOT(hide()));
    connect(button1,SIGNAL(clicked()),select,SLOT(hide()));

    connect(button2,SIGNAL(clicked()),this,SLOT(on_button2_clicked()));
    connect(button2,SIGNAL(clicked()),button1,SLOT(hide()));
    connect(button2,SIGNAL(clicked()),button2,SLOT(hide()));
    connect(button2,SIGNAL(clicked()),button3,SLOT(hide()));
    connect(button2,SIGNAL(clicked()),button4,SLOT(hide()));
    connect(button2,SIGNAL(clicked()),button5,SLOT(hide()));
    connect(button2,SIGNAL(clicked()),select,SLOT(hide()));

    connect(button3,SIGNAL(clicked()),this,SLOT(on_button3_clicked()));
    connect(button3,SIGNAL(clicked()),button1,SLOT(hide()));
    connect(button3,SIGNAL(clicked()),button2,SLOT(hide()));
    connect(button3,SIGNAL(clicked()),button3,SLOT(hide()));
    connect(button3,SIGNAL(clicked()),button4,SLOT(hide()));
    connect(button3,SIGNAL(clicked()),button5,SLOT(hide()));
    connect(button3,SIGNAL(clicked()),select,SLOT(hide()));

    connect(button4,SIGNAL(clicked()),this,SLOT(on_button4_clicked()));
    connect(button4,SIGNAL(clicked()),button1,SLOT(hide()));
    connect(button4,SIGNAL(clicked()),button2,SLOT(hide()));
    connect(button4,SIGNAL(clicked()),button3,SLOT(hide()));
    connect(button4,SIGNAL(clicked()),button4,SLOT(hide()));
    connect(button4,SIGNAL(clicked()),button5,SLOT(hide()));
    connect(button4,SIGNAL(clicked()),select,SLOT(hide()));

    connect(button5,SIGNAL(clicked()),this,SLOT(on_button5_clicked()));
    connect(button5,SIGNAL(clicked()),button1,SLOT(hide()));
    connect(button5,SIGNAL(clicked()),button2,SLOT(hide()));
    connect(button5,SIGNAL(clicked()),button3,SLOT(hide()));
    connect(button5,SIGNAL(clicked()),button4,SLOT(hide()));
    connect(button5,SIGNAL(clicked()),button5,SLOT(hide()));
    connect(button5,SIGNAL(clicked()),select,SLOT(hide()));
}

