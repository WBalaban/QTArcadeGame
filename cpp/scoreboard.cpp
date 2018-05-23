#include "scoreboard.h"
#include <QFont>

Scoreboard::Scoreboard(QGraphicsItem *parent): QGraphicsTextItem(parent), score(0)
{

    // show text on screen
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Scoreboard::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score)); // update score label
}

int Scoreboard::getScore()
{
    return score;
}
