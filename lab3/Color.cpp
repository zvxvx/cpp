#include "Color.h"

Color::Color() : c_red{0.5}, c_green{0.5}, c_blue{0.5} {};
Color::Color(double r, double g, double b) : c_red{r}, c_green{g}, c_blue{b} {};
Color::Color(const Color& c)
    : c_red{c.c_red}, c_green{c.c_green}, c_blue{c.c_green} {};