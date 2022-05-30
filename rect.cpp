#include "rect.h"
#include "qdatetime.h"
#include<QBrush>
#include <QImage>
#include<iostream>
Rect::Rect(int x1,int y1,int h):x(x1),y(y1),high(h),up_skin("D:/Qt/QtProjects/Project1/RectUpSkin2.png"),down_skin("D:/Qt/QtProjects/Project1/RectDownSkin2.png")
  ,rect_vel(-5)
{}
void Rect::DrawRect(QPainter *paint)
{
    pix1 = new QPixmap(down_skin);
    pix2 = new QPixmap(up_skin);
    paint->drawPixmap(x,-250,90,high+200,*pix1);
    paint->drawPixmap(x,high+50,90,500,*pix2);
}
void Rect::SetRectSkin(QString s1,QString s2)
{
    up_skin = s1;
    down_skin = s2;
}
void Rect::MoveRect()
{
    x+= rect_vel;
    if(x <= -100 && x>= -120)
      {
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    high = rand() % 300 + 150;
    x = 610;
      }
}
int Rect::getX()
{
    return x;
}
void Rect::setX(int b)
{
    x = b;
}
int Rect::getHigh()
{
    return high;
}
