#include "stdio.h"
#include "stdlib.h"
#include "heap.h"


struct Item_t {
    int key;
    void* value;
};
typedef struct Item_t Item_t;


struct Heap_t {
    size_t size;
    Item_t** storage;
    size_t next_free;
};
typedef struct Heap_t Heap_t;

void payload_free_function(ItemPayload_t payload)
{
    // Stub method.
}

Item_t* AllocateItem(int key,
                     ItemPayload_t payload,
                     ItemPayloadFreeFnPtr payload_free_function)
{
    return NULL;
}

int FreeItem(Item_t* item)
{
    return 0;
}

Heap_t* AllocateHeap(size_t size)
{
    return NULL;
}

int Freeheap(Heap_t* heap)
{
    return 0;
}

int PushHeap(Heap_t* heap, Item_t* item)
{
    return 0;
}

Item_t* PopHeap(Heap_t* heap)
{
    return NULL;
}

Item_t* PeekHeap(Heap_t* heap)
{
    return NULL;
}

