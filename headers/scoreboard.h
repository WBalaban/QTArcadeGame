#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsTextItem>

class Scoreboard: public QGraphicsTextItem
{
public:
    Scoreboard(QGraphicsItem * parent=nullptr);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCOREBOARD_H
