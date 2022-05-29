#include "bird.h"
#include "QPixmap"
#include "QPoint"
#include "QImage"
#include <iostream>
bird::bird(QPoint p):center(p),x(0),bird_vel(-1),inc_v(10),gr(1),skin("D:/Qt/QtProjects/Project1/skin1.png")
{
    wings1[0] = new QString("D:/Qt/QtProjects/Project1/skin1.png");
    wings1[1] = new QString("D:/Qt/QtProjects/Project1/skin1up.png");
    wings1[2] = new QString("D:/Qt/QtProjects/Project1/skin1.png");
    wings1[3] = new QString("D:/Qt/QtProjects/Project1/skin1down.png");
    wings2[0] = new QString("D:/Qt/QtProjects/Project1/skin2.png");
    wings2[1] = new QString("D:/Qt/QtProjects/Project1/skin2up.png");
    wings2[2] = new QString("D:/Qt/QtProjects/Project1/skin2.png");
    wings2[3] = new QString("D:/Qt/QtProjects/Project1/skin2down.png");
    wings3[0] = new QString("D:/Qt/QtProjects/Project1/skin3.png");
    wings3[1] = new QString("D:/Qt/QtProjects/Project1/skin3up.png");
    wings3[2] = new QString("D:/Qt/QtProjects/Project1/skin3.png");
    wings3[3] = new QString("D:/Qt/QtProjects/Project1/skin3down.png");
    i= 0;
}

void bird::drawBird(QPainter* paint)
{
    QImage im(skin);
    paint->drawImage(center.x(),center.y(),im);
}

void bird::incBirdSpeed(QKeyEvent* event)
{
    ugl = -30;
    bird_vel = inc_v;
}
void bird::BirdDeath()
{
    gr =0;
    bird_vel = -20;
    inc_v = 0;
    if(center.y()+26 >= 540)
    {
        bird_vel = 0;
    }
}
void bird::moveBird()
{
    if(bird_vel>=-15)
    bird_vel-=gr;
    center.setY(center.y() - bird_vel);
    if(bird_vel<= -2)
        ugl += 8;
    if(ugl >= 30){
         ugl = 30;
     }
}
void bird::BirdRestart()
{
    gr = 1;
    bird_vel = -1;
    inc_v = 10;
    ugl = 0;
}
void bird::MoveWings(int a)
{
     i = (i+1)%4;
    if(a == 1)
    {
      skin = *wings1[i];
    }
    if(a == 2)
    {
      i = (i+1)%3;
      skin = *wings2[i];
    }
    if(a == 3)
    {
      skin = *wings3[i];
    }
}
void bird::SetBirdSpeed(int n)
{
    inc_v = n;
}
void bird::SetGravity(int g)
{
    gr = g;
}
void bird::setskin(QString s)
{
    skin = s;
}
QString bird::GetSkin()
{
    return skin;
}
QPoint bird::getCenter()
{
    return center;
}
void bird::setCenter(QPoint c)
{
    center = c;
}
int bird::getUgl()
{
    return ugl;
}
