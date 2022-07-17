#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{
    canPlaceBomb = true;
    timer = new QTimer();
    flameTimer = new QTimer();
    bombTimer = new QTimer();
    timer->setInterval(85);
    flameTimer->setInterval(200);
    bombTimer->setInterval(3000);
    timer->start();
    connect(bombTimer,&QTimer::timeout,this,&Player::bombCooldown);
    connect(flameTimer,&QTimer::timeout,this,&Player::deleteFlames);
    frames.append(new QPixmap(":/img/sprites/Bman_F_f00.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f01.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f02.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f03.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f04.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f05.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f06.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_F_f07.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f00.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f01.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f02.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f03.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f04.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f05.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f06.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_B_f07.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f00.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f01.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f02.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f03.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f04.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f05.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f06.png"));
    frames.append(new QPixmap(":/img/sprites/Bman_S_f07.png"));
    setPixmap(*frames.at(0));
}

Player::~Player(){
    delete timer;
    delete bombTimer;
    qDeleteAll(frames);
    delete flameTimer;
}


void Player::stopUp(){disconnect(timer,&QTimer::timeout,this,&Player::animateUp);}
void Player::stopDown(){disconnect(timer,&QTimer::timeout,this,&Player::animateDown);}
void Player::stopSide(){disconnect(timer,&QTimer::timeout,this,&Player::animateSide);}

void Player::handleCollision()
{
    for(QGraphicsItem* item: collidingItems()){
        if(typeid(*item)==typeid(Wall) || typeid(*item)==typeid(Box)){
            this->setPos(xPrev,yPrev);
        }
    }
}

void Player::placeBomb()
{
    if(canPlaceBomb){
        bomb=new Bomb;
        bomb->setPos(x(),y()+64);
        scene()->addItem(bomb);
        canPlaceBomb = false;
        bombTimer->start();
    }
}

void Player::deleteFlames()
{
    flames.clear();
    flameTimer->stop();
}

void Player::bombCooldown()
{
    int x=bomb->x();
    int y=bomb->y();
    canPlaceBomb = true;
    bombTimer->stop();
    delete bomb;
    for(int i=1;i<5;i++){
        flames.append(new Flame(i));
        flames.at(i-1)->setPos(x,y);
        scene()->addItem(flames.at(i-1));
    }
    flameTimer->start();
}


void Player::moveDown(){
    this->setPos(x(),y()+10);
    connect(timer,&QTimer::timeout,this,&Player::animateDown);
}
void Player::moveUp(){
    this->setPos(x(),y()-10);
    connect(timer,&QTimer::timeout,this,&Player::animateUp);
}
void Player::moveRight(){
    this->setPos(x()+10,y());
    connect(timer,&QTimer::timeout,this,&Player::animateSide);
}
void Player::moveLeft(){
    this->setPos(x()-10,y());
    connect(timer,&QTimer::timeout,this,&Player::animateSide);
}


void Player::animateDown(){
    if(frame>7){
       frame=0;
    }
    setPixmap(*frames.at(frame));
    frame++;
}
void Player::animateUp(){
    if(frame<8 || frame>15){
       frame=8;
    }
    setPixmap(*frames.at(frame));
    frame++;
}
void Player::animateSide(){
    if(frame<16 || frame>23){
        frame=16;
    }
    setPixmap(*frames.at(frame));
    frame++;
}
