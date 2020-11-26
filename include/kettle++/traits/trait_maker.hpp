#ifndef __KTL_TRAIT_MAKER_GUARD__
#define __KTL_TRAIT_MAKER_GUARD__

#include <type_traits>

namespace ktl {
// Bring standard types into scope
using std::enable_if_t;
using std::is_copy_assignable_v;
using std::is_copy_constructible_v;

#define MAKE_TRAIT(name, expr)                                                 \
  template <class, class = void> struct name : public std::false_type {};      \
                                                                               \
  template <class T>                                                           \
  struct name<T, std::void_t<decltype(expr)>> : public std::true_type {};      \
                                                                               \
  template <class T> inline constexpr bool name##_v = name<T>::value;

// Assignment
MAKE_TRAIT(has_assign, std::declval<T &>() += std::declval<T &>())
MAKE_TRAIT(has_plus_assign, std::declval<T &>() += std::declval<T &>())
MAKE_TRAIT(has_minus_assign, std::declval<T &>() -= std::declval<T>())
MAKE_TRAIT(has_mult_assign, std::declval<T &>() *= std::declval<T &>())
MAKE_TRAIT(has_div_assign, std::declval<T &>() /= std::declval<T &>())
MAKE_TRAIT(has_mod_assign, std::declval<T &>() %= std::declval<T &>())
MAKE_TRAIT(has_and_assign, std::declval<T &>() &= std::declval<T &>())
MAKE_TRAIT(has_or_assign, std::declval<T &>() |= std::declval<T &>())
MAKE_TRAIT(has_xor_assign, std::declval<T &>() ^= std::declval<T &>())
MAKE_TRAIT(has_bit_left_assign, std::declval<T &>() <<= std::declval<T &>())
MAKE_TRAIT(has_bit_right_assign, std::declval<T &>() >>= std::declval<T &>())

// In/De-crement
MAKE_TRAIT(has_pre_inc, ++std::declval<T &>())
MAKE_TRAIT(has_pre_dec, --std::declval<T &>())
MAKE_TRAIT(has_post_inc, std::declval<T &>()++)
MAKE_TRAIT(has_post_dec, std::declval<T &>()--)

// Unary Arithmetic
MAKE_TRAIT(has_unary_plus, +std::declval<T &>())
MAKE_TRAIT(has_unary_minus, -std::declval<T &>())
MAKE_TRAIT(has_unary_bit_not, ~std::declval<T &>())

// Binary Arithmetic
MAKE_TRAIT(has_binary_plus, std::declval<T>() + std::declval<T>())
MAKE_TRAIT(has_binary_minus, std::declval<T>() - std::declval<T>())
MAKE_TRAIT(has_binary_mult, std::declval<T>() * std::declval<T>())
MAKE_TRAIT(has_binary_div, std::declval<T>() / std::declval<T>())
MAKE_TRAIT(has_binary_mod, std::declval<T>() % std::declval<T>())
MAKE_TRAIT(has_binary_bit_and, std::declval<T>() & std::declval<T>())
MAKE_TRAIT(has_binary_bit_or, std::declval<T>() | std::declval<T>())
MAKE_TRAIT(has_binary_bit_xor, std::declval<T>() ^ std::declval<T>())
MAKE_TRAIT(has_binary_bit_left, std::declval<T>() << std::declval<T>())
MAKE_TRAIT(has_binary_bit_right, std::declval<T>() >> std::declval<T>())

// Logical
MAKE_TRAIT(has_unary_logical_not, !std::declval<T>())
MAKE_TRAIT(has_unary_logical_and, std::declval<T>() && std::declval<T>())
MAKE_TRAIT(has_unary_logical_or, std::declval<T>() || std::declval<T>())

// Comparsion
MAKE_TRAIT(has_equals, std::declval<T>() == std::declval<T>())
MAKE_TRAIT(has_not_equals, std::declval<T>() != std::declval<T>())
MAKE_TRAIT(has_less_than, std::declval<T>() < std::declval<T>())
MAKE_TRAIT(has_less_than_equals, std::declval<T>() <= std::declval<T>())
MAKE_TRAIT(has_more_than, std::declval<T>() > std::declval<T>())
MAKE_TRAIT(has_more_than_equals, std::declval<T>() >= std::declval<T>())

} // namespace ktl
#endif
