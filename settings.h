#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    bool getBirdSpeed13();
    bool getBirdSpeed10();
    bool getBirdSpeed7();
    bool getRectSpeed10();
    bool getRectSpeed7();
    bool getRectSpeed5();
    bool getGravity1();
    bool getGravity2();
    bool getBirdSkin1();
    bool getBirdSkin2();
    bool getBirdSkin3();
    bool getBackSkin1();
    bool getBackSkin2();
    bool getBackSkin3();
    bool getRectSkin1();
    bool getRectSkin2();
    bool getRectSkin3();
    void SetBirdSpeed();
    void SetRectSpeed();
    void SetGravity();
    void SetBirdSkin();
    void SetBackSkin();
    void SetRectSkin();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    bool BirdSpeed13;
    bool BirdSpeed10;
    bool BirdSpeed7;
    bool RectSpeed10;
    bool RectSpeed7;
    bool RectSpeed5;
    bool Gravity2;
    bool Gravity1;
    bool BirdSkin1;
    bool BirdSkin2;
    bool BirdSkin3;
    bool BackSkin1;
    bool BackSkin2;
    bool BackSkin3;
    bool RectSkin1;
    bool RectSkin2;
    bool RectSkin3;
    QTimer* timer_s;
    Ui::Settings *ui;
};

#endif // SETTINGS_H
