#include "Game.h"
#include "Enemy.h"
#include "Hole.h"
#include "Platform.h"
#include "Button.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QDebug>


extern Game * game;

Game::Game(QWidget *parent){

    //建立screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,600);

    //建立第一個場景
    scene1= new QGraphicsScene;
    scene1->setSceneRect(0,0,400,600);
    setScene(scene1);
    setBackgroundBrush(QPixmap(":/res/original.png").scaled(400, 600));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,600);


}

void Game::start()
{
    //先清除menu物件
    scene1->clear();

    //初始化變數
    sy=580;
    dy=0;
    h=100;
    state=1;
    scores=0;
    here=1;

    //建立 player item
    player = new Player();
    scene1->addItem(player);//場景中添加player

    //讓event被player接收
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //產生分數
    score = new Score();
    scene1->addItem(score);

    //產生怪獸
    QTimer *timer1=new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn()));
    timer1->start(30000);//每30秒產生一個怪獸

    //產生洞
    QTimer *timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(setHole()));
    timer2->start(40000);//每40秒產生一個洞

    //產生跳台
    for(int i=0;i<8;++i){
        platform[i] =new Platform();
        px[i]=rand()%330;//0~330
        platform[i]->setPos(px[i],py[i]);
        scene1->addItem(platform[i]);
    }
    //產生彈簧一
    prop1=new Prop1();
    prop1->setPos(px[2]+10,py[2]-15);
    prop12=new Prop1();
    prop12->setPos(px[6]+10,py[6]-15);
    scene1->addItem(prop1);
    scene1->addItem(prop12);

    //產生
    prop2=new Prop2();
    prop2->setPos(px[0]+20,py[0]-20);
    scene1->addItem(prop2);

    //產生跳一下就消失且會移動的跳台
    for(int i=0;i<2;++i){
        breaks[i]=new Break();
        bx[i]=rand()%330;
        breaks[i]->setPos(bx[i],by[i]);
        scene1->addItem(breaks[i]);
    }



    //讓doodle跳
    QTimer *timer3=new QTimer();
    timer3->start(70);
    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(jump()));

    QTimer *timer4=new QTimer();
    for(int i=0;i<7;++i){
        QObject::connect(timer4,SIGNAL(timeout()),platform[i],SLOT(move()));
    }
     timer4->start(1400);

}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Doodle Jump"));
    QFont titleFont("chiller",38);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene1->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene1->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene1->addItem(quitButton);

}

void Game::loseMenu(){
    scene1->clear();


    // create the gameover text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Game Over"));
    QFont titleFont("chiller",38);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 190;
    titleText->setPos(txPos,tyPos);
    scene1->addItem(titleText);

    //create final score
    score = new Score();
    score->setPlainText(QString("Score: ") + QString::number(game->scores));
    score->setDefaultTextColor(Qt::black);
    score->setFont(QFont("chiller",20));
    score->setPos(this->width()/2 - score->boundingRect().width()/2,170);
    scene1->addItem(score);

    // create the replay button
    Button* restartButton = new Button(QString("Play Again"));
    int bxPos = this->width()/2 - restartButton->boundingRect().width()/2;
    int byPos = 275;
    restartButton->setPos(bxPos,byPos);
    connect(restartButton,SIGNAL(clicked()),this,SLOT(start()));
    scene1->addItem(restartButton);

}


void Player::jump()
{
    if(game->sy<=580 && game->sy>0 && game->state==1){//上升
        game->dy-=2;
        game->sy+=game->dy;
        if(game->sy<=238){
            game->dy=0;
            //game->sy=0;
            game->state=0;
        }
    }else if(game->sy>=0 && game->sy<580 && game->state==0){//下降
        game->dy+=2;
        game->sy+=game->dy;
        if(game->sy>=580){
            game->dy=0;
            game->state=1;
        }
    }

    setPos(x(),game->sy);

    //player碰到最下面，就死掉
    if(game->player->y()>=580){
        game->loseMenu();
    }


}

void Platform::move(){
    for(int i=0;i<8;++i){
        game->py[i]+=5;
        if(game->py[i]>=570){
            game->py[i]=20;
        }
        game->platform[i]->setPos(game->px[i],game->py[i]);
    }

    for(int i=0;i<2;++i){
        /*game->bx[i]+=2;
        if(game->bx[i]>=330){
            game->bx[i]=0;
        }*/
        game->by[i]+=5;
        if(game->by[i]>=570){
           game->by[i]=20;
        }
        game->breaks[i]->setPos(game->bx[i],game->by[i]);
    }
    if(game->here==0){
        scene()->addItem(game->breaks[0]);
        scene()->addItem(game->breaks[1]);
        game->here=1;
    }

    game->prop1->setPos(game->px[2]+10,game->py[2]-15);
    game->prop12->setPos(game->px[6]+10,game->py[6]-15);
    game->prop2->setPos(game->px[0]+20,game->py[0]-20);
    game->score->plus();


}


