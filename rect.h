#ifndef RECT_H
#define RECT_H
#include<QPoint>
#include<QPainter>
#include<QPixmap>

class Rect
{
public:
    Rect(int x,int y,int h);
    void DrawRect(QPainter *paint);
    void SetRectSkin(QString,QString);

    void MoveRect();
    int getX();
    void setX(int);
    int getHigh();

private:
    int rect_vel;
    QPoint p1;
    QPoint p2;
    int x;
    int y;
    int high;
    QPixmap* pix1;
    QPixmap* pix2;
    QString up_skin;
    QString down_skin;
};

#endif
