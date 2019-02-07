#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "utils.h"


class Manager : public QGraphicsView
{
    Q_OBJECT
public:
    Manager(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    QTimer *timer;

public slots:
    void spawnEnemy();
};

#endif // MANAGER_H
