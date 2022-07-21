#include "result.h"

result::result()
{
    text = new label;
    text->setPos(960,540);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    auto scene = new QGraphicsScene(0,0,1920,1080,this);
    scene->addItem(text);
    scene->setBackgroundBrush(QColor("gray"));
    setScene(scene);
}
