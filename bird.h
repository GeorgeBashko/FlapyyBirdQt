#ifndef BIRD_H
#define BIRD_H
#include<QPainter>
#include<QPoint>
#include<QPixmap>

class bird
{
public:
    bird(QPoint p);
    void drawBird(QPainter* paint);
private:
    QPixmap* pix3;
    QPoint center;
};

#endif // BIRD_H
