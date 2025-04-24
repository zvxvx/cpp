#include "ColorBlob.h"

ColorBlob::ColorBlob() : cb_w{2}, cb_h{2} {
  cb_d = new Color*[cb_h];
  for (int i = 0; i < cb_h; i++) {
    cb_d[i] = new Color[cb_w];
    for (int j = 0; j < cb_w; j++) {
      cb_d[i][j] = Color();
    }
  }
};
ColorBlob::ColorBlob(int w, int h, Color c) : cb_w{w}, cb_h{h} {
  cb_d = new Color*[h];
  for (int i = 0; i < h; i++) {
    cb_d[i] = new Color[w];
    for (int j = 0; j < w; j++) {
      cb_d[i][j] = c;
    }
  }
};
ColorBlob::ColorBlob(const ColorBlob& cb) : cb_w{cb.cb_w}, cb_h{cb.cb_h} {
  cb_d = new Color*[cb_h];
  for (int i = 0; i < cb_h; i++) {
    cb_d[i] = new Color[cb_w];
    for (int j = 0; j < cb_w; j++) {
      cb_d[i][j] = cb.cb_d[i][j];
    }
  }
};
ColorBlob::ColorBlob(ColorBlob&& cb) noexcept {
  cb_w = cb.cb_w;
  cb_h = cb.cb_h;
  cb_d = cb.cb_d;
  cb.cb_w = 0;
  cb.cb_h = 0;
  cb.cb_d = nullptr;
}
ColorBlob::~ColorBlob() {
  for (int i = 0; i < cb_h; i++) {
    delete[] cb_d[i];
  }
  delete[] cb_d;
  cb_d = nullptr;
  cb_h = 0;
  cb_w = 0;
};

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
}

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

  return (*this);
}

bool operator==(const ColorBlob& cb1, const ColorBlob& cb2) {
  if (cb1.cb_w != cb2.cb_w && cb1.cb_h != cb2.cb_h) return false;

  for (int i = 0; i < cb1.cb_h; i++) {
    for (int j = 0; j < cb1.cb_w; j++) {
      if (!(cb1.cb_d[i][j] == cb2.cb_d[i][j])) {
        return false;
      }
    }
  }
  return true;
}

ColorBlob operator+(const ColorBlob& cbOne, const ColorBlob& cbTwo) {
  double newHeight = std::min(cbOne.cb_h, cbTwo.cb_h);
  double newWidth = std::min(cbOne.cb_w, cbTwo.cb_w);
  ColorBlob added(newWidth, newHeight, Color());

  for (int i = 0; i < newHeight; i++) {
    for (int j = 0; j < newWidth; j++) {
      double newBlue = std::min(
          cbOne.cb_d[i][j].getBlue() + cbTwo.cb_d[i][j].getBlue(), 1.0);
      double newRed =
          std::min(cbOne.cb_d[i][j].getRed() + cbTwo.cb_d[i][j].getRed(), 1.0);
      double newGreen = std::min(
          cbOne.cb_d[i][j].getGreen() + cbTwo.cb_d[i][j].getGreen(), 1.0);

      added.cb_d[i][j].setBlue(newBlue);
      added.cb_d[i][j].setRed(newRed);
      added.cb_d[i][j].setGreen(newGreen);
    }
  }
  return added;
};

ColorBlob operator-(const ColorBlob& cbOne, const ColorBlob& cbTwo);

ColorBlob operator*(const ColorBlob& cbOne, const ColorBlob& cbTwo);

bool operator!(const ColorBlob& cb) {

};

ostream& operator<<(ostream& os, const ColorBlob& cb) {
  for (int i = 0; i < cb.cb_h; i++) {
    for (int j = 0; j < cb.cb_w; j++) {
      os << "[" << i << "]" << "[" << j << "]: " << cb.cb_d << endl;
    }
  }
};

istream& operator>>(istream& is, ColorBlob& cb) {
  for (int i = 0; i < cb.cb_h; i++) {
    for (int j = 0; j < cb.cb_w; j++) {
      cout << "[" << i << "]" << "[" << j << "]: ";
      is >> cb.cb_d[i][j];
    }
  }
};
