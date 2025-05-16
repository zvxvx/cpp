#ifndef CIRCLE
#define CIRCLE

#include "Shape2D.h"

class Circle : public Shape2D {
private:
  double radius;

public:
  Circle(string n, double r) : Shape2D{n}, radius{r} {};
  double computeArea() const override { return Shape::PI * (radius * radius); };
  void printDetail() const override {
    cout << name << ", " << getType() << ", radius: " << radius
         << ", area: " << computeArea() << endl;
  }
};
#endif
