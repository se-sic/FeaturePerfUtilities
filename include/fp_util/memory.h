#ifndef MEMORY_H
#define MEMORY_H
namespace fp_util {
inline void use_memory(void* mem){
  asm volatile("" : "+g"(mem) : :);
}

inline void *get_memory(size_t Size){
  void* mem = malloc(Size);

  use_memory(mem);

  return mem;
}

inline void free_memory(void* mem){
  use_memory(mem);

  free(mem);
}
}

#endif //MEMORY_H
