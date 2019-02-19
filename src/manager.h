// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_MANAGER_H_
#define SRC_MANAGER_H_

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "helper.h"
#include "utils.h"

class Manager : public QGraphicsView {
    Q_OBJECT
    const static int TIME_SPAWN = 1000;

public:
    explicit Manager(QWidget *parent = nullptr);
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

#endif  // SRC_MANAGER_H_
