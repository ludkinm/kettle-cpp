#ifndef __KTL_LOG_EXPR_GUARD__
#define __KTL_LOG_EXPR_GUARD__

#include <iostream>

namespace ktl::util {

#define LOG_EXPR(expr)                                                         \
  std::cout << std::boolalpha << (#expr) << '=' << (expr) << '\n';

} // namespace ktl::util
#endif
