#ifndef MILENIUMFALCON_H
#define MILENIUMFALCON_H
#include <QGraphicsRectItem>
#include <QObject>
#include "backtracking.h"
#include <list>

class mileniumFalcon: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    mileniumFalcon();
    Backtracking backtracking;
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
