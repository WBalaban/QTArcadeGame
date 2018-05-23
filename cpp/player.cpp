#include "bullet.h"
#include "enemy.h"
#include "gamewindow.h"
#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>


extern Gamewindow * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/icons/witcher.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // player movement defined
    switch(event->key())
    {
    case Qt::Key_A:
        if (pos().x() > 0) setPos(x()-10,y());
        break;
    case Qt::Key_D:
        if (pos().x()+100 < 800) setPos(x()+10,y());
        break;
    case Qt::Key_Space: // create bullet and add it to the scene
        if( game->ammo->getAmmoCount() > 0) // check ammo count
        {
            Bullet * bullet = new Bullet();
            bullet->setPos(x(),y());
            scene()->addItem(bullet);
            game->ammo->setAmmoCount(1);
        }
        break;
    case Qt::Key_R:
        game->ammo->setAmmoCount(10);
    default:
        break;
    }
}

void Player::spawn()
{
   Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
