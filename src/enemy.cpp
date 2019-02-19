// Copyright 2019 <lineufelipe@gmail.com>
#include "enemy.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QApplication>
#include "manager.h"
#include "player.h"
#include "score.h"

extern Manager *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/files/airplane_2.png"));

    auto pos_x = static_cast<qreal>(rand() % 700);
    setPos(pos_x, 0);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    connect(game, SIGNAL(remove()), this, SLOT(remove()));
    connect(game, SIGNAL(enemy_stop()), this, SLOT(stop()));
}

QRect Enemy::rect() const {
    return pixmap().rect();
}

void Enemy::move() {
    auto items = collidingItems();
    for (auto item: items) {
        if (typeid(*item) == typeid(Player)) {
            game->score->decrease(ScorePoint::SHOT_PLAYER);
            remove();

            return;
        }
    }

    setPos(x(), y()+5);
    if (pos().y() + rect().height() > scene()->height()) {
        game->score->decrease(ScorePoint::END);
        remove();
    }
}

void Enemy::remove() {
    scene()->removeItem(this);
    delete this;
}

void Enemy::stop() {
    timer->stop();
}
