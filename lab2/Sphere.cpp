#include "Sphere.h"

Sphere::Sphere() : s_center{0, 0, 0}, s_radius{0} {};
Sphere::Sphere(Point3D c, double r) : s_center{c}, s_radius{r} {};

Point3D Sphere::getCenter() const { return this->s_center; }
double Sphere::getRadius() const { return this->s_radius; }
