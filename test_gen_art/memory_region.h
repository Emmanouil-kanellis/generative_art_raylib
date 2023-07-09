#ifndef MEMORY_REGION
#define MEMORY_REGION

#include <stdlib.h>
#include <stdint.h>

#define CAPACITY 10240

typedef struct {
    size_t capacity;
    size_t size;
    uint8_t *data;
} Region;

Region* MemoryRegion(void);
void* MemoryAllocate(size_t size);
void PrintMemoryRegion(void);

#endif