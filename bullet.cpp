#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"
#include "manager.h"

extern Manager *game;

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    auto *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    auto items = collidingItems();
    for (auto enemy: items) {
        if (typeid(*enemy) == typeid(Enemy)) {
            game->score->increase();
           scene()->removeItem(enemy);
           scene()->removeItem(this);

           delete enemy;
           delete this;

           return;
        }
    }
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
