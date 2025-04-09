#include "Point2D.h"

Point2D::Point2D() :X{ 0 }, Y{ 0 }{}

Point2D::Point2D(double xP, double yP) : X{ xP }, Y{ yP } { }


double Point2D::getX() const {
	return this->X;
}
double Point2D::getY() const {
	return this->Y;
}

Point2D& Point2D::setX(double xP) {
	this->X = xP;
	return (*this);
}
Point2D& Point2D::setY(double yP) {
	this->Y = yP;
	return (*this);
}

Point2D& Point2D::addPoints(const Point2D& vec) {
	this->X += vec.X;
	this->Y += vec.Y;
	return (*this);
}

double  Point2D::multiplyPoints(const Point2D& vec) {

	double val = (this->X * vec.X) + (this->Y * vec.Y);
	return val;
}
