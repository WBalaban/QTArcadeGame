#ifndef AMMOPOUCH_H
#define AMMOPOUCH_H
#include <QGraphicsTextItem>


class AmmoPouch : public QGraphicsTextItem
{
public:
    AmmoPouch(QGraphicsItem * parent=nullptr);
    void setAmmoCount(int);
    int getAmmoCount();

private:
    int ammoCount;
};

#endif // AMMOPOUCH_H
