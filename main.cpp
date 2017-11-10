#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "MillenniumFalcon.h"
#include "Base.h"
#include <QTimer>
#include <list>
#include <QDebug>
#include "Asteroid.h"

int main(int argc,char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Base * base = new Base();
    mileniumFalcon * ship = new mileniumFalcon();
    //ship->setRect(0,0,10,10);
    // add the item to the scene
    scene->addItem(ship);
    scene->addItem(base);


    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,400);
    scene->setSceneRect(0,0,800,400);
    view->setBackgroundBrush(QImage("/Users/Christopher/Millenium_Falcon/img/space.png"));
    //ship->setPos(0,190);

    for(int i = 0; i<40;i++){
    ship->spawn();
    }

    return a.exec();

}
