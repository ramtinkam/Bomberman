#include "player.h"

Player::Player(int pi,QObject *parent)
    : QObject{parent}
{
    playerInfo = new label;
    playerIndex = pi;
    canPlaceBomb = true;
    timer = new QTimer();
    flameTimer = new QTimer();
    bombTimer = new QTimer();
    timer->setInterval(40);
    flameTimer->setInterval(200);
    bombTimer->setInterval(3000);
    timer->start();
    connect(bombTimer,&QTimer::timeout,this,&Player::bombCooldown);
    connect(flameTimer,&QTimer::timeout,this,&Player::deleteFlames);
    if(playerIndex==1){
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
    }
    else if(playerIndex==2){
        frames.append(new QPixmap(":/img/sprites/Creep_F_f00.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_F_f01.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_F_f02.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_F_f03.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_F_f04.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_F_f05.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f00.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f01.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f02.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f03.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f04.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_B_f05.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f00.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f01.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f02.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f03.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f04.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f05.png"));
        frames.append(new QPixmap(":/img/sprites/Creep_S_f06.png"));
    }
    setPixmap(*frames.at(0));
}

Player::~Player(){
    delete timer;
    delete bombTimer;
    qDeleteAll(frames);
    delete flameTimer;
    delete playerInfo;
}


void Player::stopUp(){disconnect(timer,&QTimer::timeout,this,&Player::animateUp);}
void Player::stopDown(){disconnect(timer,&QTimer::timeout,this,&Player::animateDown);}
void Player::stopRight(){disconnect(timer,&QTimer::timeout,this,&Player::animateRight);}
void Player::stopLeft(){disconnect(timer,&QTimer::timeout,this,&Player::animateLeft);}

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
        if(playerIndex==1)
            bomb->setPos(x(),y()+64);
        else if(playerIndex==2)
            bomb->setPos(x(),y());
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
    connect(timer,&QTimer::timeout,this,&Player::animateDown);
}
void Player::moveUp(){
    connect(timer,&QTimer::timeout,this,&Player::animateUp);
}
void Player::moveRight(){
    connect(timer,&QTimer::timeout,this,&Player::animateRight);
}
void Player::moveLeft(){
    connect(timer,&QTimer::timeout,this,&Player::animateLeft);
}


void Player::animateDown(){
    this->setPos(x(),y()+10);
    if(frame>7 && playerIndex==1){
       frame=0;
    }
    if(frame>5 && playerIndex==2){
       frame=0;
    }
    setPixmap(*frames.at(frame));
    frame++;
    this->handleCollision();
    xPrev=x();
    yPrev=y();
}
void Player::animateUp(){
    this->setPos(x(),y()-10);
    if((frame<8 || frame>15) && playerIndex==1){
       frame=8;
    }
    if((frame<6 || frame>11) && playerIndex==2){
       frame=6;
    }
    setPixmap(*frames.at(frame));
    frame++;
    this->handleCollision();
    xPrev=x();
    yPrev=y();
}
void Player::animateRight(){
    this->setPos(x()+10,y());
    if((frame<16 || frame>23) && playerIndex==1){
        frame=16;
    }
    if((frame<12 || frame>18) && playerIndex==2){
       frame=12;
    }
    setPixmap(*frames.at(frame));
    frame++;
    this->handleCollision();
    xPrev=x();
    yPrev=y();
}
void Player::animateLeft(){
    this->setPos(x()-10,y());
    if((frame<16 || frame>23) && playerIndex==1){
        frame=16;
    }
    if((frame<12 || frame>18) && playerIndex==2){
       frame=12;
    }
    setPixmap(*frames.at(frame));
    frame++;
    this->handleCollision();
    xPrev=x();
    yPrev=y();
}
