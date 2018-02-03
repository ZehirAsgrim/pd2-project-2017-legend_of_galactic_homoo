#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bomb : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = 0);
    int b;
};

#endif // BOMB_H
