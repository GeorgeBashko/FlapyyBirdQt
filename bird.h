#ifndef BIRD_H
#define BIRD_H
#include "qevent.h"
#include<QPainter>
#include<QPoint>
#include<QImage>

class bird
{
public:
    bird(QPoint p);
    void drawBird(QPainter* paint);
    void setskin(QString s);
    QString GetSkin();
    void setCenter(QPoint c);
    QPoint getCenter();
    void incBirdSpeed(QKeyEvent* event);
    void moveBird();
    void BirdDeath();
    void BirdRestart();
    void SetGravity(int);
    void SetBirdSpeed(int);
    void MoveWings(int a);
    int getUgl();

private:
    int bird_vel;
    int x;
    int inc_v;
    int gr;
    int ugl;
    QPoint center;
    QString skin;
    QString* wings1[4];
    QString* wings2[4];
    QString* wings3[4];
    int i;
};

#endif // BIRD_H
