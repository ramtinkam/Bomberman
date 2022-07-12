#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QGraphicsItem>
#include "player.h"

class Controller: public QGraphicsPixmapItem
{
public:
    Controller();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    Player* player1;
    Player* player2;

};

#endif // CONTROLLER_H
