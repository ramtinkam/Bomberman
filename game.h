#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>
#include <time.h>
#include "player.h"
#include "controller.h"
#include "wall.h"
#include "box.h"


class Game : public QGraphicsView
{
public:
    QGraphicsScene* scene;
    Controller* control;
    QList<Wall*> walls{};
    QList<class Box*> boxes{};
    Game();
    void placeBox();
};

#endif // GAME_H
