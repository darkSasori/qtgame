#include "enemy.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include "manager.h"
#include "player.h"
#include "score.h"

extern Manager *game;

Enemy::Enemy() : QObject (), QGraphicsRectItem ()
{
    auto pos_x = static_cast<qreal>(rand() % 700);
    setPos(pos_x, 0);
    setRect(0, 0, 100, 100);

    auto *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    auto items = collidingItems();
    for(auto item: items) {
        if (typeid (*item) == typeid (Player)) {
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

void Enemy::remove()
{
    scene()->removeItem(this);
    delete this;
}
