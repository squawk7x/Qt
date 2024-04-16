#include "lights.h"

Light::Light(QWidget* parent)
    : QPushButton(parent)
    , m_width(Large)
    , m_color(Dark_Yellow)
{
    // Set initial properties
    setFixedSize(50, 50);  // Default size
    setColor(Dark_Yellow); // Default color
}

void Light::setWidth(Width width)
{
    m_width = width;
    // Adjust size based on width
    if (width == Small) {
        setFixedSize(40, height());
    } else {
        setFixedSize(120, height());
    }
}

void Light::setColor(Color color)
{
    m_color = color;
    // Change color based on selected color
    switch (color) {
    case Dark_Yellow:
        setStyleSheet("background-color: #808000;"); // Dark Yellow color
        break;
    case Bright_Yellow:
        setStyleSheet("background-color: #FFFF00;"); // Bright Yellow color
        break;
    case Dark_Red:
        setStyleSheet("background-color: #800000;"); // Dark Red color
        break;
    case Bright_Red:
        setStyleSheet("background-color: #FF0000;"); // Bright Red color
        break;
    }
};

RoundLight::RoundLight(QWidget* parent, int size)
    : Light(parent)
{
    this->setFixedSize(size, size);
}
