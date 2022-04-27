#include "rect.h"
#include<QBrush>
#include <QImage>

Rect::Rect(int x1,int y1,int h):x(x1),y(y1),high(h)
{}
void Rect::DrawRect(QPainter *paint)
{
    pix1 = new QPixmap("D:/Qt/QtProjects/Project1/im7.png");
    pix2 = new QPixmap("D:/Qt/QtProjects/Project1/im2.png");
    paint->drawPixmap(x,y-50,80,high,*pix1);
    paint->drawPixmap(x,high+50,80,500,*pix2);
}
