#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>

#include "manager.h"

Manager *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Manager();
    game->show();

    return a.exec();
}
