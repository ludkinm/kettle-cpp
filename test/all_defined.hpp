#ifndef __KTL_TEST_ALL_DEFINED__
#define __KTL_TEST_ALL_DEFINED__

// A class which has all operators on an int defined
struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl &operator+=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x += rhs.x;
    return lhs;
  }

  friend IntImpl &operator-=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }

  friend IntImpl &operator*=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x *= rhs.x;
    return lhs;
  }

  friend IntImpl &operator/=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x /= rhs.x;
    return lhs;
  }

  friend IntImpl &operator%=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x %= rhs.x;
    return lhs;
  }

  friend IntImpl &operator&=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x &= rhs.x;
    return lhs;
  }

  friend IntImpl &operator|=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x |= rhs.x;
    return lhs;
  }

  friend IntImpl &operator^=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x ^= rhs.x;
    return lhs;
  }

  friend IntImpl &operator<<=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x <<= rhs.x;
    return lhs;
  }

  friend IntImpl &operator>>=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x >>= rhs.x;
    return lhs;
  }

  friend IntImpl &operator++(IntImpl &rhs) {
    ++rhs.x;
    return rhs;
  }

  friend IntImpl &operator--(IntImpl &rhs) {
    --rhs.x;
    return rhs;
  }

  friend IntImpl operator++(IntImpl &rhs, int) {
    rhs.x++;
    return rhs;
  }

  friend IntImpl operator--(IntImpl &rhs, int) {
    rhs.x--;
    return rhs;
  }

  friend IntImpl operator+(IntImpl const &rhs) { return IntImpl{+rhs.x}; }

  friend IntImpl operator-(IntImpl const &rhs) { return IntImpl{-rhs.x}; }

  friend IntImpl operator~(IntImpl const &rhs) { return IntImpl{~rhs.x}; }

  friend IntImpl operator+(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x + rhs.x};
  }

  friend IntImpl operator-(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x - rhs.x};
  }

  friend IntImpl operator*(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x * rhs.x};
  }

  friend IntImpl operator/(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x / rhs.x};
  }

  friend IntImpl operator%(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x % rhs.x};
  }

  friend IntImpl operator&(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x & rhs.x};
  }

  friend IntImpl operator|(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x | rhs.x};
  }

  friend IntImpl operator^(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x ^ rhs.x};
  }

  friend IntImpl operator<<(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x << rhs.x};
  }

  friend IntImpl operator>>(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x >> rhs.x};
  }

  friend bool operator!(IntImpl const &rhs) { return !rhs.x; }

  friend bool operator&&(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x && rhs.x;
  }

  friend bool operator||(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x || rhs.x;
  }

  friend bool operator==(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x == rhs.x;
  }

  friend bool operator!=(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x != rhs.x;
  }

  friend bool operator<(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x < rhs.x;
  }

  friend bool operator<=(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x <= rhs.x;
  }

  friend bool operator>(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x > rhs.x;
  }

  friend bool operator>=(IntImpl const &lhs, IntImpl const &rhs) {
    return lhs.x >= rhs.x;
  }
};

#endif
