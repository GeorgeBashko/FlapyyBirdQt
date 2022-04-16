#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H

#include <QMainWindow>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class BounceBall; }
QT_END_NAMESPACE

class BounceBall : public QMainWindow
{
    Q_OBJECT

public:
    BounceBall(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
  //  void keyPressEvent(QKeyEvent *event);
   // void push_button_clicked();
    ~BounceBall();
public slots:
    void moveRect();

private:
    Ui::BounceBall *ui;
    QPoint p1;
    QPoint p3;
    int p1_h;
    int p3_h;
    int rect_x_vel;

};
#endif // BOUNCEBALL_H
