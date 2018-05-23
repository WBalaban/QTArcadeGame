#include "healthbar.h"
#include <QFont>

Healthbar::Healthbar(QGraphicsItem *parent): QGraphicsTextItem(parent), health{3}

{

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Healthbar::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Healthbar::getHealth()
{
    return health;
}
