#include "controller.h"

Controller::Controller()
{
    player1 = new Player();
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Controller::keyReleaseEvent(QKeyEvent* event){
    if(event->key() == Qt::Key::Key_S){
        player1->stopDown();
    }
    if(event->key() == Qt::Key::Key_W){
        player1->stopUp();
    }
    if(event->key() == Qt::Key::Key_D){
        player1->stopSide();
    }
    if(event->key() == Qt::Key::Key_A){
        player1->stopSide();
    }
}


void Controller::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key::Key_S){
        player1->moveDown();
    }
    if(event->key() == Qt::Key::Key_W){
        player1->moveUp();
    }
    if(event->key() == Qt::Key::Key_D){
        player1->moveRight();
    }
    if(event->key() == Qt::Key::Key_A){
        player1->moveLeft();
    }
    player1->handleCollision();
    player1->xPrev=player1->pos().x();
    player1->yPrev=player1->pos().y();
}
