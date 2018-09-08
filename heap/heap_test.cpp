#include "heap.c"
#include "gtest/gtest.h"

TEST(ItemTest, ItemInit)
{
    ItemPayload_t payload = (ItemPayload_t)malloc(sizeof(int));
    *(int *)payload = 5;

    Item_t* item = AllocateItem(4, payload, NULL);

    ASSERT_NE(item, nullptr);
    ASSERT_EQ(item->key, 4);
    ASSERT_EQ(*(int *)item->payload, 5);
}

TEST(HeapTest, HeapInit)
{
    Heap_t* heap = AllocateHeap(12);

    ASSERT_NE(heap, nullptr);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
