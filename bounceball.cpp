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
#include<QPushButton>

#include<QFile>
#include <QTextStream>


BounceBall::BounceBall(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BounceBall),p1(600,0),p3(952,0),p2(150,150),score("0"),intScore(0),gameOver(false),bestScore("0"),intBestScore(0),pl(0,540),pl1(593,540),skin("0"),b1(p2),i(0),a(1),
      u(0),r1(p1.x(),p1.y(),300),r2(p3.x(),p3.y(),400),RectUpSkin("D:/Qt/QtProjects/Project1/RectUpSkin1.png"),RectDownSkin("D:/Qt/QtProjects/Project1/RectDownSkin1.png")
{
    ui->setupUi(this);
    ptimer = new QTimer(this);
    ptimer2 = new QTimer(this);
    ptimer3 = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(moveRect()));
    connect(ptimer, SIGNAL(timeout()), SLOT(BirdWings()));
    connect(ptimer, SIGNAL(timeout()), SLOT(moveLine()));
    connect(ptimer, SIGNAL(timeout()), SLOT(checkCrash()));
    connect(ptimer2, SIGNAL(timeout()), SLOT(moveAll()));
    connect(ptimer3, SIGNAL(timeout()), SLOT(incScore()));
    ui->pushButton->hide();
    BackSkin = "D:/Qt/QtProjects/Project1/BackSkin2.png";
}
void BounceBall::Restart()
{
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_2->hide();
    ptimer3->start();
    ptimer->start();
    b1.setCenter({150,150});
    r1.setX(600);
    r2.setX(952);
    pl.setX(0);
    pl1.setX(593);
    score = "0";
    intScore = 0;
    b1.BirdRestart();
    gameOver = false;
    CheckNewSettingsSpeed();
    CheckSkinAndBackgroundAndPipes();
}

void BounceBall::CheckNewSettingsSpeed()
{
    if(s1.getBirdSpeed13() == true)
    {
        b1.SetBirdSpeed(13);
    }
    if(s1.getBirdSpeed7() == true)
    {
        b1.SetBirdSpeed(7);
    }
    if(s1.getBirdSpeed10() == true)
    {
        b1.SetBirdSpeed(10);
    }
    if(s1.getRectSpeed10() == true)
    {
        rect_x_vel = -9;
        ptimer3->setInterval(30);
    }
    if(s1.getRectSpeed7() == true)
    {
        rect_x_vel = -7;
        ptimer3->setInterval(31);
    }
    if(s1.getRectSpeed5() == true)
    {
        rect_x_vel = -5;
        ptimer3->setInterval(62);
    }
    if(s1.getGravity1() == true)
    {
        b1.SetGravity(1);
    }
    if(s1.getGravity2() == true)
    {
        b1.SetGravity(2);
    }
}
void BounceBall::CheckSkinAndBackgroundAndPipes()
{
    if(s1.getBirdSkin1() == true)
    {
       b1.setskin("D:/Qt/QtProjects/Project1/skin1.png");
       a =1;
    }
    if(s1.getBirdSkin2() == true)
    {
       b1.setskin("D:/Qt/QtProjects/Project1/skin2.png");
       a =2;
    }
    if(s1.getBirdSkin3() == true)
    {
       b1.setskin("D:/Qt/QtProjects/Project1/skin3.png");
       a =3;
    }
    if(s1.getBackSkin1() == true)
    {
       BackSkin = "D:/Qt/QtProjects/Project1/BackSkin1.png";
    }
    if(s1.getBackSkin2() == true)
    {
       BackSkin = "D:/Qt/QtProjects/Project1/BackSkin2.png";
    }
    if(s1.getBackSkin3() == true)
    {
       BackSkin = "D:/Qt/QtProjects/Project1/BackSkin3.png";
    }
    if(s1.getRectSkin1() == true)
    {
        RectUpSkin  = "D:/Qt/QtProjects/Project1/RectUpSkin1.png";
        RectDownSkin  = "D:/Qt/QtProjects/Project1/RectDownSkin1.png";
    }
    if(s1.getRectSkin2() == true)
    {
        RectUpSkin  = "D:/Qt/QtProjects/Project1/RectUpSkin2.png";
        RectDownSkin  = "D:/Qt/QtProjects/Project1/RectDownSkin2.png";
    }
    if(s1.getRectSkin3() == true)
    {
        RectUpSkin  = "D:/Qt/QtProjects/Project1/RectUpSkin3.png";
        RectDownSkin  = "D:/Qt/QtProjects/Project1/RectDownSkin3.png";
    }
}
void BounceBall::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        QImage im3(BackSkin);
        QBrush bg(im3);
        painter.fillRect(0, 0, this->width(), this->height(), bg);
        QPixmap* pix3 = new QPixmap("D:/Qt/QtProjects/Project1/line.png");
        painter.drawPixmap(pl.x(),pl.y(),635,12,*pix3);
        QPixmap* pix4 = new QPixmap("D:/Qt/QtProjects/Project1/line.png");
        painter.drawPixmap(pl1.x(),pl1.y(),635,12,*pix4);
        r1.SetRectSkin(RectUpSkin,RectDownSkin);
        r2.SetRectSkin(RectUpSkin,RectDownSkin);
        r1.DrawRect(&painter);
        r2.DrawRect(&painter);
        score = QString("%1").arg(intScore);
        QFont font("Red", 35, QFont::DemiBold);
        painter.setPen(Qt::black);
        if(s1.getBackSkin1())
        painter.setPen(Qt::red);
        if(s1.getBackSkin3())
        painter.setPen(Qt::yellow);
        painter.setFont(font);
        painter.drawText(300,100,score);
        pix1 = new QPixmap("D:/Qt/QtProjects/Project1/back_low.png");
        painter.drawPixmap(0,552,600,60,*pix1);
        painter.save();
        painter.translate(b1.getCenter().x()+34,b1.getCenter().y()+24);
        painter.rotate(b1.getUgl());
        painter.drawPixmap( -34, -24, 34, 24, b1.GetSkin());
        painter.restore();
        b1.drawBird(&painter);
        if(gameOver)
        GameOver(&painter,"der Kapitulation");
        this->update();
}
void BounceBall::BirdWings()
{
    b1.MoveWings(a);
    this->update();
}
void BounceBall::moveLine()
{
    pl.setX(pl.x() + rect_x_vel);
    pl1.setX(pl1.x() + rect_x_vel);
    if(pl.x()<=-593 && pl.x()<=-598)
    {
       pl.setX(593);
    }
    if(pl1.x()<=-593 && pl1.x()>=-598)
    {
       pl1.setX(593);
    }
}
void BounceBall::moveRect()
{
   r1.MoveRect();
   r2.MoveRect();
   this->update();
}
void BounceBall::moveAll()
{
    b1.moveBird();
    this->update();
}
void BounceBall::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        b1.incBirdSpeed(event);
    }
    if(event->key() == Qt::Key_S)
    {
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ptimer->start(20);
        ptimer2->start(20);
        ptimer3->start(62);
    }
}
void BounceBall::checkCrash()
{
    if(r1.getX()<=188 && r1.getX()+90>=150)
   {
        if(b1.getCenter().y()<-50+r1.getHigh() || b1.getCenter().y()>= r1.getHigh()+24)
        {
           gameOver = true;
        }
   }
    else
        if(r2.getX()<=188 && r2.getX()+90>=150)
       {
            if( b1.getCenter().y()<-50+r2.getHigh() || b1.getCenter().y()>= r2.getHigh()+24)
            {
                gameOver = true;
            }
       }
    if(b1.getCenter().y()+ 26>= 540)
    {
        gameOver = true;
    }
}
void BounceBall::incScore()
{
            if(r1.getX() >= 109 && r1.getX()<=117 || r2.getX()>= 109 && r2.getX()<=117)
            {
                intScore++;
            }
}
void BounceBall::GameOver(QPainter *painter, QString message)
{
       ptimer->stop();
       ptimer3->stop();
       b1.BirdDeath();
       if(b1.getCenter().y()+26 >= 540)
       {
             ptimer->stop();
             QFont font("Courier", 15, QFont::DemiBold);
             painter->setFont(font);
             int h = height();
             int w = width();
             painter->translate(QPoint(w/2, h/2));
             painter->drawText(-100, 50, message);
             ui->pushButton->show();
             ui->pushButton_3->show();
             ui->pushButton_2->show();
             checkBest();
             DrawScore(painter,score);
             ui->pushButton_3->setEnabled(true);
             ui->pushButton_2->setEnabled(true);
             ui->pushButton->setEnabled(true);
       }
}
void BounceBall::OpenSettings()
{
    QIcon q1;
    QPixmap* pix5 = new QPixmap("D:/Qt/QtProjects/Project1/Settings.png");
    q1.addPixmap(*pix5);
    s1.setFixedSize(415,421);
    s1.setWindowTitle("Settings");
    s1.setWindowIcon(q1);
    s1.setModal(true);
    s1.show();
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
void BounceBall::on_pushButton_clicked()
{
    ui->pushButton->hide();
    Restart();
}
void BounceBall::on_pushButton_2_clicked()
{
    OpenSettings();
}
void BounceBall::on_pushButton_3_clicked()
{
    hide();
}
BounceBall::~BounceBall()
{
    delete ui;
}
