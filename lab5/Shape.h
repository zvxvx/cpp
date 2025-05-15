#include <string>
class Shape {
protected:
  std::string name;

public:
  Shape(const std::string &_name) : name{_name} {};
  virtual ~Shape() {};
  const double PI = 3.14159265358979;
  virtual void printShapeDetail() const = 0;
  virtual std::string getType() const = 0;
};
