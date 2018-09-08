#include "heap.c"
#include "gtest/gtest.h"

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
