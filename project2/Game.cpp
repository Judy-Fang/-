#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCoreApplication>
#include "Game.h"
#include "Mainwindow.h"
#include "ui_MainWindow.h"

Spirit* Game::s_spirits[Const::GAMEBOARD_GRID_COUNT_V][Const::GAMEBOARD_GRID_COUNT_H];

/**
 * 建構子
 */
Game::Game() :
    m_gameBoard(NULL),
    m_bitmap(NULL),
    m_status(END),
    m_man(NULL),
    m_nBoxCount(0)
{
    memset( s_spirits, 0, sizeof(s_spirits) );

    //連接signal and slot
    QObject::connect( &m_timer, SIGNAL(timeout()), SLOT(onTimer()) );

}

/**
 * 建構子
 */
Game::~Game()
{
    this->deleteAllSpirits();
}

/**
 * 創建遊戲
 * @param mainWindow    主視窗
 * @param gameBoard     遊戲區域
 * @param bitmap        遊戲區域圖
 */
void Game::create(QWidget* mainWindow, QWidget* gameBoard, QPixmap* bitmap)
{
    //初始化成員
    m_mainWindow = mainWindow;
    m_gameBoard = gameBoard;
    m_bitmap = bitmap;
}

QFile file1("record/1.txt");
QFile file2("record/2.txt");
QFile file3("record/3.txt");
QFile file4("record/4.txt");
QFile file5("record/5.txt");


/**
 * 進入關卡
 * @param nLevel
 */
void Game::gotoLevel(int nLevel)
{
    switch(nLevel)
    {
        case 1:
            if(file1.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file1);
                QString line=in.readLine();
                m_nrecord=line.toInt();
            }
            file1.close();
        break;
        case 2:
            if(file2.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file2);
                QString line=in.readLine();
                m_nrecord=line.toInt();
            }
            file2.close();
            break;
        case 3:
            if(file3.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file3);
                QString line=in.readLine();
                m_nrecord=line.toInt();
            }
            file3.close();
            break;
        case 4:
            if(file4.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file4);
                QString line=in.readLine();
                m_nrecord=line.toInt();
            }
            file4.close();
            break;
        case 5:
            if(file5.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file5);
                QString line=in.readLine();
                m_nrecord=line.toInt();
            }
            file5.close();
            break;
     }

    MainWindow::mutalUi->saved();
    MainWindow::mutalUi->display();
    //讀取關卡文件
    QFile levelFile( QString(Const::LEVEL_FILE_PATH).arg(nLevel) );
    levelFile.open(QIODevice::ReadOnly | QIODevice::Text);

    //删除當前所有精靈
    this->deleteAllSpirits();

    //重繪遊戲區域
    m_drawer.begin(m_bitmap);
    m_drawer.fillRect(0, 0, Const::GAMEBOARD_WIDTH,Const::GAMEBOARD_HEIGHT, Const::GAMEBOARD_COLOR);
    m_drawer.end();

    int nRead = 1;
    char cBuffer = 0;
    Spirit::Type spiritType;
    m_nBoxCount = 0;

    //創建所有精靈
    for (int y = 0; y < Const::GAMEBOARD_GRID_COUNT_V; y++)
    {
        for (int x = 0; x < Const::GAMEBOARD_GRID_COUNT_H; x++)
        {
            levelFile.read(&cBuffer, 1);
            if (nRead == 0)        //空白區域
            {
                continue;
            }
            if (cBuffer == '\r' || cBuffer == '\n')
            {
                x--;
                continue;
            }

            spiritType = (Spirit::Type)atoi(&cBuffer);

            // 創建箱子
            if (spiritType == Spirit::BOX)
            {
                s_spirits[y][x] = new Box( spiritType, x, y, m_bitmap,
                    new Spirit(Spirit::BACKGROUND, x, y, m_bitmap) );
                m_nBoxCount++;
                continue;
            }
            //創建小人
            else if (spiritType == Spirit::MAN)
            {
                s_spirits[y][x] = m_man = new Man( spiritType, x, y, m_bitmap,
                    m_gameBoard, new Spirit(Spirit::BACKGROUND, x, y, m_bitmap) );
                continue;
            }
            //創建背景或牆
            s_spirits[y][x] = new Spirit(spiritType, x, y, m_bitmap);
        }
    }

    //關閉文件
    levelFile.close();

    //重置成員變量
    m_nLevel = nLevel;
    MainWindow::mutalUi->levelChange();
    m_status = PLAYING;

    //開啟時鐘(讓人有動的感覺，一段時間就動)
    m_timer.start(Const::TIMER_INIT);

}

/**
 * 重玩本關
 */
void Game::replay()
{
    this->gotoLevel(m_nLevel);
}

void Game::quit()
{
    exit(0);
}

/**
 * 根據按鍵訊號，移動小人。
 * @param nKey    按键
 * 
 */
void Game::onKeyPress(int nKey)
{
    //如果沒在玩，則直接返回
    if (m_status != PLAYING)
    {
        return;
    }
    //如果按的不是WASD键，直接返回
    if(nKey!=Qt::Key_W && nKey!=Qt::Key_A && nKey!=Qt::Key_S && nKey!=Qt::Key_D ){
        return;
    }

    //移動小人。如果不能移動，則直接返回
    Box::MoveResult moveResult = m_man->move(nKey);
    if (moveResult == Box::NO_MOVE)
    {
        return;
    }
    else if(nKey==Qt::Key_W || nKey==Qt::Key_A || nKey==Qt::Key_S || nKey==Qt::Key_D )
    {
        MainWindow::mutalUi->add();
    }

    //重繪遊戲區域
    m_gameBoard->update();

    //根據移動结果，檢查是否勝利
    if (moveResult == Box::ARRIVED_ON_DEST)
    {
        m_nBoxCount--;
        this->checkWon();
    }
    else if (moveResult == Box::LEFT_FROM_DEST)
    {
        m_nBoxCount++;
    }
}

/**
 * 讓小人跳舞。
 */
void Game::onTimer()
{
    m_man->dancing();
}

/**
 * 檢查遊戲是否勝利。
 */
void Game::checkWon()
{
    //如果還有箱子未到達目的地，則直接返回
    if (m_nBoxCount != 0)
    {
        return;
    }

    // 停止時鐘
    m_timer.stop();
    m_status = END;

    //全部通關了，彈出提示視窗
    if (m_nLevel == Const::LEVEL_COUNT)
    {
        if(m_nrecord==0 || MainWindow::mutalUi->num<m_nrecord)
        {
            if(file5.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&file5);
                int a=MainWindow::mutalUi->num;
                out<<a;
            }
        file5.close();
        }
        if(file5.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file5);
            QString line=in.readLine();
            m_nrecord=line.toInt();
        }
        file5.close();
        MainWindow::mutalUi->saved();
        QMessageBox::information( m_gameBoard, NULL, tr("IDS_GAME_WON_MAX") );
    }
    //進入下一關
    else
    {
        QMessageBox::information( m_gameBoard, NULL, tr("IDS_GAME_WON") );
        switch(m_nLevel)
        {
            case 1:
            if(m_nrecord==0 ||MainWindow::mutalUi->num<m_nrecord )
            {
                if(file1.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QTextStream out(&file1);
                    int a=MainWindow::mutalUi->num;
                    out<<a;
                }
                file1.close();
            }
                break;
            case 2:
            if(m_nrecord==0 || MainWindow::mutalUi->num<m_nrecord)
            {
                if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QTextStream out(&file2);
                    int a=MainWindow::mutalUi->num;
                    out<<a;
                }
                file2.close();
            }
                break;
            case 3:
            if(m_nrecord==0 || MainWindow::mutalUi->num<m_nrecord)
            {
                if(file3.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QTextStream out(&file3);
                    int a=MainWindow::mutalUi->num;
                    out<<a;
                }
                file3.close();
            }
                break;
            case 4:
            if(m_nrecord==0 || MainWindow::mutalUi->num<m_nrecord)
            {
                if(file4.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QTextStream out(&file4);
                    int a=MainWindow::mutalUi->num;
                    out<<a;
                }
                file4.close();
            }
                break;
        }
        MainWindow::mutalUi->reset();//歸零步數
        m_nrecord=0;//記錄重置
        this->gotoLevel(m_nLevel + 1);
    }
}

/**
 * 删除所有精靈
 */
void Game::deleteAllSpirits()
{
    for (int i = 0; i < Const::GAMEBOARD_GRID_COUNT_V; i++)
    {
        for (int j = 0; j < Const::GAMEBOARD_GRID_COUNT_H; j++)
        {
            if (s_spirits[i][j] != NULL)
            {
                delete s_spirits[i][j];
            }
        }
    }
    memset( s_spirits, 0, sizeof(s_spirits) );
}
