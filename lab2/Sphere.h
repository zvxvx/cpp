#ifndef SPHERE_H
#define SPHERE_
#include "Point3D.h"

class Sphere {
  Point3D s_center;
  double s_radius;

 public:
  Sphere();
  Sphere(Point3D, double);

  Point3D getCenter() const;
  double getRadius() const;

  Sphere& setCenter(Point3D);
  Sphere& setRadius(double);
};

#endif  // SPHERE_
