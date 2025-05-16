#ifndef TRIANGLE
#define TRIANGLE

#include "Shape2D.h"

class Triangle : public Shape2D {
private:
  double base;
  double height;

public:
  Triangle(string n, double b, double h) : Shape2D{n}, base{b}, height{h} {};
  double computeArea() const override { return (base * height) / 2; };
  void printDetail() const override {
    cout << name << ", " << getType() << ", base: " << base
         << ", height: " << height << ", area: " << computeArea() << endl;
  }
};
#endif
