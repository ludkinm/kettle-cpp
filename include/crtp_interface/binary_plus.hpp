#ifndef __CRTPI_BINARY_PLUS_GUARD__
#define __CRTPI_BINARY_PLUS_GUARD__

#include <crtp_interface/traits/trait_maker.hpp>
#include <type_traits>

namespace crtpi {

template <class, class = void> struct binary_plus {};

/*
 * Implement T &operator+(T const&, T const&)
 * If T provides binary operator+ then add nothing
 * If T provides operator+= then can implement using that
 * If T provides operator-= and unary operator- then implement using those
 */

template <class T>
using enable_if_has_plus_assign_but_no_binary_plus =
    std::enable_if_t<(!has_binary_plus_v<T> && has_plus_assign_v<T>)>;

template <class T>
struct binary_plus<T, std::enable_if_t<has_binary_plus_v<T>>> {};

template <class T>
struct binary_plus<T, enable_if_has_plus_assign_but_no_binary_plus<T>> {
  friend T operator+(T const &lhs, T const &rhs) {
    T tmp{lhs};
    tmp += rhs;
    return tmp;
  }
};

template <class T>
struct binary_plus<
    T, std::enable_if_t<!has_binary_plus_v<T> && !has_plus_assign_v<T> &&
                        has_minus_assign_v<T> && has_unary_minus_v<T>>> {
  friend T operator+(T const &lhs, T const &rhs) {
    T tmp{lhs};
    tmp -= -rhs;
    return tmp;
  }
};

} // namespace crtpi
#endif
