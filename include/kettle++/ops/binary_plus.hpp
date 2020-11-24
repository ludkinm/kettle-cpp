#ifndef __KTL_BINARY_PLUS_GUARD__
#define __KTL_BINARY_PLUS_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

/*
 * Implement binary+ using Options:
 * (1) If T has binary+ use it
 * (2) If T has += and copy constructor
 * (3) If T has -= and unary-
 */

template <class, class = void> struct binary_plus {};

template <class T> struct binary_plus<T, enable_if_t<has_binary_plus_v<T>>> {};

template <class T>
struct binary_plus<T,
                   enable_if_t<!has_binary_plus_v<T> && has_plus_assign_v<T>>> {
  friend T operator+(T const &lhs, T const &rhs) {
    T tmp{lhs};
    tmp += rhs;
    return tmp;
  }
};

template <class T>
struct binary_plus<T,
                   enable_if_t<!has_binary_plus_v<T> && !has_plus_assign_v<T> &&
                               has_minus_assign_v<T> && has_unary_minus_v<T>>> {
  friend T operator+(T const &lhs, T const &rhs) {
    T tmp{lhs};
    tmp -= -rhs;
    return tmp;
  }
};

} // namespace ktl
#endif
