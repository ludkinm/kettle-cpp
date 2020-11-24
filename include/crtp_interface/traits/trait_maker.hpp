#ifndef __CRTPI_TRAIT_MAKER_GUARD__
#define __CRTPI_TRAIT_MAKER_GUARD__

#include <type_traits>

namespace crtpi {
#define MAKE_TRAIT(name, expr)                                                 \
  template <class, class = void> struct name : public std::false_type {};      \
                                                                               \
  template <class T>                                                           \
  struct name<T, std::void_t<decltype(expr)>> : public std::true_type {};      \
                                                                               \
  template <class T> static constexpr bool name##_v = name<T>::value;

MAKE_TRAIT(has_less_than, std::declval<T>() < std::declval<T>())

MAKE_TRAIT(has_equals, std::declval<T>() == std::declval<T>())

MAKE_TRAIT(has_plus_assign, std::declval<T &>() += std::declval<T &>())

MAKE_TRAIT(has_unary_plus, +std::declval<T &>())

MAKE_TRAIT(has_binary_plus, std::declval<T>() + std::declval<T>())

MAKE_TRAIT(has_minus_assign, std::declval<T &>() -= std::declval<T>())

MAKE_TRAIT(has_unary_minus, -std::declval<T &>())

MAKE_TRAIT(has_binary_minus, std::declval<T>() - std::declval<T>())

using std::is_copy_constructible_v;

} // namespace crtpi
#endif
