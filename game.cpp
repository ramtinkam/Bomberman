#include "game.h"


Game::Game()
{
    showFullScreen();
    scene = new QGraphicsScene(0,0,800,600,this);
    control = new Controller;
    scene->addItem(control);
    scene->addItem(control->player1);
    setScene(scene);

}
