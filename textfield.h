#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <QGraphicsTextItem>
#include <QTextDocument>
#include <QStyleOptionGraphicsItem>

class textField: public QGraphicsTextItem
{
private:
    int height{};
    int width{};
public:
    textField(int h,int w);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget);
};

#endif // TEXTFIELD_H
