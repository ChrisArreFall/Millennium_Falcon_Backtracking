#ifndef MILLENNIUMFALCON_H
#define MILLENNIUMFALCON_H
#include <QObject>
#include <QGraphicsItem>
#include <list>

class MillenniumFalcon : public QObject,public QGraphicsItem{
    Q_OBJECT
public:
    MillenniumFalcon();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
public slots:
    void move();
};

#endif // MILLENNIUMFALCON_H
