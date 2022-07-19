#include "game.h"


Game::Game()
{
    srand(time(0));
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
    control->player2->setPos(1344,960);
    scene->addItem(control->player1);
    scene->addItem(control->player2);
    scene->setBackgroundBrush(QBrush(QImage(":/img/sprites/BackgroundTile.png")));
    control->player1->xPrev=512;
    control->player1->yPrev=128;
    control->player2->xPrev=1344;
    control->player2->yPrev=960;
    this->placeBox();
    setScene(scene);

}

void Game::placeBox()
{
    int x=512,y=128,r=0;
    bool flg=true;
    for(int i=0;i<14;i++){
        for (int j=0;j<14;j++){
            for(int l=60;l<76;l++){
                if(x==walls.at(l)->x() && y==walls.at(l)->y())
                    flg=false;
            }
            if(rand()%2==0 && (x>768 || y>384) && (x<1088 || y<704)  && flg){
                boxes.append(new class Box);
                boxes.at(r)->setPos(x,y);
                scene->addItem(boxes.at(r));
                r++;
            }
            flg=true;
            x += 64;
        }
        x = 512;
        y += 64;
    }
}
