#ifndef __KTL_TEST_ALL_DEFINED__
#define __KTL_TEST_ALL_DEFINED__

// A class which has all operators on an int defined
struct Int {
  int x;
  explicit Int(int a) : x{a} {}

  friend Int &operator+=(Int &lhs, Int const &rhs) {
    lhs.x += rhs.x;
    return lhs;
  }

  friend Int &operator-=(Int &lhs, Int const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }

  friend Int &operator*=(Int &lhs, Int const &rhs) {
    lhs.x *= rhs.x;
    return lhs;
  }

  friend Int &operator/=(Int &lhs, Int const &rhs) {
    lhs.x /= rhs.x;
    return lhs;
  }

  friend Int &operator%=(Int &lhs, Int const &rhs) {
    lhs.x %= rhs.x;
    return lhs;
  }

  friend Int &operator&=(Int &lhs, Int const &rhs) {
    lhs.x &= rhs.x;
    return lhs;
  }

  friend Int &operator|=(Int &lhs, Int const &rhs) {
    lhs.x |= rhs.x;
    return lhs;
  }

  friend Int &operator^=(Int &lhs, Int const &rhs) {
    lhs.x ^= rhs.x;
    return lhs;
  }

  friend Int &operator<<=(Int &lhs, Int const &rhs) {
    lhs.x <<= rhs.x;
    return lhs;
  }

  friend Int &operator>>=(Int &lhs, Int const &rhs) {
    lhs.x >>= rhs.x;
    return lhs;
  }

  friend Int &operator++(Int &rhs) {
    ++rhs.x;
    return rhs;
  }

  friend Int &operator--(Int &rhs) {
    --rhs.x;
    return rhs;
  }

  friend Int operator++(Int &rhs, int) {
    rhs.x++;
    return rhs;
  }

  friend Int operator--(Int &rhs, int) {
    rhs.x--;
    return rhs;
  }

  friend Int operator+(Int const &rhs) { return Int{+rhs.x}; }

  friend Int operator-(Int const &rhs) { return Int{-rhs.x}; }

  friend Int operator~(Int const &rhs) { return Int{~rhs.x}; }

  friend Int operator+(Int const &lhs, Int const &rhs) {
    return Int{lhs.x + rhs.x};
  }

  friend Int operator-(Int const &lhs, Int const &rhs) {
    return Int{lhs.x - rhs.x};
  }

  friend Int operator*(Int const &lhs, Int const &rhs) {
    return Int{lhs.x * rhs.x};
  }

  friend Int operator/(Int const &lhs, Int const &rhs) {
    return Int{lhs.x / rhs.x};
  }

  friend Int operator%(Int const &lhs, Int const &rhs) {
    return Int{lhs.x % rhs.x};
  }

  friend Int operator&(Int const &lhs, Int const &rhs) {
    return Int{lhs.x & rhs.x};
  }

  friend Int operator|(Int const &lhs, Int const &rhs) {
    return Int{lhs.x | rhs.x};
  }

  friend Int operator^(Int const &lhs, Int const &rhs) {
    return Int{lhs.x ^ rhs.x};
  }

  friend Int operator<<(Int const &lhs, Int const &rhs) {
    return Int{lhs.x << rhs.x};
  }

  friend Int operator>>(Int const &lhs, Int const &rhs) {
    return Int{lhs.x >> rhs.x};
  }

  friend bool operator!(Int const &rhs) { return !rhs.x; }

  friend bool operator&&(Int const &lhs, Int const &rhs) {
    return lhs.x && rhs.x;
  }

  friend bool operator||(Int const &lhs, Int const &rhs) {
    return lhs.x || rhs.x;
  }

  friend bool operator==(Int const &lhs, Int const &rhs) {
    return lhs.x == rhs.x;
  }

  friend bool operator!=(Int const &lhs, Int const &rhs) {
    return lhs.x != rhs.x;
  }

  friend bool operator<(Int const &lhs, Int const &rhs) {
    return lhs.x < rhs.x;
  }

  friend bool operator<=(Int const &lhs, Int const &rhs) {
    return lhs.x <= rhs.x;
  }

  friend bool operator>(Int const &lhs, Int const &rhs) {
    return lhs.x > rhs.x;
  }

  friend bool operator>=(Int const &lhs, Int const &rhs) {
    return lhs.x >= rhs.x;
  }
};

#endif
