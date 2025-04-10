#include "Ray.h"

#include <iostream>

Ray::Ray() : r_origin{0, 0, 0}, r_direction{0, 0, 0} {};
Ray::Ray(Point3D o, Point3D d) : r_origin{o}, r_direction{d} {};

Point3D Ray::getOrigin() const { return this->r_origin; }
Point3D Ray::getDirection() const { return this->r_direction; }

Ray& Ray::setOrigin(Point3D o) {
  this->r_origin = o;
  return (*this);
}
Ray& Ray::setDirection(Point3D d) {
  this->r_direction = d;
  return (*this);
}

void Ray::checkIntersection(Sphere& s) {
  double a = this->r_direction.squarePoints();
  double b = this->r_origin.subtractPoints(s.getCenter())
                 .multiplyPoints(this->r_direction);
  double c = (this->r_origin.subtractPoints(s.getCenter()).squarePoints()) -
             (s.getRadius() * s.getRadius());
  double result = (b * b) - (a * c);

  if (result < 0) {
    std::cout << "Ray does not touch or intersect the sphere." << std::endl;
  } else {
    std::cout << "Ray either touches or intersects the sphere." << std::endl;
  }
  std::cout << result << std::endl;
}