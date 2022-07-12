#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QList>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QList<QPixmap*> frames{};
    int frame{};
    QTimer* timer;

public:
    Player(QObject *parent = nullptr);
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void stopUp();
    void stopDown();
    void stopSide();


public slots:
    void animateDown();
    void animateUp();
    void animateSide();

};

#endif // PLAYER_H
