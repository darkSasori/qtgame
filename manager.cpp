#include "manager.h"
#include <QDesktopWidget>
#include <QApplication>
#include "enemy.h"
#include "bullet.h"

Manager::Manager(QWidget *parent) : QGraphicsView (parent), started(false)
{
    auto rect = QApplication::desktop()->screen();
    int w = rect->width(), h = rect->height();

    setWindowState(Qt::WindowFullScreen);

    scene = new QGraphicsScene(0, 0, w, h);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    show();
    setFixedSize(w, h);

    player = new Player();
    scene->addItem(player);
    player->setPos(width()/2 - player->rect().width()/2, height() - player->rect().height());

    score = new Score();
    score->setPos(0, 1);
    scene->addItem(score);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));

    helper = new Helper();
    helper->setPos(w-107, 1);
    scene->addItem(helper);
}

void Manager::start()
{
    if (started) {
        return;
    }

    emit remove();
    timer->start(TIME_SPAWN);
    score->zero();
    started = true;
}

void Manager::restart()
{
    stop();
    start();
}

void Manager::stop()
{
    if (!started) {
        return;
    }

    emit enemy_stop();
    timer->stop();
    started = false;
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
    case Qt::Key_F1:
        start();
        break;
    case Qt::Key_F2:
        stop();
        break;
    case Qt::Key_F3:
        restart();
        break;
    case Qt::Key_Right:
    case Qt::Key_Left:
    case Qt::Key_Space:
        if (started) {
            player->keyPressEvent(event);
        }
        break;
    }
}
