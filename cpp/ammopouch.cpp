#include "ammopouch.h"
#include <QFont>


AmmoPouch::AmmoPouch(QGraphicsItem *parent): QGraphicsTextItem(parent), ammoCount{10}
{
    setPlainText(QString("Ammo: ") + QString::number(ammoCount));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void AmmoPouch::setAmmoCount(int ammo)
{
    // check if ammo has to be realoaded
    if(10==ammo) ammoCount=10;
    else --ammoCount;
    setPlainText(QString("Ammo: ") + QString::number(ammoCount));

    if(0==ammoCount) setPlainText(QString("Reload! 'R' "));
}

int AmmoPouch::getAmmoCount()
{
    return ammoCount;
}
