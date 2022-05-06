#include "bounceball.h"
#include"rect.h"
#include"bird.h"
#include "./ui_bounceball.h"
#include <QPainter>
#include <QBrush>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include<QPixmap>
#include<QFontMetrics>
#include<iostream>
#include "menu.h"
#include<QPushButton>

BounceBall::BounceBall(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BounceBall),p1(600,0),p3(952,0),p1_h(300),p3_h(400),rect_x_vel(-5),p2(150,150),bird_vel(-1),grav(1),score("0"),intScore(0),gameOver(false),bestScore("0"),intBestScore(0),pl(0,540)
{
    ui->setupUi(this);
    ptimer = new QTimer(this);
    ptimer2 = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(moveRect()));
    connect(ptimer, SIGNAL(timeout()), SLOT(checkCrash()));
    connect(ptimer2, SIGNAL(timeout()), SLOT(moveBird()));
    connect(ptimer, SIGNAL(timeout()), SLOT(incScore()));
    ui->pushButton->hide();
    ui->pushButton_2->hide();
}
void BounceBall::Restart()
{
    ui->pushButton->setEnabled(false);
    ptimer->start();
    p2.setX(150);
    p2.setY(150);
    p1.setX(600);
    p1.setY(0);
    p3.setX(952);
    p3.setY(0);
    score = "0";
    intScore = 0;
    bird_vel = -1;
    grav = 1;
    rect_x_vel = -5;
    gameOver = false;
}
void BounceBall::leaderBoard()
{
    ui->pushButton_2->setEnabled(false);
    //ui->pushButton_2->hide();
}
void BounceBall::paintEvent(QPaintEvent *event)
{
        ui->pushButton->setEnabled(true);
        QPainter painter(this);
        QImage im0("D:/Qt/QtProjects/Project1/line.png","PNG");
        QImage im3("D:/Qt/QtProjects/Project1/im3.png","PNG");
        QBrush bg(im3);
        painter.fillRect(0, 0, this->width(), this->height(), bg);
        QBrush l1(im0);
        painter.fillRect(pl.x(),pl.y(),593,12,l1);
        Rect r1(p1.x(),p1.y(),p1_h);
        Rect r2(p3.x(),p3.y(),p3_h);
        r1.DrawRect(&painter);
        r2.DrawRect(&painter);
        bird b1(p2);
        b1.drawBird(&painter);
        score = QString("%1").arg(intScore);
        QFont font("Courier", 35, QFont::DemiBold);
        painter.setFont(font);
        painter.drawText(300,100,score);
        if(gameOver)
        GameOver(&painter,"der Kapitulation");
}
void BounceBall::moveRect()
{
    p1.setX(p1.x() + rect_x_vel);
    p3.setX(p3.x() + rect_x_vel);
    //pl.setX(pl.x() - 2);
      if(p1.x() <= -100 && p1.x()>= -105)
      {
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    p1_h = rand() % 300 + 150;
    p1.setX(610);
      }
      if(p3.x() <= -100 && p3.x()>= -105 )
      {
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    p3_h = rand() % 300 + 150;
    if(p3_h>=190 && p3_h<=260)
    {
        p3_h = 400;
    }
    p3.setX(610);
      }
    this->update();
}
void BounceBall::moveBird()
{
    bird_vel-=grav;
    p2.setY(p2.y() - bird_vel);
    this->update();
}
void BounceBall::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        bird_vel = 10;
    }
    if(event->key() == Qt::Key_S)
    {
        ptimer->start(20);
        ptimer2->start(20);
    }
}
void BounceBall::checkCrash()
{
    if(p1.x()<=188 && p1.x()+90>=150)
   {
        if(p2.y()<-50+p1_h || p2.y()>= p1_h+24)
        {
           gameOver = true;
        }
   }
    else
        if(p3.x()<=188 && p3.x()+90>=150)
       {
            if( p2.y()<-50+p3_h || p2.y()>= p3_h+24)
            {
                gameOver = true;
            }
       }
    if(p2.y()+ 26>= 570)
    {
        gameOver = true;
    }
}
void BounceBall::incScore()
{
            if(p1.x() >= 109 && p1.x()<=112 || p3.x()>= 109 && p3.x()<=112)
            {
                intScore++;
            }
}
void BounceBall::GameOver(QPainter *painter, QString message)
{
       rect_x_vel = 0;
       grav = 0;
       ptimer->stop();
       bird_vel = -20;
       if(p2.y()+26 >= 595)
       {
             bird_vel = 0;
             ptimer->stop();
             QFont font("Courier", 15, QFont::DemiBold);
             painter->setFont(font);
             int h = height();
             int w = width();
             painter->translate(QPoint(w/2, h/2));
             painter->drawText(-100, 50, message);
             ui->pushButton->show();
             checkBest();
             DrawScore(painter,score);
             //ui->pushButton_2->show();
       }
}
void BounceBall::on_pushButton_clicked()
{
    ui->pushButton->hide();
    Restart();
}
void BounceBall::on_pushButton_2_clicked()
{
    ui->pushButton_2->hide();
    leaderBoard();
}
void BounceBall::DrawScore(QPainter* paint,QString score)
{
    QBrush b1 = QBrush(Qt::lightGray);
    paint->setBrush(b1);
    paint->drawRect(-150,-250,350,200);
    QFont font("Courier", 15, QFont::DemiBold);
    paint->setFont(font);
    paint->drawText(-40, -230, "You score");
    paint->drawText(-5, -140, "Best");
    QFont font1("Courier", 35, QFont::DemiBold);
    paint->setFont(font1);
    paint->drawText(0,-170,score);
    paint->drawText(0,-80,bestScore);
}
void BounceBall::checkBest()
{
    if(intScore>=intBestScore)
    {
        intBestScore = intScore;
        bestScore = QString("%1").arg(intBestScore);
    }
}
BounceBall::~BounceBall()
{
    delete ui;
}
