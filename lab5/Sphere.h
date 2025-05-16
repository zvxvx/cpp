#ifndef SPHERE
#define SPHERE

#include "Shape3D.h"

class Sphere : public Shape3D {
private:
  double radius;

public:
  Sphere(string n, double r) : Shape3D{n}, radius{r} {};
  double computeArea() const override {
    return 4 * Shape::PI * (radius * radius);
  }
  double computeVolume() const override {
    return (4 * Shape::PI * (radius * radius * radius) / 3);
  };
  void printDetail() const override {
    cout << name << ", " << getType() << ", radius: " << radius
         << ", area: " << computeArea() << ", volume: " << computeVolume()
         << endl;
  }
};
#endif
