#ifndef WATCH_H
#define WATCH_H

#include <QApplication>
#include <QHBoxLayout>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include "lights.h"
#include "patternMaker.h"

class Watch : public QWidget
{
    Q_OBJECT

public:
    Watch(QWidget* parent = nullptr, int base = 5);
    ~Watch();

private slots:
    void updateIndicator();

private:
    int m_base;

    RoundLight* roundLight;
    Light* Hu[4];
    Light* Hl[4];
    Light* Mu[11];
    Light* Ml[4];
    Light* Su[11];
    Light* Sl[4];

    PatternMaker* patternMaker;
};

#endif // WATCH_H
