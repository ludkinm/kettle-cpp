#include "crtp_interface/op_plus.hpp"
#include <iostream>
#include <type_traits>

struct Point : public crtpi::op_plus<Point> {
  int x;
  int y;

  explicit Point(int a = 0, int b = 0) : x{a}, y{b} {}

  friend Point &operator+=(Point &lhs, Point const &rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
  }
  friend std::ostream &operator<<(std::ostream &os, Point const &p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};

struct P {
  int x, y;
};

int main() {
  LOG_EXPR(crtpi::has_op_plus_assign_v<void>);
  LOG_EXPR(crtpi::has_op_plus_assign_v<int>);
  LOG_EXPR(crtpi::has_op_plus_assign_v<double>);
  LOG_EXPR(crtpi::has_op_plus_assign_v<std::nullptr_t>);
  LOG_EXPR(crtpi::has_op_plus_assign_v<Point>);

  // Point is an aggregate but the first element is
  // crtpi::op_plus<Point> which needs initialising...
  Point p{1, 2};
  Point q{2, 3};
  std::cout << "p=" << p << '\n';
  std::cout << "q=" << q << '\n';
  std::cout << "p+=q\n";
  p += q;
  std::cout << "p=" << p << '\n';
  Point r = p + q;
  std::cout << "r=p+q=" << r << '\n';
  Point s{r};

  { // this is not allowed:
    // crtpi::op_plus<Point> *x = new Point(1, 2);
    // delete x;
  }
}
