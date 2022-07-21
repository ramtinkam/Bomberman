#ifndef FLAME_H
#define FLAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include "wall.h"
#include "box.h"



class Flame : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Flame(int s,QObject *parent = nullptr);
    ~Flame();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void checkCollision();
private:
    QTimer* timer;
    QTimer* lifeTimer;
    int state;
public slots:
    void delFlame();
};

#endif // FLAME_H
