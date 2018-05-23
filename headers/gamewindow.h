#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "scoreboard.h"
#include "healthbar.h"
#include "ammopouch.h"

class Gamewindow: public QGraphicsView
{
public:
    Gamewindow(QWidget * parent=nullptr);

    QGraphicsScene * map;
    Player * player;
    Scoreboard * score;
    Healthbar * health;
    AmmoPouch * ammo;

};

#endif // GAMEWINDOW_H
