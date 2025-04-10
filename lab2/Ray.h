/*
Assignment 2
Programmer: Greg Pappas
Compiler: g++
*/

#ifndef RAY_H
#define RAY_H

#include "Point3D.h"
#include "Sphere.h"

class Ray {
  Point3D r_origin;
  Point3D r_direction;

 public:
  Ray();
  Ray(Point3D, Point3D);

  Point3D getOrigin() const;
  Point3D getDirection() const;

  Ray& setOrigin(Point3D);
  Ray& setDirection(Point3D);

  void checkIntersection(Sphere&);
};

#endif  // RAY_H
