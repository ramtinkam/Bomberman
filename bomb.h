#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include "flame.h"

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);
    ~Bomb();

private:
    QList<QPixmap*> frames{};
    QTimer* timer;
    int frame{};

public slots:
    void animate();

};

#endif // BOMB_H
