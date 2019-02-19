// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_BULLET_H_
#define SRC_BULLET_H_

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "utils.h"

class Bullet: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    explicit Bullet(QGraphicsItem *parent = nullptr);

public slots:
    void move();
    void remove();
    void stop();

private:
    QTimer *timer;
};

#endif  // SRC_BULLET_H_
