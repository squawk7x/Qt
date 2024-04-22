#include "watch.h"
#include <QKeyEvent>

Watch::Watch(QWidget* parent, int base)
    : QWidget(parent)
    , m_base(base)
{
    setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* lines = new QVBoxLayout(this);

    roundLight = new RoundLight(this, 140);
    patternMaker = new PatternMaker(m_base);

    roundLight->setStyleSheet("QPushButton { border-radius: 70px; background-color: #808000; }");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(); // Add stretch to center the button horizontally
    buttonLayout->addWidget(roundLight);
    buttonLayout->addStretch();     // Add stretch to center the button horizontally
    lines->addLayout(buttonLayout); // Add the button layout to the main layout

    // Initialize Light vectors
    Hu.resize((24 - 1) / m_base);
    Hl.resize(m_base - 1);
    Mu.resize(60 / m_base - 1);
    Ml.resize(m_base - 1);
    Su.resize(60 / m_base - 1);
    Sl.resize(m_base - 1);

    for (int i = 0; i < (24 - 1) / m_base; i++) {
        Hu[i] = new Light();
        Hu[i]->setWidth(Light::Width::Large);
    }

    for (int i = 0; i < m_base - 1; i++) {
        Hl[i] = new Light();
        Hl[i]->setWidth(Light::Width::Large);

        Ml[i] = new Light();
        Ml[i]->setWidth(Light::Width::Large);

        Sl[i] = new Light();
        Sl[i]->setWidth(Light::Width::Large);
    }

    for (int i = 0; i < 60 / m_base - 1; i++) {
        Mu[i] = new Light();
        Mu[i]->setWidth(Light::Width::Small);

        Su[i] = new Light();
        Su[i]->setWidth(Light::Width::Small);
    }

    // Add lights to layouts
    QHBoxLayout* line_Hu = new QHBoxLayout;
    QHBoxLayout* line_Hl = new QHBoxLayout;
    QHBoxLayout* line_Mu = new QHBoxLayout;
    QHBoxLayout* line_Ml = new QHBoxLayout;
    QHBoxLayout* line_Su = new QHBoxLayout;
    QHBoxLayout* line_Sl = new QHBoxLayout;

    for (int i = 0; i < (24 - 1) / m_base; i++) {
        line_Hu->addWidget(Hu[i]);
    }

    for (int i = 0; i < m_base - 1; i++) {
        line_Hl->addWidget(Hl[i]);
        line_Ml->addWidget(Ml[i]);
        line_Sl->addWidget(Sl[i]);
    }

    for (int i = 0; i < 60 / m_base - 1; i++) {
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

    for (int i = 0; i < (24 - 1) / m_base; ++i) {
        Hu[i]->setColor((patternMaker->m_Hu[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
    }

    for (int i = 0; i < m_base - 1; ++i) {
        Hl[i]->setColor((patternMaker->m_Hl[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
        Ml[i]->setColor((patternMaker->m_Ml[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
        Sl[i]->setColor((patternMaker->m_Sl[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
    }

    for (int i = 0; i < 60 / m_base - 1; ++i) {
        Mu[i]->setColor((patternMaker->m_Mu[i] == 1)
                            ? (((i + 1) * m_base % 15) ? Light::Bright_Yellow : Light::Bright_Red)
                            : (((i + 1) * m_base % 15) ? Light::Dark_Yellow : Light::Dark_Red));

        Su[i]->setColor((patternMaker->m_Su[i] == 1)
                            ? (((i + 1) * m_base % 15) ? Light::Bright_Yellow : Light::Bright_Red)
                            : (((i + 1) * m_base % 15) ? Light::Dark_Yellow : Light::Dark_Red));
    }
}

void Watch::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_T) {
        // Toggle the translucency on 'T' key press
        bool isTransparent = this->testAttribute(Qt::WA_TranslucentBackground);
        this->setAttribute(Qt::WA_TranslucentBackground, !isTransparent);

        if (isTransparent) {
            this->setStyleSheet(
                "background-color: rgba(255, 255, 255, 255);"); // Opaque white background
        } else {
            this->setStyleSheet(
                "background-color: rgba(255, 255, 255, 0);"); // Transparent background
        }

        this->update(); // Ensure the window updates its appearance
    } else {
        // QMainWindow::keyPressEvent(event); // Call base class handler
    }
}
