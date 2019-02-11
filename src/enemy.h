#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "utils.h"


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = nullptr);
    QRect rect() const;

public slots:
    void move();
    void remove();
    void stop();

private:
    QTimer *timer;
};

#endif // ENEMY_H
