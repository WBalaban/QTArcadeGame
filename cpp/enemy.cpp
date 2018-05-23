#include "Enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "gamewindow.h"

extern Gamewindow * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    // set enemy image
     setPixmap(QPixmap(":/icons/ghul.png"));

    // random number initalizer
    unsigned int random_number = qrand() % 700; //rand() % 700;
    setPos(random_number,0);


    // connect enemy move function with timer
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));

    timer->start(50);
}

void Enemy::moveEnemy()
{

    setPos(x(),y()+5);

    // control health bar and destroy enemy when it gets out of the screen
    if (pos().y() > 600)
    {
        game->health->decrease();

        if(game->health->getHealth() == 0) {} // TODO

        scene()->removeItem(this);
        delete this;
    }
}
