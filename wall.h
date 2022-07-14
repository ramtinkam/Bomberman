#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>


class Wall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Wall(QObject *parent = nullptr);
};

#endif // WALL_H
