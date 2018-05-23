#include "gamewindow.h"
#include "enemy.h"
#include <QMediaPlayer>
#include <QImage>
#include <QMediaPlaylist>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>


Gamewindow::Gamewindow(QWidget *parent)
{
    // create the scene and set it to fixed size 800x600
    map = new QGraphicsScene();
    map->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/icons/background.jpg")));

    // disable scrolling bars and set window size to scene size
    setScene(map);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setFixedSize(800,600);

     // play background music in loop, playlist allows to add more music
     QMediaPlaylist *playlist = new QMediaPlaylist();
     playlist->addMedia(QUrl("qrc:/sound/bgmusic3.mp3"));
     playlist->setPlaybackMode(QMediaPlaylist::Loop);
     QMediaPlayer * backgroundMusic = new QMediaPlayer();
     backgroundMusic->setPlaylist(playlist);
     backgroundMusic->play();

    // create the score/health/ammobar and player
    score = new Scoreboard();
    map->addItem(score);

    health = new Healthbar();
    health->setPos(health->x(),health->y()+25);
    map->addItem(health);

    ammo = new AmmoPouch();
    ammo->setPos(ammo->x(),ammo->y()+50);
    map->addItem(ammo);

    player = new Player();
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    // set focus on player so he can use keyPressEvent
    player->setFocus();
    map->addItem(player);

    // periodicaly add enemies to the scene
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    show();
}
