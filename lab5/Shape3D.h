#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "Shape2D.h"

class Shape3D : public Shape2D {
public:
  Shape3D(string &n) : Shape2D{n} {};
  ~Shape3D() {};
  void printDetail();
  string getType() const override { return "3D Shape"; };
  virtual double computeVolume() const = 0;
};
#endif
