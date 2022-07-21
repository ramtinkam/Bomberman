#ifndef HOME_H
#define HOME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include "textfield.h"
#include "label.h"
#include "button.h"
#include "game.h"

class home: public QGraphicsView
{
public:
    home();
    QGraphicsScene* scene;
private:
    textField* player1Text;
    textField* player2Text;
    textField* lives;
public slots:
    void gameStart();
};

#endif // HOME_H
