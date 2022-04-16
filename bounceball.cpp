#include "bounceball.h"
#include"rect.h"
#include "./ui_bounceball.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include<iostream>
#include<QPixmap>

BounceBall::BounceBall(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BounceBall),p1(600,0),p3(950,0),p1_h(300),p3_h(400),rect_x_vel(-4)
{
    ui->setupUi(this);
    QTimer* ptimer = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(moveRect()));
    ptimer->start(25);
}
BounceBall::~BounceBall()
{
    delete ui;
}
void BounceBall::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        QImage im3("D:/Qt/QtProjects/Project1/im3.png","PNG");
        QBrush bg(im3);
        painter.fillRect(0, 0, this->width(), this->height(), bg);
        QPen blackP(Qt::white);
        painter.setPen(blackP);
        Rect r1(p1.x(),p1.y(),p1_h);
        Rect r2(p3.x(),p3.y(),p3_h);
        r1.DrawRect(&painter);
        r2.DrawRect(&painter);
}
void BounceBall::moveRect()
{
    p1.setX(p1.x() + rect_x_vel);
    p3.setX(p3.x() + rect_x_vel);
/*
    if (ball.y() + radius >= this->height())
    {
        y_vel = 0;
    }
    if(ball.y() <cur_y -60)
    {
       y_vel = 8;
    }
    */
      if(p1.x() <= -100 && p1.x()>= -105 )
      {
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    p1_h = rand() % 270 + 50;
    p1.setX(610);
      }
      if(p3.x() <= -100 && p3.x()>= -105 )
      {
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    p3_h = rand() % 200 + 20;
    p3.setX(610);
      }
    this->update();
}
/*
void BounceBall::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
         cur_y = ball.y();
         y_vel = -5;
    }
}
*/
