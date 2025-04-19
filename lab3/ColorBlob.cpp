#include "ColorBlob.h"

ColorBlob::ColorBlob() : cb_w{2}, cb_h{2}, cb_d{new Color*[4]} {};
ColorBlob::ColorBlob(int w, int h, Color** colors)
    : cb_w{w}, cb_h{h}, cb_d{colors} {};
ColorBlob::ColorBlob(const ColorBlob& cb) {
  (*this).cb_w = cb.cb_w;
  (*this).cb_h = cb.cb_h;
  (*this).cb_d = cb.cb_d;
}
ColorBlob::ColorBlob(ColorBlob&& cb) noexcept {
  (*this).cb_w = cb_w;
  (*this).cb_h = cb_h;
  (*this).cb_d = cb_d;
  cb_w = 0;
  cb_h = 0;
  cb_d = nullptr;
}
ColorBlob::~ColorBlob() {};

ColorBlob& ColorBlob::operator=(ColorBlob&& cb) noexcept {

}
