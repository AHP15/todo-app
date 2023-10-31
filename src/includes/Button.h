#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <string_view>

#include <Style.h>

class Button
{
public:
    struct Point
    {
        int x {};
        int y {};
    };
    Button(std::string_view text, const Point& point)
        : m_text { text }, m_point{ point }
    {}

    using Color = Style::Color;
    void setText(std::string_view text) { m_text = text; }
    void setStyle(Style& style) { m_style = style; }
    void setBackground(Color& color) { m_style.background = color; }
    void setForeground(Color& color) { m_style.foreground = color; }
    void setWidth(int width) { m_style.width = width; }
    void setHeight(int height) { m_style.height = height; }
    void setFontSize(int fontSize) { m_style.fontSize = fontSize; }

    const std::string& getText() const { return m_text; }
    const Style& getStyle() const { return m_style; }
    const Point& getPoint() const { return m_point; }

private:
    std::string m_text{};
    Style m_style{};
    Point m_point{};
};

#endif