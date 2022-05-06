#include "bounceball.h"
#include "menu.h"
#include<QPixmap>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BounceBall w;
    w.setWindowTitle("FlappyBird");
    w.show();
    w.setFixedSize(600,600);
    return a.exec();
}
