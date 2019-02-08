#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"
#include "manager.h"

extern Manager *game;

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    connect(game, SIGNAL(remove()), this, SLOT(remove()));
    connect(game, SIGNAL(enemy_stop()), this, SLOT(stop()));
}

void Bullet::move()
{
    auto items = collidingItems();
    for (auto enemy: items) {
        if (typeid(*enemy) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(enemy);
            delete enemy;
            remove();

           return;
        }
    }

    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0) {
        remove();
    }
}

void Bullet::remove()
{
    scene()->removeItem(this);
    delete this;
}

void Bullet::stop()
{
    timer->stop();
}
