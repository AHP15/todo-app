#ifndef STYLE_H
#define STYLE_H

struct Style
{
    struct Color
    {
        short red{};
        short blue{};
        short green{};
        float opacity{};
    };  
    Color foreground{};
    Color background{};
    int width{};
    int height{};
    short fontSize{};
};
#endif
