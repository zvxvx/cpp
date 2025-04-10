#include "Point3D.h"

Point3D::Point3D() : p_x{0}, p_y{0}, p_z{0} {};
Point3D::Point3D(double x, double y, double z) : p_x{x}, p_y{y}, p_z{z} {};

double Point3D::getX() const { return this->p_x; }
double Point3D::getY() const { return this->p_y; }
double Point3D::getZ() const { return this->p_z; }

Point3D& Point3D::setX(double x) {
  this->p_x = x;
  return (*this);
}
Point3D& Point3D::setY(double y) {
  this->p_y = y;
  return (*this);
}
Point3D& Point3D::setZ(double z) {
  this->p_z = z;
  return (*this);
}
Point3D& Point3D::addPoints(const Point3D& p) {
  this->p_x += p.p_x;
  this->p_y += p.p_y;
  this->p_z += p.p_z;
  return (*this);
}
Point3D& Point3D::subtractPoints(const Point3D& p) {
  this->p_x -= p.p_x;
  this->p_y -= p.p_y;
  this->p_z -= p.p_z;
  return (*this);
}

double Point3D::multiplyPoints(const Point3D& p) {
  return (this->p_x * p.p_x) + (this->p_y * p.p_y) + (this->p_z * p.p_z);
}
double Point3D::squarePoints() {
  return (this->p_x * this->p_x) + (this->p_y * this->p_y) +
         (this->p_z * this->p_z);
}