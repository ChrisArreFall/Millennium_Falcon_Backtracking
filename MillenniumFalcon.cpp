#include "MillenniumFalcon.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <qmath.h>
#include <unistd.h>
#include <QTimer>
#include <QDebug>


MillenniumFalcon::MillenniumFalcon()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


QRectF MillenniumFalcon::boundingRect() const{
}
QPainterPath MillenniumFalcon::shape() const{
}
void MillenniumFalcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Ship
    //QImage image("/Users/Christopher/Millennium_Falcon_Backtracking/img/ship.png");
    //painter->drawImage(0, 329,image);

    painter->drawRect(0,329,60,42);

    // Indicator
    //painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkGray : Qt::red);
    //painter->drawEllipse(-482, 17, 8, 8);
}


void MillenniumFalcon::move()
{
    if(!(pos().x()==920)){
        setPos(x()+10,y());
        //movements.add(10);
        qDebug() << pos().x();
    }
}

