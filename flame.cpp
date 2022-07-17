#include "flame.h"

//state 1=right 2=left 3=up 4=down
Flame::Flame(int s, QObject *parent)
    : QObject{parent}
{
    state=s;
    timer = new QTimer;
    lifeTimer = new QTimer;
    timer->setInterval(50);
    lifeTimer->setInterval(200);
    connect(lifeTimer,&QTimer::timeout,this,&Flame::delFlame);
    lifeTimer->start();
    setPixmap(QPixmap(":/img/sprites/Flame_f00.png"));
    switch (state) {
    case 1:
        connect(timer,&QTimer::timeout,this,&Flame::moveRight);
        timer->start();
        break;
    case 2:
        connect(timer,&QTimer::timeout,this,&Flame::moveLeft);
        timer->start();
        break;
    case 3:
        connect(timer,&QTimer::timeout,this,&Flame::moveUp);
        timer->start();
        break;
    case 4:
        connect(timer,&QTimer::timeout,this,&Flame::moveDown);
        timer->start();
        break;
}

}

Flame::~Flame()
{
    delete timer;
    delete lifeTimer;
}

void Flame::moveRight()
{
    this->setPos(x()+64,y());
    checkCollision();
}
void Flame::moveLeft()
{
    this->setPos(x()-64,y());
    checkCollision();
}
void Flame::moveUp()
{
    this->setPos(x(),y()-64);
    checkCollision();
}
void Flame::moveDown()
{
    this->setPos(x(),y()+64);
    checkCollision();
}

void Flame::checkCollision()
{
    for(QGraphicsItem* item: collidingItems()){
        if(typeid(*item)==typeid(Wall)){
            delete this;
            break;
        }
        if(typeid(*item)==typeid(Box)){
            delete item;
        }
    }
}

void Flame::delFlame()
{
    delete this;
}

