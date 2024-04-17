#ifndef WATCH_H
#define WATCH_H

#include <QApplication>
#include <QHBoxLayout>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include "lights.h"
#include "patternMaker.h"
#include <vector>

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
    std::vector<Light*> Hu;
    std::vector<Light*> Hl;
    std::vector<Light*> Mu;
    std::vector<Light*> Ml;
    std::vector<Light*> Su;
    std::vector<Light*> Sl;

    PatternMaker* patternMaker;
};

#endif // WATCH_H
