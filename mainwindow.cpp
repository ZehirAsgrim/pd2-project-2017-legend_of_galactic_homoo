#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene();
    timer = new QTimer();
    bombtntimer = new QTimer();

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1080,640);
    GameTitle();

    ui->graphicsView->show();
    ui->btn_enter->hide();

    ui->check1->hide();
    ui->check2->hide();
    ui->check3->hide();
    ui->check4->hide();
    ui->check5->hide();
    ui->check6->hide();
    ui->check7->hide();
    ui->check8->hide();
    ui->rad1->hide();
    ui->rad2->hide();
    ui->rad3->hide();
    ui->rad4->hide();
    ui->rad5->hide();
    ui->rad6->hide();
    ui->rad7->hide();
    ui->rad8->hide();
    c1=0;
    c2=0;
    c3=0;
    c4=0;
    c5=0;
    c6=0;
    c7=0;
    c8=0;

    ui->bar_iserlohn->hide();
    ui->bar_odin->hide();
    ui->bar_heinessen->hide();

    ui->btn_reinhard->hide();
    ui->btn_yang->hide();
    ui->btn_siegfried->hide();
    ui->btn_dusty->hide();
    ui->btn_medjed->hide();
    ui->btn_mit->hide();
    ui->btn_oskar->hide();
    ui->btn_juli->hide();

    ui->timeclock->hide();
    ui->bar_fleet->hide();
    ui->bar_bomb->hide();
    ui->btn_bomb->hide();

    ui->thor->hide();

    connect(ui->btn_Feuer, SIGNAL(clicked()), this, SLOT(EnterButton()));
    connect(ui->btn_enter, SIGNAL(clicked()), this, SLOT(StartButton()));
    connect(ui->thor, SIGNAL(clicked()), this, SLOT(ThorHammerFire()));
    connect(ui->btn_reinhard, SIGNAL(clicked()), this, SLOT(NewReinhard()));
    connect(ui->btn_yang, SIGNAL(clicked()), this, SLOT(NewYang()));
    connect(ui->btn_siegfried, SIGNAL(clicked()), this, SLOT(NewSiegfried()));
    connect(ui->btn_dusty, SIGNAL(clicked()), this, SLOT(NewDusty()));
    connect(ui->btn_medjed, SIGNAL(clicked()), this, SLOT(NewMedjed()));
    connect(ui->btn_mit, SIGNAL(clicked()), this, SLOT(NewMittermeyer()));
    connect(ui->btn_oskar, SIGNAL(clicked()), this, SLOT(NewOskar()));
    connect(ui->btn_juli, SIGNAL(clicked()), this, SLOT(NewJulian()));
    connect(ui->btn_bomb, SIGNAL(clicked()), this, SLOT(Bomb()));
    connect(timer, SIGNAL(timeout()), this, SLOT(TimeDisp()));
    connect(ui->check1, SIGNAL(clicked()), this, SLOT(Checked1()));
    connect(ui->check2, SIGNAL(clicked()), this, SLOT(Checked2()));
    connect(ui->check3, SIGNAL(clicked()), this, SLOT(Checked3()));
    connect(ui->check4, SIGNAL(clicked()), this, SLOT(Checked4()));
    connect(ui->check5, SIGNAL(clicked()), this, SLOT(Checked5()));
    connect(ui->check6, SIGNAL(clicked()), this, SLOT(Checked6()));
    connect(ui->check7, SIGNAL(clicked()), this, SLOT(Checked7()));
    connect(ui->check8, SIGNAL(clicked()), this, SLOT(Checked8()));
    connect(ui->rad1, SIGNAL(clicked()), this, SLOT(Radio1()));
    connect(ui->rad2, SIGNAL(clicked()), this, SLOT(Radio2()));
    connect(ui->rad3, SIGNAL(clicked()), this, SLOT(Radio3()));
    connect(ui->rad4, SIGNAL(clicked()), this, SLOT(Radio4()));
    connect(ui->rad5, SIGNAL(clicked()), this, SLOT(Radio5()));
    connect(ui->rad6, SIGNAL(clicked()), this, SLOT(Radio6()));
    connect(ui->rad7, SIGNAL(clicked()), this, SLOT(Radio7()));
    connect(ui->rad8, SIGNAL(clicked()), this, SLOT(Radio8()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameTitle()
{
    QImage bg;
    bg.load(":img/BGT.jpg");
    scene->setBackgroundBrush(bg);
    bgm = new QSound("symphony31.wav");
    bgm->play();
    scene->count = 180;
    scene->fleetenergy = 10;
    scene->bombenergy = 0;
    scene->AUnum = 0;
}

void MainWindow::EnterButton()
{
    scene->AUnum = 1;
    QImage bg;
    bg.load(":img/BGC.jpg");
    scene->setBackgroundBrush(bg);

    ui->btn_Feuer->hide();
    ui->btn_enter->show();

    ui->check1->show();
    ui->check2->show();
    ui->check3->show();
    ui->check4->show();
    ui->check5->show();
    ui->check6->show();
    ui->check7->show();
    ui->check8->show();
    ui->rad1->show();
    ui->rad1->setChecked(true);
    ui->rad2->show();
    ui->rad3->show();
    ui->rad4->show();
    ui->rad5->show();
    ui->rad6->show();
    ui->rad7->show();
    ui->rad8->show();
}
void MainWindow::StartButton()
{
    scene->gamestart();

    ui->btn_enter->hide();
    ui->check1->hide();
    ui->check2->hide();
    ui->check3->hide();
    ui->check4->hide();
    ui->check5->hide();
    ui->check6->hide();
    ui->check7->hide();
    ui->check8->hide();
    ui->rad1->hide();
    ui->rad2->hide();
    ui->rad3->hide();
    ui->rad4->hide();
    ui->rad5->hide();
    ui->rad6->hide();
    ui->rad7->hide();
    ui->rad8->hide();

    bgm->stop();
    bgm = new QSound("bolero.wav");
    bgm->play();
    QImage bg;
    bg.load(":img/BGB.jpg");
    scene->setBackgroundBrush(bg.scaled(1080,640));
    scene->setBackgroundBrush(bg);
    ui->timeclock->display(scene->count);

    ui->bar_iserlohn->show();
    ui->bar_odin->show();
    ui->bar_heinessen->show();

    if(c1==1&&scene->AUnum!=1)ui->btn_reinhard->show();
    if(c2==1&&scene->AUnum!=2)ui->btn_yang->show();
    if(c3==1&&scene->AUnum!=3)ui->btn_siegfried->show();
    if(c4==1&&scene->AUnum!=4)ui->btn_dusty->show();
    if(c8==1&&scene->AUnum!=5)ui->btn_medjed->show();
    if(c5==1&&scene->AUnum!=6)ui->btn_mit->show();
    if(c7==1&&scene->AUnum!=7)ui->btn_oskar->show();
    if(c6==1&&scene->AUnum!=8)ui->btn_juli->show();

    ui->timeclock->show();
    ui->bar_fleet->show();
    ui->bar_bomb->show();
    ui->btn_bomb->show();

    timer->start(1000);
}

void MainWindow::NewReinhard()
{
    if(scene->AUnum != 1)
        scene->newreinhard();
}
void MainWindow::NewYang()
{
    if(scene->AUnum != 2)
        scene->newyang();
}
void MainWindow::NewSiegfried()
{
    if(scene->AUnum != 3)
        scene->newsiegfried();
}
void MainWindow::NewDusty()
{
    if(scene->AUnum != 4)
        scene->newdusty();
}
void MainWindow::NewMedjed()
{
    if(scene->AUnum != 5)
        scene->newmedjed();
}
void MainWindow::NewMittermeyer()
{
    if(scene->AUnum != 6)
        scene->newmittermeyer();
}
void MainWindow::NewOskar()
{
    if(scene->AUnum != 7)
        scene->newoskar();
}
void MainWindow::NewJulian()
{
    if(scene->AUnum != 8)
        scene->newjulian();
}

void MainWindow::Checked1()
{
    if(ui->check1->isChecked())
        c1 = 1;
    else
        c1 = 0;
}
void MainWindow::Checked2()
{
    if(ui->check2->isChecked())
        c2 = 1;
    else
        c2 = 0;
}
void MainWindow::Checked3()
{
    if(ui->check3->isChecked())
        c3 = 1;
    else
        c3 = 0;
}
void MainWindow::Checked4()
{
    if(ui->check4->isChecked())
        c4 = 1;
    else
        c4 = 0;
}
void MainWindow::Checked5()
{
    if(ui->check5->isChecked())
        c5 = 1;
    else
        c5 = 0;
}
void MainWindow::Checked6()
{
    if(ui->check6->isChecked())
        c6 = 1;
    else
        c6 = 0;
}
void MainWindow::Checked7()
{
    if(ui->check7->isChecked())
        c7 = 1;
    else
        c7 = 0;
}
void MainWindow::Checked8()
{
    if(ui->check8->isChecked())
        c8 = 1;
    else
        c8 = 0;
}
void MainWindow::Radio1()
{
    if(ui->rad1->isChecked())
        scene->AUnum = 1;
}
void MainWindow::Radio2()
{
    if(ui->rad2->isChecked())
        scene->AUnum = 2;
}
void MainWindow::Radio3()
{
    if(ui->rad3->isChecked())
        scene->AUnum = 3;
}
void MainWindow::Radio4()
{
    if(ui->rad4->isChecked())
        scene->AUnum = 4;
}
void MainWindow::Radio5()
{
    if(ui->rad5->isChecked())
        scene->AUnum = 5;
}
void MainWindow::Radio6()
{
    if(ui->rad6->isChecked())
        scene->AUnum = 6;
}
void MainWindow::Radio7()
{
    if(ui->rad7->isChecked())
        scene->AUnum = 7;
}
void MainWindow::Radio8()
{
    if(ui->rad8->isChecked())
        scene->AUnum = 8;
}

void MainWindow::TimeDisp()
{
    scene->count--;
    ui->timeclock->display(scene->count);
    ui->bar_fleet->setValue(scene->fleetenergy);
    ui->bar_bomb->setValue(scene->bombenergy);
    ui->bar_iserlohn->setValue(scene->planeti->hp);
    ui->bar_odin->setValue(scene->planeto->hp);
    ui->bar_heinessen->setValue(scene->planeth->hp);
    if(scene->planeti->hp<=0)
    {
        ui->bar_iserlohn->hide();
        ui->thor->hide();
    }
    if(scene->planeto->hp<=0)
        ui->bar_odin->hide();
    if(scene->planeth->hp<=0)
        ui->bar_heinessen->hide();
    if(scene->count == 120 || scene->count == 60)
        if(scene->planeti->hp>0)
            ui->thor->show();
    if(scene->planeth->hp<=0 && scene->planeti->hp<=0 && scene->planeto->hp<=0)
    {
        ResultLose();
    }
    else if(scene->count == 0)
        ResultWin();
}

void MainWindow::ThorHammerFire()
{
    scene->thorhammerfire();
    ui->thor->hide();
}

void MainWindow::Bomb()
{
    scene->bomber();
}

void MainWindow::ResultWin()
{
    timer->stop();
    bgm->stop();
    bgm = new QSound("walkure.wav");
    bgm->play();
    scene->endgame();
    ui->bar_iserlohn->hide();
    ui->bar_odin->hide();
    ui->bar_heinessen->hide();

    ui->btn_reinhard->hide();
    ui->btn_yang->hide();
    ui->btn_siegfried->hide();
    ui->btn_dusty->hide();
    ui->btn_medjed->hide();
    ui->btn_mit->hide();
    ui->btn_oskar->hide();
    ui->btn_juli->hide();

    ui->timeclock->hide();
    ui->bar_fleet->hide();
    ui->bar_bomb->hide();
    ui->btn_bomb->hide();

    ui->thor->hide();
    QImage bg;
    bg.load(":img/BGW.jpg");
    scene->setBackgroundBrush(bg.scaled(1080,640));
    scene->setBackgroundBrush(bg);
}
void MainWindow::ResultLose()
{
    timer->stop();
    bgm->stop();
    bgm = new QSound("fpanthem.wav");
    bgm->play();
    scene->endgame();
    ui->bar_iserlohn->hide();
    ui->bar_odin->hide();
    ui->bar_heinessen->hide();

    ui->btn_reinhard->hide();
    ui->btn_yang->hide();
    ui->btn_siegfried->hide();
    ui->btn_dusty->hide();
    ui->btn_medjed->hide();
    ui->btn_mit->hide();
    ui->btn_oskar->hide();
    ui->btn_juli->hide();

    ui->timeclock->hide();
    ui->bar_fleet->hide();
    ui->bar_bomb->hide();
    ui->btn_bomb->hide();

    ui->thor->hide();
    QImage bg;
    bg.load(":img/BGL.jpg");
    scene->setBackgroundBrush(bg.scaled(1080,640));
    scene->setBackgroundBrush(bg);
}
