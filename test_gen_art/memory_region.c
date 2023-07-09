#include "memory_region.h"

#include <stdio.h>
#include <string.h>

static uint8_t internalMemory[CAPACITY];
static Region staticRegion;

Region* MemoryRegion(void)
{
    memset(internalMemory, 0xff, CAPACITY);
    staticRegion.capacity = CAPACITY;
    staticRegion.size = 0;
    staticRegion.data = internalMemory;
    return &staticRegion;
}

void * MemoryAllocate(size_t sizeBytes){


    void *result = &staticRegion.data[staticRegion.size];
    staticRegion.size += sizeBytes;
    return result;
}

void PrintMemoryRegion(void) {
    printf("Memory Region\n");
    for(int i =0; i <= CAPACITY; i++){
        printf("%02x", staticRegion.data[i]);
    }
    printf("\n");
}