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
  (*this).cb_w = cb_w;
  (*this).cb_h = cb_h;
  (*this).cb_d = cb_d;
  cb_w = 0;
  cb_h = 0;
  cb_d = nullptr;
}
ColorBlob::~ColorBlob() {
  for (int i = 0; i < cb_h; i++) {
    delete[] cb_d[i];
  }
  delete[] cb_d;
  cb_d = nullptr;
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

ColorBlob& ColorBlob::operator=(ColorBlob&& cb) noexcept {}

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

ColorBlob operator+(const ColorBlob& cbOne, const ColorBlob& cbTwo);

ColorBlob operator-(const ColorBlob& cbOne, const ColorBlob& cbTwo);

ColorBlob operator*(const ColorBlob& cbOne, const ColorBlob& cbTwo);

bool operator!(const ColorBlob& cb);

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
