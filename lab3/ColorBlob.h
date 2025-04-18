#ifndef COLORBLOB_H
#define COLORBLOB_H

#include "Color.h"

class ColorBlob {
  int cb_w;
  int cb_h;
  Color** cb_d;

 public:
  ColorBlob();
  ColorBlob(int w, int h, Color** colors);
  ColorBlob(const ColorBlob& cb);
  ColorBlob(ColorBlob&& other) noexcept;
  ~ColorBlob();

  ColorBlob& operator=(const ColorBlob& cb);
  ColorBlob& operator=(ColorBlob&& other) noexcept;

  friend bool operator==(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator+(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator-(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend ColorBlob operator*(const ColorBlob& cbOne, const ColorBlob& cbTwo);
  friend bool operator!(const ColorBlob& cb);
  friend ostream& operator<<(ostream& os, ColorBlob& cb);
  friend istream& operator>>(istream& is, ColorBlob& cb);
};

#endif