#include "Base.h"
#include <QGraphicsScene>
#include <QDebug>
Base::Base(): QObject(), QGraphicsRectItem(){
    // drew the rect
    setRect(0,0,30,30);
    setPos(770,185);
}
