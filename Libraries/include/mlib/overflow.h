#ifndef _OVERFLOW_H_
#define _OVERFLOW_H_

/// <summary>
///EXAMPLE:
///   int x = 1000000000;
///   int y = 2000000000;
///   bool result = hasOverflow(x, y)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
template <typename T>
bool hasOverflow(T x, T y) {
  const T max = ~(1 << (sizeof(T)*8-1)); // maximum value for signed T
  const T min = 1 << (sizeof(T)*8-1); // minimum value for signed T
  if ((y > 0 && x > max - y) || (y < 0 && x < min - y)) {
    return true;
  }
  return false;
}


#endif