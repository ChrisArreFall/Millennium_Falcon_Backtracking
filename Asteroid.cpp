#include "Asteroid.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "MillenniumFalcon.h"
#include <QDebug>
Asteroid::Asteroid(){
    int randomNumberY = 50 + rand() % ((360 - 50 ) + 1);;
    int randomNumberX = 50 + rand() % ((700 - 50 ) + 1);;
    setPos(randomNumberX,randomNumberY);
    //setRect(0,0,20,20);
    setPixmap(QPixmap("/Users/Christopher/Millennium_Falcon_Backtracking/img/asteroides.png"));

}




