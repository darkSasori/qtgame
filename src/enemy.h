// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_ENEMY_H_
#define SRC_ENEMY_H_

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "utils.h"

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Enemy(QGraphicsItem *parent = nullptr);
    QRect rect() const;

public slots:
    void move();
    void remove();
    void stop();

private:
    QTimer *timer;
};

#endif  // SRC_ENEMY_H_
