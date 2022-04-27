#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H

#include <QMainWindow>
#include <QPoint>
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class BounceBall; }
QT_END_NAMESPACE

class BounceBall : public QMainWindow
{
    Q_OBJECT

public:
    BounceBall(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent *event);
   // void push_button_clicked();
    ~BounceBall();
public slots:
    void moveRect();

private:
    Ui::BounceBall *ui;
    QPoint p1;
    QPoint p3;
    QPixmap* pix;
    int p1_h;
    int p3_h;
    int rect_x_vel;
    int bird_vel;
    QPoint p2;

};
#endif // BOUNCEBALL_H
