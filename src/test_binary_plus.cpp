#include <crtp_interface/binary_plus.hpp>
#include <crtp_interface/log_expr.hpp>
#include <crtp_interface/traits/trait_maker.hpp>
#include <crtp_interface/unary_plus.hpp>

struct PointImpl {
  int x;
  int y;
  explicit PointImpl(int a = 0, int b = 0) : x{a}, y{b} {}

  friend PointImpl &operator+=(PointImpl &lhs, PointImpl const &rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
  }

  friend std::ostream &operator<<(std::ostream &os, PointImpl const &p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};

struct Point : public PointImpl, protected crtpi::binary_plus<PointImpl> {
  using PointImpl::PointImpl;

  friend std::ostream &operator<<(std::ostream &os, Point const &p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};

struct BigNumImpl {
  long x;
  explicit BigNumImpl(long a) : x{a} {}

  friend BigNumImpl operator+(BigNumImpl const &lhs, BigNumImpl const &rhs) {
    return BigNumImpl{lhs.x + rhs.x};
  }

  friend BigNumImpl &operator+=(BigNumImpl &lhs, BigNumImpl const &rhs) {
    lhs.x += rhs.x;
    return lhs;
  }

  friend std::ostream &operator<<(std::ostream &os, BigNumImpl const &p) {
    return os << p.x << 'L';
  }
};

struct BigNum : public BigNumImpl, protected crtpi::binary_plus<BigNumImpl> {
  using BigNumImpl::BigNumImpl;
};

struct SmallNumImpl {
  int x;
  explicit SmallNumImpl(int a) : x{a} {}

  friend SmallNumImpl operator-(SmallNumImpl const &lhs) {
    SmallNumImpl y{-lhs.x};
    return y;
  }

  friend SmallNumImpl &operator-=(SmallNumImpl &lhs, SmallNumImpl const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }

  friend std::ostream &operator<<(std::ostream &os, SmallNumImpl const &p) {
    return os << p.x << 'L';
  }
};

struct SmallNum : public SmallNumImpl,
                  protected crtpi::binary_plus<SmallNumImpl>,
                  protected crtpi::unary_plus<SmallNumImpl> {
  using SmallNumImpl::SmallNumImpl;
};

int main() {
  LOG_EXPR(crtpi::has_plus_assign_v<void>)
  LOG_EXPR(crtpi::has_plus_assign_v<int>)
  LOG_EXPR(crtpi::has_plus_assign_v<double>)
  LOG_EXPR(crtpi::has_plus_assign_v<Point>)
  LOG_EXPR(crtpi::has_plus_assign_v<BigNum>)
  LOG_EXPR(crtpi::has_plus_assign_v<SmallNum>)
  LOG_EXPR(crtpi::has_minus_assign_v<SmallNum>)
  LOG_EXPR(crtpi::has_unary_minus_v<SmallNum>)

  {
    Point p{1, 2};
    Point q{2, 3};
    std::cout << "p:" << p << '\n';
    std::cout << "q:" << q << '\n';
    std::cout << "p+q: " << (p + q) << '\n';
    std::cout << "p+=q, p=: " << (p += q, p) << '\n';
  }

  {
    BigNum p{100L};
    BigNum q{201L};
    std::cout << "p:" << p << '\n';
    std::cout << "q:" << q << '\n';
    std::cout << "p+q: " << (p + q) << '\n';
    std::cout << "p+=q, p=: " << (p += q, p) << '\n';
  }

  {
    SmallNum p{100L};
    SmallNum q{201L};
    std::cout << "p:" << p << '\n';
    std::cout << "q:" << q << '\n';
    std::cout << "p+q: " << (p + q) << '\n';
    std::cout << "+q: " << (+q) << '\n';
  }
}
