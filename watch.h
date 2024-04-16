#ifndef WATCH_H
#define WATCH_H

#include <QApplication>
#include <QHBoxLayout>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include "lights.h"
#include "patternMaker.h"

constexpr int BASE = 5;

class Watch : public QWidget
{
    Q_OBJECT

public:
    Watch(QWidget* parent = nullptr, int base = 5);
    ~Watch();

private slots:
    void updateIndicator();

private:
    const int m_base;

    RoundLight* roundLight;
    Light* Hu[BASE - 1];
    Light* Hl[BASE - 1];
    Light* Mu[(60 / BASE) - 1];
    Light* Ml[BASE - 1];
    Light* Su[(60 / BASE) - 1];
    Light* Sl[BASE - 1];

    PatternMaker* patternMaker;
};

#endif // WATCH_H
