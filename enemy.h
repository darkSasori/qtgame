#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "utils.h"


class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
    void remove();
    void stop();

private:
    QTimer *timer;
};

#endif // ENEMY_H
