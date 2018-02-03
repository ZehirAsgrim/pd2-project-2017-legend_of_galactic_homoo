#include "scene.h"

Scene::Scene()
{
}

void Scene::gamestart()
{
    QPixmap p0,p1,p2;
    p1.load(":img/odin.png");
    p2.load(":img/heinessen.png");
    p0.load(":img/iserlohn.png");

    planeti = new Planet();
    planeto = new Planet();
    planeth = new Planet();

    planeto->hp = 100;
    planeto->setPixmap(p1);
    planeto->setPos(30,20);//130*150
    addItem(planeto);

    planeti->hp = 200;
    planeti->setPixmap(p0);
    planeti->setPos(30,220);//152*175
    addItem(planeti);

    planeth->hp = 100;
    planeth->setPixmap(p2);
    planeth->setPos(30,450);
    addItem(planeth);//135*150

    if(AUnum == 1)
    {
        QPixmap p;
        p.load(":img/reinhard.gif");
        AU = new Reinhard();
        AU->setPixmap(p);
        AU->setPos(130,270);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 2)
    {
        QPixmap p;
        p.load(":img/yang.gif");
        AU = new Yang();
        AU->setPixmap(p);
        AU->setPos(130,270);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 3)
    {
        QPixmap p;
        p.load(":img/siegfried.gif");
        AU = new Siegfried();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 4)
    {
        QPixmap p;
        p.load(":img/dusty.png");
        AU = new Dusty();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 5)
    {
        QPixmap p;
        p.load(":img/mittermeyer.png");
        AU = new Mittermeyer();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 6)
    {
        QPixmap p;
        p.load(":img/julian.png");
        AU = new Julian();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 7)
    {
        QPixmap p;
        p.load(":img/oskar.png");
        AU = new Oskar();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }
    else if(AUnum == 8)
    {
        QPixmap p;
        p.load(":img/medjed.gif");
        AU = new Medjed();
        AU->setPixmap(p);
        AU->setPos(130,300);
        AU->hp = 999;
        addItem(AU);
    }

    thortimer = new QTimer();
    t = new QTimer();
    go = new QTimer();
    woo = new QTimer();
    sound = new QSound(":sound/explode.wav");
    thoray = new QSound(":sound/thoray.wav");
    t->start(1000);
    go->start(750);
    woo->start(2500);

    connect(t, SIGNAL(timeout()),this, SLOT(battle()));
    connect(woo, SIGNAL(timeout()),this, SLOT(newhomoo()));
}

void Scene::battle()
{
    if(fleetenergy<10)
        fleetenergy++;
    if(bombenergy<15)
        bombenergy++;
    int i,j,k;

    QPixmap p;
    p.load(":img/explode.png");

    for(i = 0;i < bomblist.size();i++)
    {
        for(j = 0;j < homoolist.size();j++)
        {
            if(homoolist.at(j)->x()+32 >= bomblist.at(i)->x() &&
                homoolist.at(j)->x()+32 <= bomblist.at(i)->x()+200 &&
                homoolist.at(j)->y()+32 >= bomblist.at(i)->y() &&
                homoolist.at(j)->y()+32 <= bomblist.at(i)->y()+120 &&
                    bomblist.at(i)->b < 2)
                {
                    homoolist.at(j)->hp = 0;
                    bomblist.at(i)->b = 1;
                }

        }
        for(k = 0;k < aulist.size();k++)
        {
            if(aulist.at(k)->x()+45 >= bomblist.at(i)->x() &&
                  aulist.at(k)->x()+45 <= bomblist.at(i)->x()+200 &&
                  aulist.at(k)->y()+45 >= bomblist.at(i)->y() &&
                  aulist.at(k)->y()+45 <= bomblist.at(i)->y()+120 &&
                  bomblist.at(i)->b < 2)
                {
                    aulist.at(k)->hp = 0;
                    bomblist.at(i)->b = 1;
                }
        }
    }

    for(i = 0;i < bomblist.size();i++)
    {
        if(bomblist.at(i)->b == 1)
        {
            sound->play();
            bomblist.at(i)->setPixmap(p);
            bomblist.at(i)->b = 2;
        }
    }
    for(i = 0;i < homoolist.size();i++)
    {
        if(homoolist.at(i)->x() >= AU->x() &&
                homoolist.at(i)->x() <= AU->x()+80 &&
                homoolist.at(i)->y()+32 >= AU->y() &&
                homoolist.at(i)->y()+32 <= AU->y()+80)
                {
                    homoolist.at(i)->hp--;
                }
    }

    for(i = 0;i < aulist.size();i++)
    {
        for(j = 0;j < homoolist.size();j++)
        {
            if(homoolist.at(j)->x() >= aulist.at(i)->x() &&
                homoolist.at(j)->x() <= aulist.at(i)->x()+80 &&
                homoolist.at(j)->y()+32 >= aulist.at(i)->y() &&
                homoolist.at(j)->y()+32 <= aulist.at(i)->y()+80)
                {
                    homoolist.at(j)->hp--;
                    aulist.at(i)->hp--;
                }
        }
    }
    for(i = 0;i < homoolist.size();i++)
    {
        if(homoolist.at(i)->x() <= planeto->x()+130 &&
           homoolist.at(i)->x() > planeto->x() &&
           homoolist.at(i)->y()+32 >= planeto->y() &&
           homoolist.at(i)->y()+32 <= planeto->y()+150 &&
           planeto->hp > 0)
        {
            planeto->hp = planeto->hp - 5;
            homoolist.at(i)->hp--;
            if(planeto->hp == 0)
                removeItem(planeto);
        }
        if(homoolist.at(i)->x() <= planeti->x()+150 &&
           homoolist.at(i)->x() > planeti->x() &&
           homoolist.at(i)->y()+32 >= planeti->y() &&
           homoolist.at(i)->y()+32 <= planeti->y()+175 &&
           planeti->hp > 0)
        {
            planeti->hp = planeti->hp - 5;
            homoolist.at(i)->hp--;
            if(planeti->hp == 0)
                removeItem(planeti);
        }
        if(homoolist.at(i)->x() <= planeth->x()+135 &&
           homoolist.at(i)->x()+32 >planeth->x() &&
           homoolist.at(i)->y()+32 >= planeth->y() &&
           homoolist.at(i)->y()+32 <= planeth->y()+150 &&
           planeth->hp > 0)
        {
             planeth->hp = planeth->hp - 5;
             homoolist.at(i)->hp--;
             if(planeth->hp == 0)
                 removeItem(planeth);
        }
    }
    for(i = 0;i < homoolist.size();)
    {
        if(homoolist.at(i)->hp <= 0||homoolist.at(i)->x() < 0)
        {
            removeItem(homoolist.at(i));
            homoolist.removeAt(i);
        }
        else i++;
    }
    for(i = 0;i < aulist.size();)
    {
        if(aulist.at(i)->hp <= 0 || aulist.at(i)->x() > 1080)
        {
            removeItem(aulist.at(i));
            aulist.removeAt(i);
        }
        else i++;
    }
}

void Scene::newhomoo()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    homoo_x = 1000;
    if(planeto->hp <= 0 && planeth->hp > 0) //150..560
    {
        homoo_y = qrand() % (560-150)+150;
        homoonum = 10;
    }
    else if(planeto->hp > 0 && planeth->hp <= 0)    //0..400
    {
        homoo_y = qrand() % 400;
        homoonum = 10;
    }
    else if(planeto->hp <= 0 && planeth->hp <= 0)   //150..400
    {
        homoo_y = qrand() % (400-150)+150;
        homoonum = 8;
    }
    else
    {
        homoo_y = qrand() % 560;
        homoonum = 12;
    }
    QPixmap h;
    QPixmap h2;
    h.load(":img/homoo.gif");
    h2.load(":img/homou.png");
    if(count > 0 && homoolist.size()<homoonum)
    {
        hom = new Homoo();
        if(homoolist.size() == 4 || homoolist.size() == 9)
        {
            hom->setPixmap(h2);
            hom->hp = 7;
        }
        else
        {
            hom->setPixmap(h);
            hom->hp = 6;
        }
        hom->setPos(homoo_x,homoo_y);
        addItem(hom);
        hom->connect(go, SIGNAL(timeout()), hom, SLOT(hqmqq()));
        homoolist.append(hom);
    }
}

void Scene::newreinhard()
{
    QPixmap p;
    p.load(":img/reinhard.gif");
    if(fleetenergy>=5)
    {
        aur = new Reinhard();
        aur->setPixmap(p);
        aur->setPos(130,300);
        aur->hp = 7;
        addItem(aur);
        aur->connect(go, SIGNAL(timeout()), aur, SLOT(sail()));
        aulist.append(aur);
        fleetenergy = fleetenergy - 5;

    }

}
void Scene::newyang()
{  
    if(fleetenergy>=5)
    {
        QPixmap p;
        p.load(":img/yang.gif");
        auy = new Yang();
        auy->setPixmap(p);
        auy->setPos(130,homoo_y);
        auy->hp = 7;
        addItem(auy);
        auy->connect(go, SIGNAL(timeout()), auy, SLOT(sail()));
        aulist.append(auy);
        fleetenergy = fleetenergy - 5;
    }
}
void Scene::newsiegfried()
{
    if(fleetenergy>=4)
    {
        QPixmap p;
        p.load(":img/siegfried.gif");
        aus = new Siegfried();
        aus->setPixmap(p);
        aus->setPos(120,50);
        aus->hp = 4;
        addItem(aus);
        aus->connect(go, SIGNAL(timeout()), aus, SLOT(sail()));
        aulist.append(aus);
        fleetenergy = fleetenergy - 4;
    }
}
void Scene::newdusty()
{
    if(fleetenergy>=4)
    {
        QPixmap p;
        p.load(":img/dusty.png");
        aud = new Dusty();
        aud->setPixmap(p);
        aud->setPos(130,homoo_y);
        aud->hp = 5;
        addItem(aud);
        aud->connect(go, SIGNAL(timeout()), aud, SLOT(sail()));
        aulist.append(aud);
        fleetenergy = fleetenergy - 4;
    }
}
void Scene::newmittermeyer()
{
    if(fleetenergy>=3)
    {
        QPixmap p;
        p.load(":img/mittermeyer.png");
        aumi = new Mittermeyer();
        aumi->setPixmap(p);
        aumi->setPos(130,homoo_y);
        aumi->hp = 5;
        addItem(aumi);
        aumi->connect(go, SIGNAL(timeout()), aumi, SLOT(sail()));
        aulist.append(aumi);
        fleetenergy = fleetenergy - 3;
    }
}
void Scene::newoskar()
{
    if(fleetenergy>=3)
    {
        QPixmap p;
        p.load(":img/oskar.png");
        auo = new Oskar();
        auo->setPixmap(p);
        auo->setPos(130,homoo_y);
        auo->hp = 4;
        addItem(auo);
        auo->connect(go, SIGNAL(timeout()), auo, SLOT(sail()));
        aulist.append(auo);
        fleetenergy = fleetenergy - 3;
    }
}
void Scene::newjulian()
{
    if(fleetenergy>=3)
    {
        QPixmap p;
        p.load(":img/julian.png");
        auj = new Oskar();
        auj->setPixmap(p);
        auj->setPos(130,460);
        auj->hp = 3;
        addItem(auj);
        auj->connect(go, SIGNAL(timeout()), auj, SLOT(sail()));
        aulist.append(auj);
        fleetenergy = fleetenergy - 3;
    }
}
void Scene::newmedjed()
{
    if(fleetenergy>=4)
    {
        QPixmap p;
        p.load(":img/medjed.gif");
        aum = new Medjed();
        aum->setPixmap(p);
        aum->setPos(160,homoo_y);
        aum->hp = 6;
        addItem(aum);
        aum->connect(go, SIGNAL(timeout()), aum, SLOT(sail()));
        aulist.append(aum);
        fleetenergy = fleetenergy - 4;
    }
}

void Scene::thorhammerfire()
{
    thoray->play();
    QPixmap p;
    p.load(":img/thorhammer.png");
    planeti->setPixmap(p);
    connect(thortimer,SIGNAL(timeout()),this,SLOT(thorhammerefil()));
    thortimer->start(1000);
    int i;
    for(i = 0;i < homoolist.size();)
    {
        if(homoolist.at(i)->y()+64 > 220+15 &&
           homoolist.at(i)->y() < 220+72)//15..72 235..292
        {
            removeItem(homoolist.at(i));
            homoolist.removeAt(i);
        }
        else i++;
    }
    for(i = 0;i < aulist.size();)
    {
        if(aulist.at(i)->y()+100 > 220+15 &&
           aulist.at(i)->y() < 220+72)//15..72 235..292
        {
            removeItem(aulist.at(i));
            aulist.removeAt(i);
        }
        else i++;
    }
}

void Scene::thorhammerefil()
{
    QPixmap p;
    p.load(":img/iserlohn.png");
    planeti->setPixmap(p);
    thortimer->stop();
}

void Scene::endgame()
{
    woo->stop();
    removeItem(planeti);
    removeItem(planeto);
    removeItem(planeth);
    int i;
    for(i = 0;i < homoolist.size();i++)
    {
        removeItem(homoolist.at(i));
    }
    for(i = 0;i < aulist.size();i++)
    {
        removeItem(aulist.at(i));
    }
    for(i = 0;i < bomblist.size();i++)
    {
        removeItem(bomblist.at(i));
    }
}

void Scene::bomber()
{   if(bombenergy == 15)
    {
        int bomb_x = (qrand() % 700)+300;
        QPixmap p;
        p.load(":img/bomb.png");
        bomb = new Bomb();
        bomb->b = 0;
        bomb->setPixmap(p);
        bomb->setPos(bomb_x,homoo_y);
        addItem(bomb);
        bomblist.append(bomb);
        bombenergy = 0;
    }
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right)
    {
        if(AU->x()<980-15)
            AU->setPos(AU->x()+5, AU->y());
    }
    if(event->key()==Qt::Key_Left)
    {
        if(AU->x()>100+15)
            AU->setPos(AU->x()-5, AU->y());
    }
    if(event->key()==Qt::Key_Up)
    {
        if(AU->y()>10)
            AU->setPos(AU->x(), AU->y()-5);
    }
    if(event->key()==Qt::Key_Down)
    {
        if(AU->y()<540-10)
            AU->setPos(AU->x(), AU->y()+5);
    }
}
