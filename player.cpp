#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    timer = new QTimer();
    timer->setInterval(85);
    timer->start();
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


void Player::keyReleaseEvent(QKeyEvent* event){
    if(event->key() == Qt::Key::Key_S){
        disconnect(timer,&QTimer::timeout,this,&Player::animateDown);
    }
    if(event->key() == Qt::Key::Key_W){
        disconnect(timer,&QTimer::timeout,this,&Player::animateUp);
    }
    if(event->key() == Qt::Key::Key_D){
        disconnect(timer,&QTimer::timeout,this,&Player::animateSide);
    }
    if(event->key() == Qt::Key::Key_A){
        disconnect(timer,&QTimer::timeout,this,&Player::animateSide);
    }
}


void Player::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key::Key_S){
        this->moveDown();
    }
    if(event->key() == Qt::Key::Key_W){
        this->moveUp();
    }
    if(event->key() == Qt::Key::Key_D){
        this->moveRight();
    }
    if(event->key() == Qt::Key::Key_A){
        this->moveLeft();
    }
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
