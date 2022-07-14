#include "game.h"


Game::Game()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(0,0,1920,1080,this);
    control = new Controller;
    int x=448,y=64;
    for(int i=0;i<15;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        x += 64;
    }
    for(int i=15;i<30;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y += 64;
    }
    for(int i=30;i<45;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        x -= 64;
    }
    for(int i=45;i<60;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y -= 64;
    }
    x += 192;
    y += 192;
    for(int i=60;i<64;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y += 192;
    }
    y -=192;
    x +=192;
    for(int i=64;i<68;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y -= 192;
    }
    y +=192;
    x +=192;
    for(int i=68;i<72;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y += 192;
    }
    y -=192;
    x +=192;
    for(int i=72;i<76;i++){
        walls.append(new Wall);
        walls.at(i)->setPos(x,y);
        scene->addItem(walls.at(i));
        y -= 192;
    }
    scene->addItem(control);
    control->player1->setPos(512,128);
    scene->addItem(control->player1);
    scene->setBackgroundBrush(QBrush(QImage(":/img/sprites/BackgroundTile.png")));
    control->player1->xPrev=512;
    control->player1->yPrev=128;
    setScene(scene);

}
