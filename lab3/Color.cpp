#include "Color.h"

Color::Color() : c_red{0.5}, c_green{0.5}, c_blue{0.5} {};
Color::Color(double r, double g, double b)
    : c_red{min(r, 1.0)}, c_green{min(g, 1.0)}, c_blue{min(b, 1.0)} {};
Color::Color(const Color& c)
    : c_red{c.c_red}, c_green{c.c_green}, c_blue{c.c_green} {};

double Color::getRed() const { return this->c_red; }
double Color::getGreen() const { return this->c_green; }
double Color::getBlue() const { return this->c_blue; }

Color& Color::setRed(double r) { this->c_red = r; }
Color& Color::setGreen(double r) { this->c_green = r; }
Color& Color::setBlue(double r) { this->c_blue = r; }

Color& Color::operator=(const Color& c) {
  this->c_red = c.c_red;
  this->c_green = c.c_green;
  this->c_blue = c.c_blue;
}
bool operator==(const Color& cOne, const Color& cTwo) {
  return cOne.c_red == cTwo.c_red && cOne.c_green == cTwo.c_green &&
         cOne.c_blue == cTwo.c_blue;
}
Color operator+(const Color& cOne, const Color& cTwo) {
  Color added = Color();
  added.c_red = clamp(cOne.c_red + cTwo.c_red, 0.0, 1.0);
  added.c_green = clamp(cOne.c_green + cTwo.c_green, 0.0, 1.0);
  added.c_blue = clamp(cOne.c_blue + cTwo.c_blue, 0.0, 1.0);
  return added;
}