#include "Bullet.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "enemy.h"
#include "gamewindow.h"

extern Gamewindow * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set bullet image
    setPixmap(QPixmap(":/icons/cannonBall.png"));

    // connect moveBullet funtion with timer
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    timer->start(50);
}

void Bullet::moveBullet(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> objectCollision = collidingItems();

    // check if bullet and enemy object collides, if so delete both
    for (int i = 0, n = objectCollision.size(); i < n; ++i){
        if (typeid(*(objectCollision[i])) == typeid(Enemy)){
            // increase current score
            game->score->increase();

            // remove, delete enemy and bullet object if they are colliding
            scene()->removeItem(objectCollision[i]);
            scene()->removeItem(this);

            delete objectCollision[i];
            delete this;
        }
    }
    setPos(x(),y()-10);
    // if bullet goes of the screen, delete it
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
