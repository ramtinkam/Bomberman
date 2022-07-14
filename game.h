#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "controller.h"
#include "wall.h"


class Game : public QGraphicsView
{
public:
    QGraphicsScene* scene;
    Controller* control;
    QList<Wall*> walls{};
    Game();
};

#endif // GAME_H
