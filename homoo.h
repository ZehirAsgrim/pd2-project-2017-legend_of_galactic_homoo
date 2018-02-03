#ifndef HOMOO_H
#define HOMOO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Homoo : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Homoo(QObject *parent = 0);
    int hp;

public slots:
    void hqmqq();
};

#endif // HOMOO_H
