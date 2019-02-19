// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "utils.h"

class Player : public QGraphicsPixmapItem {
public:
    explicit Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    QRect rect() const;
};

#endif  // SRC_PLAYER_H_
