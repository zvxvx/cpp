#ifndef CYLINDER
#define CYLINDER

#include "Shape3D.h"

class Cylinder : public Shape3D {
private:
  double height;
  double radius;

public:
  Cylinder(string n, double r, double h) : Shape3D{n}, radius{r}, height{h} {};
  double computeArea() const override {
    return (2 * Shape::PI * radius * height) +
           2 * Shape::PI * (radius * radius);
  }
  double computeVolume() const override {
    return Shape::PI * (radius * radius) * height;
  };
  void printDetail() const override {
    cout << name << ", " << getType() << ", radius: " << radius
         << ", height: " << height << ", area: " << computeArea()
         << ", volume: " << computeVolume() << endl;
  }
};
#endif
