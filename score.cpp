#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) :score(0), QGraphicsTextItem (parent)
{
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
    updateText();
}

void Score::updateText()
{
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increase()
{
    score++;
    updateText();
}

int Score::getScore()
{
    return score;
}
