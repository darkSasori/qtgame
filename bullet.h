#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "utils.h"


class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent = nullptr);

public slots:
    void move();
    void remove();
    void stop();

private:
    QTimer *timer;
};

#endif // BULLET_H
