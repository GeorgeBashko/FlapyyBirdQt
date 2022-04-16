#include "rect.h"
#include<QBrush>
#include <QImage>

Rect::Rect(int x1,int y1,int h):x(x1),y(y1),high(h)
{}
void Rect::DrawRect(QPainter *paint)
{
    paint->drawRect(x,y,100,high);
    paint->drawRect(x,high+150,100,1000);
    QImage im1("D:/Qt/QtProjects/Project1/im1.png");
    QImage im2("D:/Qt/QtProjects/Project1/im2.png");
    QBrush b1(im2);
    QBrush b2(im1);
    paint->fillRect(x,y,100,high,b1);
    paint->fillRect(x,high+150,100,1000,b2);
}
