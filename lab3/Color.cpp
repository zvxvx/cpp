/**
 * Assignment 3
 * Greg Pappas
 * g++ -std=c++17 *.cpp
 */
#include "Color.h"

Color::Color() : c_red{0.5}, c_green{0.5}, c_blue{0.5} {};

Color::Color(double r, double g, double b)
    : c_red{clamp(r, 0.0, 1.0)},
      c_green{clamp(g, 0.0, 1.0)},
      c_blue{clamp(b, 0.0, 1.0)} {};

Color::Color(const Color& c)
    : c_red{c.c_red}, c_green{c.c_green}, c_blue{c.c_blue} {}

double Color::getRed() const { return this->c_red; }
double Color::getGreen() const { return this->c_green; }
double Color::getBlue() const { return this->c_blue; }

Color& Color::setRed(double r) {
  this->c_red = clamp(r, 0.0, 1.0);
  return *this;
}
Color& Color::setGreen(double g) {
  this->c_green = clamp(g, 0.0, 1.0);
  return *this;
}
Color& Color::setBlue(double b) {
  this->c_blue = clamp(b, 0.0, 1.0);
  return *this;
}

Color& Color::operator=(const Color& c) {
  this->c_red = c.c_red;
  this->c_green = c.c_green;
  this->c_blue = c.c_blue;
  return *this;
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
Color operator-(const Color& cOne, const Color& cTwo) {
  Color subtracted = Color();
  subtracted.c_red = clamp(cOne.c_red - cTwo.c_red, 0.0, 1.0);
  subtracted.c_green = clamp(cOne.c_green - cTwo.c_green, 0.0, 1.0);
  subtracted.c_blue = clamp(cOne.c_blue - cTwo.c_blue, 0.0, 1.0);
  return subtracted;
}
Color operator*(const Color& cOne, const Color& cTwo) {
  Color multiplied = Color();
  multiplied.c_red = clamp(cOne.c_red * cTwo.c_red, 0.0, 1.0);
  multiplied.c_green = clamp(cOne.c_green * cTwo.c_green, 0.0, 1.0);
  multiplied.c_blue = clamp(cOne.c_blue * cTwo.c_blue, 0.0, 1.0);
  return multiplied;
}
bool operator!(const Color& c) {
  return c.c_red == 0.0 && c.c_green == 0.0 && c.c_blue == 0.0;
}
ostream& operator<<(ostream& os, const Color& c) {
  os << "Red: " << c.c_red << " Green: " << c.c_green << " Blue: " << c.c_blue
     << endl;
  return os;
}
istream& operator>>(istream& is, Color& c) {
  double r, g, b;
  is >> r >> g >> b;
  c.setRed(r);
  c.setGreen(g);
  c.setBlue(b);
  return is;
}