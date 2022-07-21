#include "textfield.h"

textField::textField(int h,int w):width(w),height(h),QGraphicsTextItem()
{
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setTextWidth(width);
    document()->setDocumentMargin(10);
    QFont f;
    f.setPixelSize(30);
    f.setBold(true);
    setFont(f);
}

void textField::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget)
{
    QStyleOptionGraphicsItem newOption(*option);
    newOption.state = QStyle::State_None;


    QGraphicsTextItem::paint(painter,&newOption,widget);
}
