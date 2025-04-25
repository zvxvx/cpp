/**
 * Assignment 3
 * Greg Pappas
 * g++ -std=c++17 *.cpp
 */
#include "ColorBlob.h"

// default constructor
ColorBlob::ColorBlob() : cb_w{2}, cb_h{2} {
  cb_d = new Color*[cb_h];
  for (int i = 0; i < cb_h; i++) {
    cb_d[i] = new Color[cb_w];
    for (int j = 0; j < cb_w; j++) {
      cb_d[i][j] = Color();
    }
  }
};
// explicit constructor
ColorBlob::ColorBlob(int w, int h, Color c) : cb_w{w}, cb_h{h} {
  cb_d = new Color*[h];
  for (int i = 0; i < h; i++) {
    cb_d[i] = new Color[w];
    for (int j = 0; j < w; j++) {
      cb_d[i][j] = c;
    }
  }
};
// copy constructor
ColorBlob::ColorBlob(const ColorBlob& cb) : cb_w{cb.cb_w}, cb_h{cb.cb_h} {
  cb_d = new Color*[cb_h];
  for (int i = 0; i < cb_h; i++) {
    cb_d[i] = new Color[cb_w];
    for (int j = 0; j < cb_w; j++) {
      cb_d[i][j] = cb.cb_d[i][j];
    }
  }
};
// move constructor
ColorBlob::ColorBlob(ColorBlob&& cb) noexcept {
  cb_w = cb.cb_w;
  cb_h = cb.cb_h;
  cb_d = cb.cb_d;

  cb.cb_w = 0;
  cb.cb_h = 0;
  cb.cb_d = nullptr;
}
// destructor
ColorBlob::~ColorBlob() {
  for (int i = 0; i < cb_h; i++) {
    delete[] cb_d[i];
  }
  delete[] cb_d;

  cb_d = nullptr;
  cb_h = 0;
  cb_w = 0;
};
// copy assignment
ColorBlob& ColorBlob::operator=(const ColorBlob& cb) {
  if (this == &cb) return *this;

  for (int i = 0; i < cb_h; i++) {
    delete[] cb_d[i];
  }
  delete[] cb_d;

  cb_w = cb.cb_w;
  cb_h = cb.cb_h;

  cb_d = new Color*[cb_h];
  for (int i = 0; i < cb_h; i++) {
    cb_d[i] = new Color[cb_w];
    for (int j = 0; j < cb_w; j++) {
      cb_d[i][j] = cb.cb_d[i][j];
    }
  }
  return *this;
}
// move assignment
ColorBlob& ColorBlob::operator=(ColorBlob&& cb) noexcept {
  if (this != &cb) {
    delete[] cb_d;
    cb_w = 0;
    cb_h = 0;

    cb_w = cb.cb_w;
    cb_h = cb.cb_h;
    cb_d = cb.cb_d;

    cb.cb_w = 0;
    cb.cb_h = 0;
    cb.cb_d = nullptr;
  }
  return *this;
}
// equals operator
bool operator==(const ColorBlob& cb1, const ColorBlob& cb2) {
  if (cb1.cb_w != cb2.cb_w || cb1.cb_h != cb2.cb_h) return false;

  for (int i = 0; i < cb1.cb_h; i++) {
    for (int j = 0; j < cb1.cb_w; j++) {
      if (!(cb1.cb_d[i][j] == cb2.cb_d[i][j])) {
        return false;
      }
    }
  }
  return true;
}
// addition operator
ColorBlob operator+(const ColorBlob& cbOne, const ColorBlob& cbTwo) {
  double newHeight = std::min(cbOne.cb_h, cbTwo.cb_h);
  double newWidth = std::min(cbOne.cb_w, cbTwo.cb_w);
  ColorBlob newCB(newWidth, newHeight, Color());

  for (int i = 0; i < newHeight; i++) {
    for (int j = 0; j < newWidth; j++) {
      double newBlue = std::clamp(
          cbOne.cb_d[i][j].getBlue() + cbTwo.cb_d[i][j].getBlue(), 0.0, 1.0);
      double newRed = std::clamp(
          cbOne.cb_d[i][j].getRed() + cbTwo.cb_d[i][j].getRed(), 0.0, 1.0);
      double newGreen = std::clamp(
          cbOne.cb_d[i][j].getGreen() + cbTwo.cb_d[i][j].getGreen(), 0.0, 1.0);

      newCB.cb_d[i][j].setBlue(newBlue);
      newCB.cb_d[i][j].setRed(newRed);
      newCB.cb_d[i][j].setGreen(newGreen);
    }
  }
  return newCB;
};
// subtraction operator
ColorBlob operator-(const ColorBlob& cbOne, const ColorBlob& cbTwo) {
  double newHeight = std::min(cbOne.cb_h, cbTwo.cb_h);
  double newWidth = std::min(cbOne.cb_w, cbTwo.cb_w);
  ColorBlob newCB(newWidth, newHeight, Color());

  for (int i = 0; i < newHeight; i++) {
    for (int j = 0; j < newWidth; j++) {
      double newBlue = std::clamp(
          cbOne.cb_d[i][j].getBlue() - cbTwo.cb_d[i][j].getBlue(), 0.0, 1.0);
      double newRed = std::clamp(
          cbOne.cb_d[i][j].getRed() - cbTwo.cb_d[i][j].getRed(), 0.0, 1.0);
      double newGreen = std::clamp(
          cbOne.cb_d[i][j].getGreen() - cbTwo.cb_d[i][j].getGreen(), 0.0, 1.0);

      newCB.cb_d[i][j].setBlue(newBlue);
      newCB.cb_d[i][j].setRed(newRed);
      newCB.cb_d[i][j].setGreen(newGreen);
    }
  }
  return newCB;
};
// multiplication operator
ColorBlob operator*(const ColorBlob& cbOne, const Color& c) {
  ColorBlob newCB(cbOne.cb_w, cbOne.cb_h, Color());

  for (int i = 0; i < cbOne.cb_h; i++) {
    for (int j = 0; j < cbOne.cb_w; j++) {
      double newBlue =
          std::clamp(cbOne.cb_d[i][j].getBlue() * c.getBlue(), 0.0, 1.0);
      double newRed =
          std::clamp(cbOne.cb_d[i][j].getRed() * c.getRed(), 0.0, 1.0);
      double newGreen =
          std::clamp(cbOne.cb_d[i][j].getGreen() * c.getGreen(), 0.0, 1.0);

      newCB.cb_d[i][j].setBlue(newBlue);
      newCB.cb_d[i][j].setRed(newRed);
      newCB.cb_d[i][j].setGreen(newGreen);
    }
  }
  return newCB;
};
// not operator
bool operator!(const ColorBlob& cb) {
  for (int i = 0; i < cb.cb_h; i++) {
    for (int j = 0; j < cb.cb_w; j++) {
      if (cb.cb_d[i][j].getBlue() == 0.0 && cb.cb_d[i][j].getGreen() == 0.0 &&
          cb.cb_d[i][j].getRed() == 0.0) {
        return false;
      }
    }
  }
  return true;
};
// output operator
ostream& operator<<(ostream& os, const ColorBlob& cb) {
  for (int i = 0; i < cb.cb_h; i++) {
    for (int j = 0; j < cb.cb_w; j++) {
      os << "[" << i << "]" << "[" << j << "]: (" << cb.cb_d[i][j].getRed()
         << "\t" << cb.cb_d[i][j].getGreen() << "\t" << cb.cb_d[i][j].getBlue()
         << ")" << endl;
    }
  }
  return os;
};
// input operator
istream& operator>>(istream& is, ColorBlob& cb) {
  for (int i = 0; i < cb.cb_h; i++) {
    for (int j = 0; j < cb.cb_w; j++) {
      cout << "[" << i << "]" << "[" << j << "]: ";
      is >> cb.cb_d[i][j];
    }
  }
  return is;
};
