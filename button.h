#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit button(QObject *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void pressed();

};

#endif // BUTTON_H
