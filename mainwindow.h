#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QPushButton>
#include <QTimer>
#include <QLCDNumber>
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QLabel>
#include <QSound>
#include <QKeyEvent>
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;
    QTimer *timer;
    QSound *bgm;
    QTimer *bombtntimer;
    void GameTitle();

    void ResultWin();
    void ResultLose();
    int c1;
    int c2;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;
    int c8;

public slots:
    void TimeDisp();

private slots:
    void StartButton();
    void EnterButton();
    void ThorHammerFire();
    void Bomb();
    void NewReinhard();
    void NewYang();
    void NewSiegfried();
    void NewDusty();
    void NewMedjed();
    void NewMittermeyer();
    void NewOskar();
    void NewJulian();
    void Checked1();
    void Checked2();
    void Checked3();
    void Checked4();
    void Checked5();
    void Checked6();
    void Checked7();
    void Checked8();
    void Radio1();
    void Radio2();
    void Radio3();
    void Radio4();
    void Radio5();
    void Radio6();
    void Radio7();
    void Radio8();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
