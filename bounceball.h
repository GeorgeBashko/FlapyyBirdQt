#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H

#include <QMainWindow>
#include <QPoint>
#include<QPixmap>
#include<QString>
#include<QTimer>
//#include "menu.h"
#include<QPushButton>

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
    void GameOver(QPainter* painter,QString message);
    void Restart();
    void leaderBoard();
    void DrawScore(QPainter* painter,QString score);
    void checkBest();
    ~BounceBall();
public slots:
    void moveRect();
    void checkCrash();
    void moveBird();
    void incScore();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::BounceBall *ui;
    QPoint p1;
    QPoint p3;
    QPoint p2;
    QPoint pl;
    QPixmap* pix;
    int p1_h;
    int p3_h;
    int rect_x_vel;
    int bird_vel;
    int grav;
    int intScore;
    int intBestScore;
    QString score;
    QString bestScore;
    QTimer* ptimer;
    QTimer* ptimer2;
    bool gameOver;
};
#endif // BOUNCEBALL_H
