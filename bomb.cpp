#include "bomb.h"

Bomb::Bomb(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer;
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,&Bomb::animate);
    frames.append(new QPixmap(":/img/sprites/Bomb_f01.png"));
    frames.append(new QPixmap(":/img/sprites/Bomb_f02.png"));
    frames.append(new QPixmap(":/img/sprites/Bomb_f03.png"));
    setPixmap(*frames.at(0));
    timer->start();

}

Bomb::~Bomb()
{
    qDeleteAll(frames);
    delete timer;

}

void Bomb::animate()
{
    setPixmap(*frames.at(++frame));
}

