#include "bounceball.h"
#include<QPixmap>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BounceBall w;
    w.show();
    w.setFixedSize(600,600);
    return a.exec();
}
