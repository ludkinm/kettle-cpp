#ifndef __KTL_UNARY_PLUS_GUARD__
#define __KTL_UNARY_PLUS_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

template <class, class = void> struct unary_plus {};

/*
 * Implement T &operator+(T const&)
 * If T provides binary operator+ then add nothing
 * Else just do the copy
 */

template <class T> struct unary_plus<T, enable_if_t<!has_unary_plus_v<T>>> {
  friend T operator+(T const &lhs) { return lhs; }
};

} // namespace ktl
#endif