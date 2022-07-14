#include "wall.h"

Wall::Wall(QObject *parent): QObject{parent}
{
    setPixmap(QPixmap(":/img/sprites/SolidBlock.png"));
}
