#include "controller.h"

Controller::Controller()
{
    player1 = new Player(1);
    player2 = new Player(2);
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
        player1->stopRight();
    }
    if(event->key() == Qt::Key::Key_A){
        player1->stopLeft();
    }
    if(event->key() == Qt::Key::Key_Down){
        player2->stopDown();
    }
    if(event->key() == Qt::Key::Key_Up){
        player2->stopUp();
    }
    if(event->key() == Qt::Key::Key_Right){
        player2->stopRight();
    }
    if(event->key() == Qt::Key::Key_Left){
        player2->stopLeft();
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
    if(event->key() == Qt::Key::Key_Space){
        player1->placeBomb();
    }
    if(event->key() == Qt::Key::Key_Down){
        player2->moveDown();
    }
    if(event->key() == Qt::Key::Key_Up){
        player2->moveUp();
    }
    if(event->key() == Qt::Key::Key_Right){
        player2->moveRight();
    }
    if(event->key() == Qt::Key::Key_Left){
        player2->moveLeft();
    }
    if(event->key() == Qt::Key::Key_Shift){
        player2->placeBomb();
    }
}
