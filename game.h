#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"


class Game : public QGraphicsView
{
public:
    Player* player1;
    Player* player2;
    QGraphicsScene* scene;
    Game();
};

#endif // GAME_H
