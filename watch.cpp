#include "watch.h"

Watch::Watch(QWidget* parent, int base)
    : QWidget(parent)
    , m_base(base)
{
    // setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* lines = new QVBoxLayout(this);

    roundLight = new RoundLight(this, 140);
    patternMaker = new PatternMaker(m_base);

    roundLight->setStyleSheet("QPushButton { border-radius: 70px; background-color: #808000; }");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(); // Add stretch to center the button horizontally
    buttonLayout->addWidget(roundLight);
    buttonLayout->addStretch();     // Add stretch to center the button horizontally
    lines->addLayout(buttonLayout); // Add the button layout to the main layout

    // Initialize Light arrays
    for (int i = 0; i < 4; i++) {
        Hu[i] = new Light();
        Hu[i]->setWidth(Light::Width::Large);
        Hu[i]->setColor(Light::Color::Dark_Red);

        Hl[i] = new Light();
        Hl[i]->setWidth(Light::Width::Large);
        Hl[i]->setColor(Light::Color::Dark_Red);

        Ml[i] = new Light();
        Ml[i]->setWidth(Light::Width::Large);

        Sl[i] = new Light();
        Sl[i]->setWidth(Light::Width::Large);
    }

    for (int i = 0; i < 11; i++) {
        Mu[i] = new Light();
        Mu[i]->setWidth(Light::Width::Small);
        (i % 3 == 0) ? Mu[i]->setColor(Light::Dark_Red) : Mu[i]->setColor(Light::Dark_Yellow);

        Su[i] = new Light();
        Su[i]->setWidth(Light::Width::Small);
        (i % 3 == 0) ? Su[i]->setColor(Light::Dark_Red) : Su[i]->setColor(Light::Dark_Yellow);
    }

    // Add lights to layouts
    QHBoxLayout* line_Hu = new QHBoxLayout;
    QHBoxLayout* line_Hl = new QHBoxLayout;
    QHBoxLayout* line_Mu = new QHBoxLayout;
    QHBoxLayout* line_Ml = new QHBoxLayout;
    QHBoxLayout* line_Su = new QHBoxLayout;
    QHBoxLayout* line_Sl = new QHBoxLayout;

    for (int i = 0; i < 4; i++) {
        line_Hu->addWidget(Hu[i]);
        line_Hl->addWidget(Hl[i]);
        line_Ml->addWidget(Ml[i]);
        line_Sl->addWidget(Sl[i]);
    }

    for (int i = 0; i < 11; i++) {
        line_Mu->addWidget(Mu[i]);
        line_Su->addWidget(Su[i]);
    }

    lines->addLayout(line_Hu);
    lines->addLayout(line_Hl);
    lines->addLayout(line_Mu);
    lines->addLayout(line_Ml);
    lines->addLayout(line_Su);
    lines->addLayout(line_Sl);

    // Create a QTimer to update the widget every second
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Watch::updateIndicator);
    timer->start(1000); // Update every second
}

Watch::~Watch()
{
    delete patternMaker;
    delete roundLight;
    // Delete other dynamically allocated widgets (Hu, Hl, Mu, Ml, Su, Sl)
}

void Watch::updateIndicator()
{
    patternMaker->makePatterns();

    static bool isDarkYellow = true; // Variable to toggle color state

    if (isDarkYellow) {
        roundLight->setStyleSheet(
            "QPushButton { border-radius: 70px; background-color: #808000; }");
    } else {
        roundLight->setStyleSheet(
            "QPushButton { border-radius: 70px; background-color: #FFFF00; }"); // Bright_Yellow
    }
    isDarkYellow = !isDarkYellow;

    for (int i = 0; i < 4; ++i) {
        Hu[i]->setColor((patternMaker->m_Hu[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
        Hl[i]->setColor((patternMaker->m_Hl[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
        Ml[i]->setColor((patternMaker->m_Ml[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
        Sl[i]->setColor((patternMaker->m_Sl[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
    }
    for (int i = 0; i < 11; ++i) {
        Mu[i]->setColor((patternMaker->m_Mu[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Light::Bright_Red : Light::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Light::Dark_Red : Light::Dark_Yellow));

        Su[i]->setColor((patternMaker->m_Su[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Light::Bright_Red : Light::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Light::Dark_Red : Light::Dark_Yellow));
    }
}
