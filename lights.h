#ifndef LIGHTS_H
#define LIGHTS_H

#include <QPushButton>

class Light : public QPushButton
{
    Q_OBJECT

public:
    Light(QWidget* parent = nullptr);

    enum Width { Large, Small };
    enum Color { Dark_Yellow, Bright_Yellow, Dark_Red, Bright_Red };

    void setWidth(Width width);
    void setColor(Color color);

private:
    Width m_width;
    Color m_color;
};

class RoundLight : public Light
{
    Q_OBJECT

public:
    RoundLight(QWidget* parent = nullptr, int size = 100);

private:
    int m_size;
    void setSize(int m_size);
};

#endif // LIGHTS_H
