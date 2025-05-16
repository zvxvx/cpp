#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
  string name;

public:
  Shape(const string &_name) : name{_name} {};
  virtual ~Shape() {};
  const double PI = 3.14159265358979;
  virtual void printDetail() const = 0;
  virtual string getType() const = 0;
};
#endif
