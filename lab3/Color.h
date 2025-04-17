#include <iostream>

class Color {
  double red = 0.5;
  double green = 0.5;
  double blue = 0.5;

 public:
  friend bool operator==(const Color& cOne, const Color& cTwo);
  friend Color operator+(const Color& cOne, const Color& cTwo);
  friend Color operator-(const Color& cOne, const Color& cTwo);
  friend Color operator*(const Color& cOne, const Color& cTwo);
  friend bool operator!(const Color& cOne);
  friend std::ostream& operator<<(std::ostream&, const Color&);
  friend std::istream& operator>>(std::istream&, Color&);
};