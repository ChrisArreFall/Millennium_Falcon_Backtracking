#include "Base.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <qmath.h>
Base::Base()
{

}

QRectF Base::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
QPainterPath Base::shape() const
{
    QPainterPath path;
    path.addEllipse(500,0,90,90);
    return path;
}
void Base::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Ship
    QImage image2("/Users/Christopher/Millennium_Falcon_Backtracking/img/base.png");
    painter->drawImage(420, 0,image2);

    // Indicator
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkGray : Qt::red);
    painter->drawEllipse(482, 21, 8, 8);
}
