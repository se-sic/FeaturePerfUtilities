#ifndef FP_UTIL_FEATURECMD_H
#define FP_UTIL_FEATURECMD_H

#include <exception>
#include <stdlib.h>
#include <string>

namespace fp_util {
inline bool isFeatureEnabled(int argc, char *argv[], std::string FeatureName) {
  for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
    if (argv[CurrentArg] == FeatureName) {
      return true;
    }
  }

  return false;
}

inline long getFeatureValue(int argc, char *argv[], std::string FeatureName) {
  int CurrentArg = 1;
  for (; CurrentArg < argc; ++CurrentArg) {
    if (argv[CurrentArg] == FeatureName) {
      ++CurrentArg;
      break;
    }
  }

  if (CurrentArg >= argc) {
    return 0;
  }

  return strtol(argv[CurrentArg], NULL, 0);
}

} // namespace fp_util

#endif // FP_UTIL_FEATURECMD_H
