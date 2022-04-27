#include "bounceball.h"
#include"rect.h"
#include"bird.h"
#include "./ui_bounceball.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include<QPixmap>

BounceBall::BounceBall(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BounceBall),p1(600,0),p3(950,0),p1_h(300),p3_h(400),rect_x_vel(-4),p2(150,150),bird_vel(-1)
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
        Rect r1(p1.x(),p1.y(),p1_h);
        Rect r2(p3.x(),p3.y(),p3_h);
        r1.DrawRect(&painter);
        r2.DrawRect(&painter);
        bird b1(p2);
        b1.drawBird(&painter);
}
void BounceBall::moveRect()
{
    bird_vel--;
    p1.setX(p1.x() + rect_x_vel);
    p3.setX(p3.x() + rect_x_vel);
    p2.setY(p2.y() - bird_vel);
      if(p1.x() <= -100 && p1.x()>= -105 )
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
void BounceBall::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        bird_vel = 10;
    }
    /*
    if(event->key() == Qt::Key_Space)
    {
        rect_x_vel = -4;
        bird_vel = -1;
    }
    */
}
