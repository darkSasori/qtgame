// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_SCORE_H_
#define SRC_SCORE_H_

#include <QGraphicsTextItem>
#include "utils.h"

enum ScorePoint{
    SHOT = 1,
    END = 2,
    SHOT_PLAYER = 4
};

class Score : public QGraphicsTextItem {
public:
    explicit Score(QGraphicsItem *parent = nullptr);

    void increase();
    void decrease(ScorePoint point);
    int getScore();
    void zero();

private:
    void updateText();

    int score;
};

#endif  // SRC_SCORE_H_
