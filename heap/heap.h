/**
 * Declarations for a set of heap and item data structures.
 */

#ifndef _JASCHILZ_HEAP_H_
#define _JASCHILZ_HEAP_H_


/**
 * Each item shall bear a pointer to a payload.
 */
typedef void* ItemPayload_t;

/**
 * Items shall be of type struct.
 */
typedef struct Item_t Item_t;

/**
 * Heaps shall be of type struct.
 */
typedef struct Heap_t Heap_t;

/**
 * Abstract definition for a function which takes a payload
 * and frees it.
 */
typedef void(*ItemPayloadFreeFnPtr)(ItemPayload_t payload);

/**
 * Allocates an item with the given key and payload.
 *
 * In case of failure, the indicated Item_t shall be set to null.
 * 
 * @param int key               The sort key for heap positioning
 * @param ItemPayload_t payload The payload for this item
 * @param ItemPayloadFreeFnPtr payload_free_function
 *                              The function for freeing this payload
 * @return Item_t*|NULL
 */
Item_t* AllocateItem(int key,
                     ItemPayload_t payload,
                     ItemPayloadFreeFnPtr payload_free_function);

/**
 * Frees an item and its payload.
 *
 * @param Item_t* item The item to free
 * @return int 0 on success
 */
int FreeItem(Item_t* item);

/**
 * Alocate a heap.
 * 
 * In case of failure, the indicated heap shall be set to null.
 *
 * @param size_t size
 * @return Heap_t*|NULL
 */
Heap_t* AllocateHeap(size_t size);

/**
 * Frees a heap, all items contained in the heap, and all payloads
 * in items.
 *
 * @param Heap_t* heap The heap to free.
 * @return int 0 on success.
 */
int Freeheap(Heap_t* heap);

/**
 * Pushes an item onto the heap.
 *
 * @param Heap_t* heap The heap to push to.
 * @param Item_t* item The item to push.
 * @return int 0 on success
 */
int PushHeap(Heap_t* heap, Item_t* item);

/** 
 * Pops the top item from the heap.
 *
 * Returns NULL if the heap is empty.
 *
 * @param Heap_t* heap The heap to pop.
 * @return Item_t*|NULL
 */
Item_t* PopHeap(Heap_t* heap);

/** 
 * Peeks an item from the heap.
 *
 * Returns NULL if the heap is empty.
 *
 * @param Heap_t* heap The heap to pop.
 * @return Item_t*|NULL
 */
Item_t* PeekHeap(Heap_t* heap);


#endif // _JASCHILZ_HEAP_H
