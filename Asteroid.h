#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QObject>

class Asteroid: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Asteroid();
};
#endif // ASTEROID_H
