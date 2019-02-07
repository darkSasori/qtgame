#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "utils.h"

enum ScorePoint{
    SHOT = 1,
    END = 2,
    SHOT_PLAYER = 4
};

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = 0);

    void increase();
    void decrease(ScorePoint point);
    int getScore();

private:
    void updateText();

    int score;
};

#endif // SCORE_H
