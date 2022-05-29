#include "bounceball.h"
#include<QPixmap>
#include <QApplication>
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BounceBall w;
    QIcon i1;
    QPixmap *pix = new QPixmap("D:/Qt/QtProjects/Project1/skin1.png");
    i1.addPixmap(*pix);
    w.setWindowIcon(i1);
    w.setWindowTitle("FlappyBird");
    w.show();
    w.setFixedSize(600,600);
    return a.exec();
}
