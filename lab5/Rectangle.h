#ifndef RECTANGLE
#define RECTANGLE

#include "Shape2D.h"

class Rectangle : public Shape2D {
private:
  double width;
  double height;

public:
  Rectangle(string n, double b, double h) : Shape2D{n}, width{b}, height{h} {};
  double computeArea() const override { return (width * height); };
  void printDetail() const override {
    cout << name << ", " << getType() << ", width: " << width
         << ", height: " << height << ", area: " << computeArea() << endl;
  }
};
#endif
