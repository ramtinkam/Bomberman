#include "game.h"


Game::Game()
{
    showFullScreen();
    scene = new QGraphicsScene(0,0,800,600,this);
    player1 = new Player();
    scene->addItem(player1);
    setScene(scene);

}
