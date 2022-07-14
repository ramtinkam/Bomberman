#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "wall.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QList<QPixmap*> frames{};
    int frame{};
    QTimer* timer;

public:
    Player(QObject *parent = nullptr);
    ~Player();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void stopUp();
    void stopDown();
    void stopSide();
    void handleCollision();
    double xPrev;
    double yPrev;


public slots:
    void animateDown();
    void animateUp();
    void animateSide();

};

#endif // PLAYER_H
