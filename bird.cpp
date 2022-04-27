#include "bird.h"
#include "QPixmap"
#include "QPoint"
#include "QImage"
bird::bird(QPoint p):center(p)
{}
void bird::drawBird(QPainter* paint)
{
    QImage im("D:/Qt/QtProjects/Project1/bbb4.png");
    paint->drawImage(center.x()-25,center.y()-25,im);
}
