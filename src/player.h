#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "utils.h"


class Player : public QGraphicsPixmapItem
{
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    QRect rect() const;

signals:

public slots:
};

#endif // MYRECT_H
