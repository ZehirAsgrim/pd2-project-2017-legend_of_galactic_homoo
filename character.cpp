#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{

}
void Character::sail()
{
    setPos(x()+15, y());
}
