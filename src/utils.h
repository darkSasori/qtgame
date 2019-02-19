// Copyright 2019 <lineufelipe@gmail.com>
#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#ifdef QT_DEBUG
#include <QDebug>
#define debug(...) qDebug() << __VA_ARGS__
#else
#define debug(...)
#endif

#endif  // SRC_UTILS_H_
