#ifndef BOX_H
#define BOX_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Box : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Box(QObject *parent = nullptr);


};

#endif // BOX_H
