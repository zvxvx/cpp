#include "Shape2D.h"

class Shape3D : public Shape2D {
public:
  virtual double computeVolume() const = 0;
  string getType() { return "Shape3D"; };
};
