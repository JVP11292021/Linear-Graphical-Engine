#ifndef _LAMBDA_H_
#define _LAMBDA_H_

// This code has been tested to work with GCC, ICC and Clang on GNU/Linux.
// Example: int (*max) (int, int) = lambda (int, (int x, int y) { return x > y ? x : y; });
#if defined(__clang__) || (defined(__GNUC__) || defined(__MINGW32__))
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })
#endif

// This code is VC++ compilers
// Example: auto max = lambda(int, return x > y ? x : y;)  
#if defined(_MSC_VER)
#define lambda(return_type, body) \
  ([&]()->return_type { body; })
#endif

#endif