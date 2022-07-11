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
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();


public slots:
    void animateDown();
    void animateUp();
    void animateSide();

};

#endif // PLAYER_H
