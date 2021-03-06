#ifndef __KTL_MINUS_ASSIGN_GUARD__
#define __KTL_MINUS_ASSIGN_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

namespace {
template <class T> constexpr static bool option0 = has_minus_assign_v<T>;

template <class T>
constexpr static bool option1 = has_plus_assign_v<T> &&has_unary_minus_v<T>;

template <class T>
constexpr static bool option2 = !option1<T> && has_binary_minus_v<T>;

template <class T>
constexpr static bool option3 =
    !option2<T> && has_binary_plus_v<T> && has_unary_minus_v<T>;
} // namespace

// Option (2) if no -=, but += and unary-
template <class T>
enable_if_t<option1<T>, T &> &operator-=(T &lhs, T const &rhs) {
  lhs += (-rhs);
  return lhs;
}

// Option (3) if not all -=, += and unary-, but binary-
template <class T>
enable_if_t<option2<T>, T &> operator-=(T &lhs, T const &rhs) {
  lhs = lhs - rhs;
  return lhs;
}

// Option (4) if not all -=, +=, binary-, but binary+ and unary-
template <class T>
enable_if_t<option3<T>, T &> operator-=(T &lhs, T const &rhs) {
  lhs = lhs + (-rhs);
  return lhs;
}

} // namespace ktl
#endif
