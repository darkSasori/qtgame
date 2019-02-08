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
    Score(QGraphicsItem *parent = nullptr);

    void increase();
    void decrease(ScorePoint point);
    int getScore();
    void zero();

private:
    void updateText();

    int score;
};

#endif // SCORE_H
