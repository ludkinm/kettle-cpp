#ifndef __KTL_PLUS_ASSIGN_GUARD__
#define __KTL_PLUS_ASSIGN_GUARD__

#include <kettle++/traits/trait_maker.hpp>

namespace ktl {

template <class, class = void> struct plus_assign {};

template <class T> struct plus_assign<T, enable_if_t<has_plus_assign_v<T>>> {};

template <class T> struct plus_assign<T, enable_if_t<has_binary_plus_v<T>>> {
  friend T &operator+=(T &lhs, T const &rhs) {
    lhs = lhs + rhs;
    return lhs;
  }
};

} // namespace ktl
#endif
