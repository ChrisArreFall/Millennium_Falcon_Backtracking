#include "MillenniumFalcon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Asteroid.h"
#include <QDebug>
#include "Base.h"
#include <list>
#include <fstream>
#include <unistd.h>
#include <ctime>
/*
 * front = 1
 * back = 2
 * up = 3
 * down = 4
 */


mileniumFalcon::mileniumFalcon(): QObject(), QGraphicsRectItem(){
    up = false;
    down = false;
    front = true;
    back = false;

    srand((int)time(0));
    contadorB = 0;
    contadorLR = 0;

    posHistory.push_front(1);
    // drew the rect
    setRect(0,0,10,10);

    // connect

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30);


}

std::list<position> mileniumFalcon::genAsteroidPos()
{
    std::list<position> asteroidPositions;
    for(int i = 0;i<scene()->items(Qt::SortOrder::DescendingOrder).size();i++){
        position asteroid;
        asteroid.x = scene()->items(Qt::SortOrder::DescendingOrder)[i]->pos().x();
        asteroid.y = scene()->items(Qt::SortOrder::DescendingOrder)[i]->pos().y();
        qDebug() << asteroid.x << ", " << asteroid.y << "Num: "<< i;
        if(asteroid.x<20||asteroid.x>750){

        }
        else{
            asteroidPositions.push_front(asteroid);
        }

    }
    return asteroidPositions;
}

void mileniumFalcon::moveAux(){
    if(this->back){
        qDebug() << "back";
        setPos(pos().x()-1,pos().y());
    }
    else if(this->up){
        qDebug() << "up";
        setPos(pos().x(),pos().y()-1);
    }
    else if(this->down){
        qDebug() << "down";
        setPos(pos().x(),pos().y()+1);
    }
    else if(this->front){
        qDebug() << "front";
        setPos(pos().x()+1,pos().y());
    }
    qDebug() << front <<", "<< back <<", "<< up <<", "<< down;
}


void mileniumFalcon::move(){
    // move enemy down
    if(pos().x()>=760){
        if(pos().y()>195){
            setPos(pos().x(),pos().y()-1);
        }
        else if(pos().y()<195){
            setPos(pos().x(),pos().y()+1);
        }
        else{
            qDebug() << "LLego satisfactoriamente!";
        }
    }
    else{
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Asteroid)){
                if(posHistory.front()==1){
                    qDebug() << "Last pos: front";
                    contadorB = 10;
                    back = true;
                    front = false;
                    posHistory.push_front(2);
                    qDebug() << "added back";
                    contadorLR = 20;
                    if(pos().y()>200){
                        qDebug() << "bigger than 200";
                        posHistory.push_front(3);
                        qDebug() << "added up";
                        up = true;
                        front = false;
                        moveAux();
                    }
                    else{
                        qDebug() << "smaller than 200";
                        posHistory.push_front(4);
                        qDebug() << "added down";
                        front = false;
                        down = true;
                        moveAux();
                    }
                }
                else if(posHistory.front()==3){
                    if(LR){
                        qDebug() << "Last pos: up";
                        up = false;
                        down = false;
                        front = true;
                        contadorLR = 15;
                        posHistory.push_front(1);
                        qDebug() << "added front";
                        LR = false;
                        moveAux();
                    }
                    else{
                        qDebug() << "Last pos: up";
                        up = false;
                        down = true;
                        front = false;
                        contadorLR = 15;
                        posHistory.push_front(4);
                        qDebug() << "added down";
                        LR = true;
                        moveAux();
                    }

                }
                else if(posHistory.front()==4){
                    if(LR){
                        qDebug() << "Last pos: down";
                        up = false;
                        down = false;
                        front = true;
                        contadorLR = 10;
                        posHistory.push_front(1);
                        qDebug() << "added front";
                        LR = false;
                        moveAux();
                    }
                    else{
                        qDebug() << "Last pos: down";
                        up = true;
                        down = false;
                        front = false;
                        contadorLR = 10;
                        posHistory.push_front(3);
                        qDebug() << "added up";
                        LR = true;
                        moveAux();
                    }

                }
                return;
            }
        }
        if(contadorB>0){
            contadorB --;
            qDebug() << contadorB;
            moveAux();
        }
        else if(contadorB==0){
            if(contadorLR>0){
                back = false;
                contadorLR--;
                qDebug() << contadorLR;
                moveAux();
            }
            else{
                up = false;
                down = false;
                front = true;
                //posHistory.push_front(1);
                moveAux();
            }
        }
        qDebug() << posHistory.size()<<", " <<posHistory.front();
    }
}




void mileniumFalcon::spawn(){
    // create an enemy
    Asteroid * asteroid = new Asteroid();
    scene()->addItem(asteroid);

}
