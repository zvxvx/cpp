/**
 * Assignment 3
 * Greg Pappas
 * g++ -std=c++17 *.cpp
 */
#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

class Color {
  double c_red = 0.5;
  double c_green = 0.5;
  double c_blue = 0.5;

 public:
  Color();                              // default
  Color(double r, double g, double b);  // explicit
  Color(const Color& c);                // copy
  // getters
  double getRed() const;
  double getGreen() const;
  double getBlue() const;
  // setters
  Color& setRed(double);
  Color& setGreen(double);
  Color& setBlue(double);

  Color& operator=(const Color& c);  // copy assignment

  friend bool operator==(const Color& cOne, const Color& cTwo);
  friend Color operator+(const Color& cOne, const Color& cTwo);
  friend Color operator-(const Color& cOne, const Color& cTwo);
  friend Color operator*(const Color& cOne, const Color& cTwo);
  friend bool operator!(const Color& c);
  friend ostream& operator<<(ostream&, const Color& c);
  friend istream& operator>>(istream&, Color& c);
};
#endif