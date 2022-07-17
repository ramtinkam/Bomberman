#include "box.h"

Box::Box(QObject *parent)
    : QObject{parent}
{
    setPixmap(QPixmap(":/img/sprites/ExplodableBlock.png"));
}
