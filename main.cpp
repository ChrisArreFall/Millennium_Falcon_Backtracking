#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <math.h>
#include "MillenniumFalcon.h"
#include "Base.h"
#include "Asteroid.h"
#include <iostream>
#include <QDebug>
static const int AsteroidCount = 20;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();

    MillenniumFalcon * falcon = new MillenniumFalcon();
    Base * base = new Base();

    scene->addItem(falcon);
    //scene->addItem(base);


    /*
    for (int i = 0; i < AsteroidCount; ++i) {
        Asteroid *asteroid = new Asteroid;
        //asteroid->setPos(::sin((i * 6.28) / AsteroidCount) * 200,::cos((i * 6.28) / AsteroidCount) * 200);
        asteroid->setPos(rand() % 501 + (-250),rand() % 700 + (-350));
        scene->addItem(asteroid);

    }
    */

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1000,700);
    //view->setBackgroundBrush(QImage("/Users/Christopher/Millennium_Falcon_Backtracking/img/space.png"));
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "​Millennium​ ​Falcon​ ​Backtracking"));

    scene->setSceneRect(0,0,1000,700);


    view->show();

    return a.exec();
}
