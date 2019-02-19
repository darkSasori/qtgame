// Copyright 2019 <lineufelipe@gmail.com>
#include "player.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/files/airplane_1.png"));
}

QRect Player::rect() const {
    return pixmap().rect();
}

void Player::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Right:
        if (pos().x()+rect().width()/2 < scene()->width())
            setPos(x()+10, y());
        break;
    case Qt::Key_Left:
        if (pos().x()+rect().width()/2 > 0)
            setPos(x()-10, y());
        break;
    case Qt::Key_Space:
        auto *bullet = new Bullet();
        bullet->setPos(x() + rect().width()/2, y());
        scene()->addItem(bullet);
        break;
    }
}
