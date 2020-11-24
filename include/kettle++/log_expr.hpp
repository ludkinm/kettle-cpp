#ifndef __CRTPI_LOG_EXPR_GUARD__
#define __CRTPI_LOG_EXPR_GUARD__

#include <iostream>

namespace crtpi::util {

#define LOG_EXPR(expr)                                                         \
  std::cout << std::boolalpha << (#expr) << '=' << (expr) << '\n';

} // namespace crtpi::util
#endif
