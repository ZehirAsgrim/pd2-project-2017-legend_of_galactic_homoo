#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QSound>
#include "planet.h"
#include "character.h"
#include "reinhard.h"
#include "yang.h"
#include "siegfried.h"
#include "mittermeyer.h"
#include "oskar.h"
#include "julian.h"
#include "dusty.h"
#include "medjed.h"
#include "homoo.h"
#include "bomb.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void gamestart();
    void thorhammerfire();
    void endgame();
    void newreinhard();
    void newyang();
    void newsiegfried();
    void newdusty();
    void newmittermeyer();
    void newoskar();
    void newjulian();
    void newmedjed();
    Character *aur;
    Character *auy;
    Character *aus;
    Character *aud;
    Character *aumi;
    Character *auo;
    Character *auj;
    Character *aum;
    Character *AU;
    Bomb *bomb;
    Homoo *hom;
    Planet *planeti;
    Planet *planeto;
    Planet *planeth;
    QSound *sound;
    QSound *thoray;
    QTimer *t;
    QTimer *go;
    QTimer *woo;
    QTimer *thortimer;
    QList <Character*> aulist;
    QList <Homoo*> homoolist;
    QList <Bomb*> bomblist;
    int count;
    int fleetenergy;
    int bombenergy;
    int homoo_x,homoo_y;
    int homoonum;
    int AUnum;
public slots:
    void newhomoo();
    void thorhammerefil();
    void bomber();
    //void explode();
    void battle();
    void keyPressEvent(QKeyEvent *event);
private:
};

#endif // SCENE_H
