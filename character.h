#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Character : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Character(QObject *parent = 0);
    int hp;
    int id;
public slots:
    void sail();
};

#endif // CHARACTER_H
