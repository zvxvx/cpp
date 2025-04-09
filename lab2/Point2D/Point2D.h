#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
using namespace std;

class Point2D {
	double X, Y;
public:
	Point2D(); // Default Constructor
	Point2D(double, double); // Constructor with Parameter
	double getX() const;
	double getY() const;
	Point2D& setX(double);
	Point2D& setY(double);
	Point2D& addPoints(const Point2D&);
	double multiplyPoints(const Point2D& vec);

};
#endif