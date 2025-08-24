
#include "../include/object_pool.h"

static ObjectPool obj_pool;
// Allocates the space with the specified numbner of objects and the sizeof each object.
void object_ObjectPool(size_t num, size_t size)
{
    obj_pool.objects = (void*)calloc(num, size);
    if (obj_pool.objects == NULL)
    {
        printf("Failed to allocate memory with size: %lu", size * num);
        exit(0);
    }
    obj_pool.size = size;
    obj_pool.capacity = num;
    obj_pool.free_flag = (uint8_t*)malloc(num);
    if (obj_pool.free_flag == NULL)
    {
        free(obj_pool.objects);
        printf("Failed to allocate free flags.");
        exit(0);
    }
     for (size_t i = 0; i < num; i++) {
        obj_pool.free_flag[i] = 1;
    }

   
}
// Returns a pointer to an unused object in the pool.
void *object_Allocate() {
    for (size_t i = 0; i < obj_pool.capacity; i++) {
        if (obj_pool.free_flag[i]) {
            obj_pool.free_flag[i] = 0; // mark as used
            return (uint8_t*)obj_pool.objects + (i * obj_pool.size);
        }
    }
    return NULL; // pool is exhausted
}
// Frees an object given the provided pointer.
void object_Free(void *ptr) {
    if (!ptr) return;

    size_t offset = (char*)ptr - (char*)obj_pool.objects;
    if (offset % obj_pool.size != 0) {
        printf("Error: pointer not aligned to pool objects.\n");
        return;
    }

    size_t index = offset / obj_pool.size;
    if (index >= obj_pool.capacity) {
        printf("Error: pointer out of pool range.\n");
        return;
    }

    obj_pool.free_flag[index] = 1; // mark slot as free again
}

void object_DestroyPool()
{
    free(obj_pool.objects);
    free(obj_pool.free_flag);
    obj_pool.objects = NULL;
    obj_pool.free_flag = NULL;
    obj_pool.size = 0;
    obj_pool.capacity = 0;
    printf("Destroyed object pool \n");
}