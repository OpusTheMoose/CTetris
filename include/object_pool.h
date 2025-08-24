#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void* objects;
    size_t size;
    size_t capacity;
    uint8_t *free_flag;
    

} ObjectPool;

void object_ObjectPool(size_t num, size_t size);
void object_DestroyPool();
