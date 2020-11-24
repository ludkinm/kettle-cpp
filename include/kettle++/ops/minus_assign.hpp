#ifndef __KTL_MINUS_ASSIGN_GUARD__
#define __KTL_MINUS_ASSIGN_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

namespace minus_assign_details {
template <class T> constexpr static bool option1 = has_minus_assign_v<T>;

template <class T>
constexpr static bool option2 =
    !option1<T> && has_plus_assign_v<T> && has_unary_minus_v<T>;

template <class T>
constexpr static bool option3 =
    !option1<T> && !option2<T> && has_binary_minus_v<T>;

template <class T>
constexpr static bool option4 = !option1<T> && !option2<T> && !option3<T> &&
                                has_binary_plus_v<T> && has_unary_minus_v<T>;
} // namespace minus_assign_details

template <class, class = void> struct minus_assign {};

// Option (1) if -= exists, do nothing
template <class T>
struct minus_assign<T, enable_if_t<minus_assign_details::option1<T>>> {};

// Option (2) if no -=, but += and unary-
template <class T>
struct minus_assign<T, enable_if_t<minus_assign_details::option2<T>>> {
  friend T &operator-=(T &lhs, T const &rhs) {
    lhs += (-rhs);
    return lhs;
  }
};

// Option (3) if not all -=, += and unary-, but binary-
template <class T>
struct minus_assign<T, enable_if_t<minus_assign_details::option3<T>>> {
  friend T &operator-=(T &lhs, T const &rhs) {
    lhs = lhs - rhs;
    return lhs;
  }
};

// Option (4) if not all -=, +=, binary-, but binary+ and unary-
template <class T>
struct minus_assign<T, enable_if_t<minus_assign_details::option4<T>>> {
  friend T &operator-=(T &lhs, T const &rhs) {
    lhs = lhs + (-rhs);
    return lhs;
  }
};

} // namespace ktl
#endif
