#include "manager.h"
#include <QApplication>
#include "enemy.h"
#include "bullet.h"

Manager::Manager(QWidget *parent) : QGraphicsView (parent)
{
    scene = new QGraphicsScene(0, 0, 800, 600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    show();
    setFixedSize(800, 600);

    player = new Player();
    scene->addItem(player);
    player->setPos(width()/2 - player->rect().width(), height() - player->rect().height());

    score = new Score();
    scene->addItem(score);

    timer = new QTimer();
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
    case Qt::Key_Escape:
        QApplication::quit();
        break;
    case Qt::Key_Right:
    case Qt::Key_Left:
    case Qt::Key_Space:
        player->keyPressEvent(event);
        break;
    }
}
