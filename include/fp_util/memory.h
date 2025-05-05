#ifndef MEMORY_H
#define MEMORY_H
/*
 * General utility functions for synthetic memory usage.
 * Provides utility functions for memory manipulations
 * such that it should not be optimized by compilers.
 */
namespace fp_util {
/// Fake a use of a generic memory location. Prevents the compiler from removing
/// this memory during optimization
/// @param mem Pointer to memory to be used
inline void use_memory(void *mem) {
  asm volatile("" : "+r,m"(mem) : : "memory");
}

/// Allocates a memory block with malloc that should not be optimized by the
/// compiler
/// @param Size Size of memory to be allocated in Bytes
/// @return A pointer to the allocated memory
inline void *get_memory(size_t Size) {
  void *mem = malloc(Size);

  use_memory(mem);

  return mem;
}

/// Frees memory allocated with malloc. "Uses" the memory before freeing so it
/// cannot be optimized.
/// @param mem Pointer to the memory to be freed
inline void free_memory(void *mem) {
  use_memory(mem);

  free(mem);
}
} // namespace fp_util

#endif // MEMORY_H
