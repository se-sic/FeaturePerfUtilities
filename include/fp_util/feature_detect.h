/**
 * Author:   Lukas
 * Created:  18/11/2023.
 **/

#ifndef FEATURE_DETECT_H
#define FEATURE_DETECT_H

namespace fp_util {

__attribute__((feature_variable("__VARA__DETECT__"))) void detect() {
  long counter = 0;
  asm volatile("" : "+g"(counter) : :);
  counter++;
}
} // namespace fp_util

#endif // FEATURE_DETECT_H
