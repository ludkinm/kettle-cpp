#ifndef __KTL_UNARY_PLUS_GUARD__
#define __KTL_UNARY_PLUS_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

/*
 * Implement T &operator+(T const&)
 * If T provides binary operator+ then add nothing
 * Else, implement as returning a copy
 */

template <class T>
enable_if_t<!has_unary_plus_v<T>, T> operator+(T const &lhs) {
  return lhs;
}

} // namespace ktl
#endif
