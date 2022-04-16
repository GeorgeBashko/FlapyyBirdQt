#ifndef RECT_H
#define RECT_H
#include<QPoint>
#include<QPainter>
class Rect
{
public:
    Rect(int x,int y,int h);
    void DrawRect(QPainter *paint);
private:
    int x;
    int y;
    int high;
};

#endif
