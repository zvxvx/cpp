#ifndef SHAPE_2D
#define SHAPE_2D

#include "Shape.h"

class Shape2D : public Shape {
public:
  Shape2D(string &n) : Shape{n} {};
  ~Shape2D() {};
  string getType() const override { return "2D Shape"; };
  void printDetail();
  virtual double computeArea() const = 0;
};
#endif
