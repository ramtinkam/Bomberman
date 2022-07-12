#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "controller.h"


class Game : public QGraphicsView
{
public:
    QGraphicsScene* scene;
    Controller* control;
    Game();
};

#endif // GAME_H
