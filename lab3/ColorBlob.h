#ifndef COLORBLOB_H
#define COLORBLOB_H

#include "Color.h"

class ColorBlob {
  int cb_w;
  int cb_h;
  Color** cb_d;

 public:
  ColorBlob(); // default
  ColorBlob(int, int, Color); // explicit
  ColorBlob(const ColorBlob&); // copy constructor
  ColorBlob(ColorBlob&&) noexcept; // move constructor
  ~ColorBlob(); //destructor

  ColorBlob& operator=(const ColorBlob& cb); // copy assignment
  ColorBlob& operator=(ColorBlob&& other) noexcept; // move assignment

  friend bool operator==(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator+(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator-(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator*(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend bool operator!(const ColorBlob& cb);
  friend ostream& operator<<(ostream& os, const ColorBlob& cb);
  friend istream& operator>>(istream& is, ColorBlob& cb);
};

#endif