#include "Base.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>
Base::Base(){
    // drew the rect
    //setRect(0,0,30,30);
    setPixmap(QPixmap("/Users/Christopher/Millennium_Falcon_Backtracking/img/base.png"));
    setPos(720,185);
}
