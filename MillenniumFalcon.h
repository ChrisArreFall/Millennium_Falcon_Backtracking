#ifndef MILENIUMFALCON_H
#define MILENIUMFALCON_H
#include "backtracking.h"
#include <list>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class mileniumFalcon: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    mileniumFalcon();
    std::list<position> genAsteroidPos();

    int contadorB;
    int contadorLR;
    void moveAux();

    bool up;
    bool down;
    bool front;
    bool back;
    bool LR;

    std::list<int> posHistory;

public slots:
    void move();
    void spawn();

};

#endif // MILENIUMFALCON_H
