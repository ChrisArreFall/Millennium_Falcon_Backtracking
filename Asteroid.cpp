#include "Asteroid.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <qmath.h>
Asteroid::Asteroid()
{

}

QRectF Asteroid::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
QPainterPath Asteroid::shape() const{
    QPainterPath path;
    path.addEllipse(0,0,90,90);
    return path;
}
void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    // Ship
    QImage image2("/Users/Christopher/Millennium_Falcon_Backtracking/img/asteroid.png");
    painter->drawImage(0, 0,image2);

    // Indicator
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkGray : Qt::red);
    painter->drawEllipse(37, 37, 8, 8);

    //painter->drawEllipse(0,0,90,90);
    //painter->setBrush(Qt::black);
}
