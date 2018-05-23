#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsTextItem>

class Healthbar: public QGraphicsTextItem
{
public:
    Healthbar(QGraphicsItem * parent=nullptr);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif // HEALTHBAR_H
