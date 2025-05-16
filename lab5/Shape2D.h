#include "Shape.h"

class Shape2D : public Shape {
public:
  Shape2D(string n) : Shape{n} {};
  ~Shape2D() {};
  virtual double computeArea() const = 0;
  string getType() const override { return "Shape2D"; };
  void printShapeDetail() const override {};
};
