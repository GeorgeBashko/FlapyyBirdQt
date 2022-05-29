#include "settings.h"
#include "ui_settings.h"
#include<iostream>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include <QTimer>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings),BirdSpeed13(false),BirdSpeed10(false),BirdSpeed7(false)
{
    ui->setupUi(this);
}
Settings::~Settings()
{
    delete ui;
}
void Settings::paintEvent(QPaintEvent *event)
{
   QPainter painter_s(this);
   QImage birdSkin1("D:/Qt/QtProjects/Project1/skin1.png");
   QImage birdSkin2("D:/Qt/QtProjects/Project1/skin2.png");
   QImage birdSkin3("D:/Qt/QtProjects/Project1/skin3.png");
   QPixmap backSkin1("D:/Qt/QtProjects/Project1/BackSkin1.png");
   QPixmap backSkin2("D:/Qt/QtProjects/Project1/BackSkin2.png");
   QPixmap backSkin3("D:/Qt/QtProjects/Project1/BackSkin3.png");
   if(ui->radioButton_9->isChecked() == true)
   {
       painter_s.drawImage(180,150,birdSkin1);
       this->update();
   }
   if(ui->radioButton_10->isChecked() == true)
   {
       painter_s.drawImage(180,150,birdSkin2);
       this->update();
   }
   if(ui->radioButton_11->isChecked() == true)
   {
       painter_s.drawImage(180,150,birdSkin3);
       this->update();
   }
   if(ui->radioButton_12->isChecked() == true)
   {
       painter_s.drawPixmap(150,220,100,70,backSkin1);
       this->update();
   }
   if(ui->radioButton_13->isChecked() == true)
   {
       painter_s.drawPixmap(150,220,100,70,backSkin2);
       this->update();
   }
   if(ui->radioButton_14->isChecked() == true)
   {
       painter_s.drawPixmap(150,220,100,70,backSkin3);
       this->update();
   }
}
void Settings::on_pushButton_clicked()
{
    SetBirdSpeed();
    SetRectSpeed();
    SetGravity();
    SetBirdSkin();
    SetBackSkin();
    SetRectSkin();
    hide();
}
bool Settings::getBirdSpeed13()
{
   return BirdSpeed13;
}
bool Settings::getBirdSpeed10()
{
   return BirdSpeed10;
}
bool Settings::getBirdSpeed7()
{
   return BirdSpeed7;
}
bool Settings::getRectSpeed10()
{
    return RectSpeed10;
}
bool Settings::getRectSpeed7()
{
    return RectSpeed7;
}
bool Settings::getRectSpeed5()
{
    return RectSpeed5;
}
bool Settings::getGravity1()
{
    return Gravity1;
}
bool Settings::getGravity2()
{
    return Gravity2;
}
bool Settings::getBirdSkin1()
{
    return BirdSkin1;
}
bool Settings::getBirdSkin2()
{
    return BirdSkin2;
}
bool Settings::getBirdSkin3()
{
    return BirdSkin3;
}
bool Settings::getBackSkin1()
{
    return BackSkin1;
}
bool Settings::getBackSkin2()
{
    return BackSkin2;
}
bool Settings::getBackSkin3()
{
    return BackSkin3;
}
bool Settings::getRectSkin1()
{
    return RectSkin1;
}
bool Settings::getRectSkin2()
{
    return RectSkin2;
}
bool Settings::getRectSkin3()
{
    return RectSkin3;
}
void Settings::SetBirdSpeed()
{
    BirdSpeed13 = ui->radioButton->isChecked();
    BirdSpeed10 = ui->radioButton_2->isChecked();
    BirdSpeed7 = ui->radioButton_5->isChecked();
}
void Settings::SetRectSpeed()
{
    RectSpeed10 = ui->radioButton_4->isChecked();
    RectSpeed7 = ui->radioButton_6->isChecked();
    RectSpeed5 = ui->radioButton_3->isChecked();
}
void Settings::SetGravity()
{
    Gravity1 = ui->radioButton_7->isChecked();
    Gravity2 = ui->radioButton_8->isChecked();
}
void Settings::SetBirdSkin()
{
    BirdSkin1 = ui->radioButton_9->isChecked();
    BirdSkin2 = ui->radioButton_10->isChecked();
    BirdSkin3 = ui->radioButton_11->isChecked();
}
void Settings::SetBackSkin()
{
    BackSkin1 = ui->radioButton_12->isChecked();
    BackSkin2 = ui->radioButton_13->isChecked();
    BackSkin3 = ui->radioButton_14->isChecked();
}
void Settings::SetRectSkin()
{
    RectSkin1 = ui->radioButton_15->isChecked();
    RectSkin2 = ui->radioButton_16->isChecked();
    RectSkin3 = ui->radioButton_17->isChecked();
}
