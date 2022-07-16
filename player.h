#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "wall.h"
#include "bomb.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QList<QPixmap*> frames{};
    int frame{};
    QTimer* timer;
    QTimer* bombTimer;
    bool canPlaceBomb;
    Bomb* bomb;

public:
    Player(QObject *parent = nullptr);
    ~Player();
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void stopUp();
    void stopDown();
    void stopSide();
    void handleCollision();
    void placeBomb();
    double xPrev;
    double yPrev;


public slots:
    void bombCooldown();
    void animateDown();
    void animateUp();
    void animateSide();


};

#endif // PLAYER_H
