#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsItem>

class Asteroid : public QGraphicsItem{
public:
    Asteroid();
    QRectF boundingRect() const override;

    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};
#endif // ASTEROID_H
