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
    /*
    Backtracking test;
    position A1;
    A1.x = 50;
    A1.y = 50;
    position A2;
    A2.x = 50;
    A2.y = 100;
    position A3;
    A3.x = 50;
    A3.y = 150;
    position A4;
    A4.x = 50;
    A4.y = 200;
    std::list<position> Alist;
    Alist.push_front(A1);
    Alist.push_front(A2);
    Alist.push_front(A3);
    Alist.push_front(A4);
    test.printSolution(test.generateMap(Alist));
*/


    QApplication a(argc, argv);



    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Base * base = new Base();
    mileniumFalcon * ship = new mileniumFalcon();
    ship->setRect(0,0,10,10);
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
    //view->setBackgroundBrush(QImage("/Users/Christopher/Millenium_Falcon/img/space.png"));
    ship->setPos(0,190);

    for(int i = 0; i<40;i++){
    ship->spawn();
    }

    return a.exec();

}
