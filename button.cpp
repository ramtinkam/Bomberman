#include "button.h"

button::button(QObject *parent)
    : QObject{parent}
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QPixmap qpixmap=QPixmap(":/img/sprites/button.png");
    qpixmap = qpixmap.scaled(200,60);
    setPixmap(qpixmap);


}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit pressed();
}
