#include "manager.h"
#include <QApplication>
#include <QTimer>
#include "enemy.h"
#include "bullet.h"

Manager::Manager(QWidget *parent) : QGraphicsView (parent)
{
    scene = new QGraphicsScene(0, 0, 800, 600);

    player = new Player();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    show();
    setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(width()/2 - player->rect().width(), height() - player->rect().height());

    auto *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(500);
}

void Manager::spawnEnemy()
{
    auto *enemy = new Enemy();
    scene->addItem(enemy);
}

void Manager::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Q:
        QApplication::quit();
        break;
    case Qt::Key_Right:
    case Qt::Key_Left:
    case Qt::Key_Space:
        player->keyPressEvent(event);
        break;
    }
}
