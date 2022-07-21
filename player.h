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
#include "label.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QList<QPixmap*> frames{};
    QList<Flame*> flames{};
    int frame{};
    int flamenumb;
    QTimer* timer;
    QTimer* bombTimer;
    QTimer* flameTimer;
    bool canPlaceBomb;
    Bomb* bomb;


public:
    Player(int pi,QObject *parent = nullptr);
    ~Player();
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();
    void handleCollision();
    void placeBomb();
    double xPrev;
    double yPrev;
    double health;
    QString name;
    int playerIndex;
    label* playerInfo;

public slots:
    void deleteFlames();
    void bombCooldown();
    void animateDown();
    void animateUp();
    void animateRight();
    void animateLeft();
};

#endif // PLAYER_H
