#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
  double p_x, p_y, p_z;

 public:
  Point3D();
  Point3D(double, double, double);
  double getX() const;
  double getY() const;
  double getZ() const;
  Point3D& setX(double);
  Point3D& setY(double);
  Point3D& setZ(double);
  Point3D& addPoints(const Point3D&);
  Point3D& subtractPoints(const Point3D&);
  double multiplyPoints(const Point3D& vec);
  double squarePoints();
};
#endif  // POINT3D_H
