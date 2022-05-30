#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H


#include <QMainWindow>
#include <QPoint>
#include<QPixmap>
#include<QString>
#include<QTimer>
#include<QPushButton>
#include<QStringList>
#include "rect.h"
#include"settings.h"
#include "bird.h"


QT_BEGIN_NAMESPACE
namespace Ui { class BounceBall; }
QT_END_NAMESPACE

class BounceBall : public QMainWindow
{
    Q_OBJECT

public:
    BounceBall(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void GameOver(QPainter* painter,QString message);
    void Restart();
    void OpenSettings();
    void DrawScore(QPainter* painter,QString score);
    void checkBest();
    void BackStyle1();
    void CheckNewSettingsSpeed();
    void GameInit();
    void CheckSkinAndBackgroundAndPipes();
    ~BounceBall();
public slots:
    void moveRect();
    void checkCrash();
    void moveAll();
    void moveLine();
    void incScore();
    void BirdWings();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::BounceBall *ui;
    int a;
    int u;
    int i;
    QString s;
    QString* wings1[4];
    QString* wings2[4];
    QString* wings3[4];
    QString* rects[6];
    QString RectUpSkin;
    QString RectDownSkin;
    QPoint p1;
    QPoint p3;
    QPoint p2;
    QPoint pl;
    QPoint pl1;
    bird b1;
    Rect r1;
    Rect r2;
    QPixmap* pix;
    QPixmap* pix1;
    int intScore;
    int intBestScore;
    QString score;
    QString bestScore;
    QString skin;
    QString BackSkin;
    QTimer* ptimer;
    QTimer* ptimer2;
    QTimer* ptimer3;
    Settings s1;
    bool gameOver;
};
#endif // BOUNCEBALL_H
