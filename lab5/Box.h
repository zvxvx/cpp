#ifndef BOX
#define BOX

#include "Shape3D.h"

class Box : public Shape3D {
private:
  double width;
  double height;
  double depth;

public:
  Box(string n, double w, double h, double d)
      : Shape3D{n}, width{w}, height{h}, depth{d} {};
  double computeVolume() const override { return width * height * depth; };
  double computeArea() const override {
    return 2 * (width * height) + 2 * (width * depth) + 2 * (height * depth);
  }
  void printDetail() const override {
    cout << name << ", " << getType() << ", width: " << width
         << ", height: " << height << ", depth: " << depth
         << ", area: " << computeArea() << ", volume: " << computeVolume()
         << endl;
  }
};
#endif
