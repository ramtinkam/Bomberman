#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);

private:
    QList<QPixmap*> frames{};
    QTimer* timer;
    int frame{};

public slots:
    void animate();
};

#endif // BOMB_H
