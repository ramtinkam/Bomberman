#ifndef RESULT_H
#define RESULT_H

#include "label.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class result: public QGraphicsView
{
public:
    result();
    label* text;
};

#endif // RESULT_H
