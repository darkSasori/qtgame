// Copyright 2019 <lineufelipe@gmail.com>
#include "helper.h"
#include <QFont>

Helper::Helper(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

    auto msg = QString("")
            + "F1 - Start\n"
            + "F2 - Stop\n"
            + "F3 - Restart\n"
            + "\n"
            + "ESC - Quit";
    setPlainText(msg);
}
