#ifndef __KTL_PLUS_ASSIGN_GUARD__
#define __KTL_PLUS_ASSIGN_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

namespace {
template <class T> inline constexpr bool option0 = has_plus_assign_v<T>;

template <class T> inline constexpr bool option1 = has_binary_plus_v<T>;

template <class T>
inline constexpr bool option2 =
    !option1<T> && has_minus_assign_v<T> && has_unary_minus_v<T>;
} // namespace

template <class T>
enable_if_t<option1<T>, T &> operator+=(T &lhs, T const &rhs) {
  lhs = lhs + rhs;
  return lhs;
}

template <class T>
enable_if_t<option2<T>, T &> operator+=(T &lhs, T const &rhs) {
  lhs -= (-rhs);
  return lhs;
}

} // namespace ktl
#endif
