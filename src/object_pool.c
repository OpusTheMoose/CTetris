
#include "../include/object_pool.h"

static ObjectPool obj_pool;
// Allocates the space with the specified numbner of objects and the sizeof each object.
void object_ObjectPool(size_t num, size_t size)
{
    obj_pool.size = size;
    obj_pool.objects = (void*)calloc(num, size);
    if (obj_pool.objects == NULL)
    {
        printf("Failed to allocate memory with size: %lu", size * num);
        exit(0);
    }
}
void object_DestroyPool()
{
    free(obj_pool.objects);
    obj_pool.size = 0;
}