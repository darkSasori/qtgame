// Copyright 2019 <lineufelipe@gmail.com>
#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) :QGraphicsTextItem(parent), score(0) {
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
    updateText();
}

void Score::updateText() {
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increase() {
    score++;
    updateText();
}

void Score::decrease(ScorePoint point) {
    score -= point;
    updateText();
}

int Score::getScore() {
    return score;
}

void Score::zero() {
    score = 0;
    updateText();
}
