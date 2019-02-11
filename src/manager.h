#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "helper.h"
#include "utils.h"


class Manager : public QGraphicsView
{
    Q_OBJECT
public:
    const static int TIME_SPAWN = 1000;

    Manager(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    QTimer *timer;

public slots:
    void spawnEnemy();

signals:
    void enemy_stop();
    void remove();

private:
    void start();
    void stop();
    void restart();

    bool started;
    Helper *helper;
};

#endif // MANAGER_H
