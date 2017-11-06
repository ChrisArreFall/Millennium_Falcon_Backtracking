#ifndef BASE_H
#define BASE_H

#include <QGraphicsItem>

class Base : public QGraphicsItem{
public:
    Base();
    QRectF boundingRect() const override;

    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};
#endif // BASE_H
