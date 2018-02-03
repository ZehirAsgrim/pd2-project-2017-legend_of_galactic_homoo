#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Planet : public QObject , public QGraphicsPixmapItem
{
public:
    explicit Planet(QObject *parent = 0);
    int hp;
};

#endif // PLANET_H
