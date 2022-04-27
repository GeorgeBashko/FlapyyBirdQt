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
private:
    int x;
    int y;
    int high;
    QPixmap* pix1;
    QPixmap* pix2;
};

#endif
