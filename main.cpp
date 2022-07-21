#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include "game.h"
#include "home.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //auto game = new Game;
    auto Home = new home;

    Home->show();

    //game->show();

    return a.exec();
}
