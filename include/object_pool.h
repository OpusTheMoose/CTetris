#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    uint64_t size;
    void* objects;

} ObjectPool;

void object_ObjectPool(size_t num, size_t size);
void object_DestroyPool();
