#include "enemy.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>

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
    setPos(x(), y()+5);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
