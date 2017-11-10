#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsItem>

#include <QGraphicsPixmapItem>
#include <QObject>

class Asteroid: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Asteroid();
};
#endif // ASTEROID_H
