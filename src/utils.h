#ifndef UTILS_H
#define UTILS_H

#ifdef QT_DEBUG
#include <QDebug>
#define debug(...) qDebug() << __VA_ARGS__
#else
#define debug(...)
#endif


#endif // UTILS_H
