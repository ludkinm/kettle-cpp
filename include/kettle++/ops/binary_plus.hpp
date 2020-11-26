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
namespace {
template <class T> inline constexpr bool option0 = has_binary_plus_v<T>;

template <class T> inline constexpr bool option1 = has_plus_assign_v<T>;

template <class T>
inline constexpr bool option2 =
    !option1<T> && has_minus_assign_v<T> && has_unary_minus_v<T>;
} // namespace

template <class T>
enable_if_t<option1<T>, T> operator+(T const &lhs, T const &rhs) {
  T tmp{lhs};
  tmp += rhs;
  return tmp;
}

template <class T>
enable_if_t<option2<T>, T> operator+(T const &lhs, T const &rhs) {
  T tmp{lhs};
  tmp -= -rhs;
  return tmp;
}

} // namespace ktl
#endif
