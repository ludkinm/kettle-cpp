#ifndef __CRTPI_TRAIT_MAKER_GUARD__
#define __CRTPI_TRAIT_MAKER_GUARD__

#include <type_traits>

namespace crtpi {

#define MAKE_TRAIT(name, expr)                                                 \
  template <class, class = void> struct name : std::false_type {};             \
  template <class T>                                                           \
  struct name<T, std::void_t<decltype(expr)>> : std::true_type {};             \
  template <typename T> static constexpr bool name##_v = name<T>::value;

MAKE_TRAIT(has_op_less_than, std::declval<T>() < std::declval<T>())
MAKE_TRAIT(has_op_equals, std::declval<T>() == std::declval<T>())

MAKE_TRAIT(has_op_plus_assign, std::declval<T &>() += std::declval<T>())
MAKE_TRAIT(has_op_unary_plus, +std::declval<T>())
MAKE_TRAIT(has_op_binary_plus, std::declval<T>() + std::declval<T>())

} // namespace crtpi
#endif
