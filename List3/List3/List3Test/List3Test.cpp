// List3Test.cpp
// Google Test unit tests for the linked list module (List.h)

#include <gtest/gtest.h>

#include "List.h"

// ============================================================
// Helper: create list of size n (values 1..n)
// ============================================================
LNode* CreateListOfSize(int n)
{
    LNode* L = ListInit();
    for (int i = 1; i <= n; i++)
    {
        ListInsert(L, i - 1, i);
    }
    return L;
}

// ============================================================
// Test suite: BuyListNode
// ============================================================

TEST(ListNodeTest, BuyListNode_CreatesNode)
{
    LNode* node = BuyListNode(42);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->data, 42);
    EXPECT_EQ(node->next, nullptr);
    free(node);
}

// ============================================================
// Test suite: ListInit / ListEmpty
// ============================================================

TEST(ListInitTest, ListInit_CreatesHead)
{
    LNode* L = ListInit();
    ASSERT_NE(L, nullptr);
    EXPECT_EQ(L->next, nullptr);
    ListDestroy(L);
}

TEST(ListEmptyTest, ListEmpty_Check)
{
    LNode* L = ListInit();
    EXPECT_TRUE(ListEmpty(L));
    ListPushFront(L, 10);
    EXPECT_FALSE(ListEmpty(L));
    ListDestroy(L);
}

// ============================================================
// Test suite: ListSize
// ============================================================

TEST(ListSizeTest, ListSize_Empty)
{
    LNode* L = ListInit();
    EXPECT_EQ(ListSize(L), 0);
    ListDestroy(L);
}

TEST(ListSizeTest, ListSize_MultipleElements)
{
    LNode* L = CreateListOfSize(5);
    EXPECT_EQ(ListSize(L), 5);
    ListDestroy(L);
}

TEST(ListSizeTest, ListSize_AfterDeletion)
{
    LNode* L = CreateListOfSize(5);
    ListPopFront(L);
    EXPECT_EQ(ListSize(L), 4);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListLocateElem
// ============================================================

TEST(ListLocateElemTest, LocateElem_FindsExisting)
{
    LNode* L = CreateListOfSize(5);
    LNode* found = ListLocateElem(L, 3);
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->data, 3);
    ListDestroy(L);
}

TEST(ListLocateElemTest, LocateElem_NotFound)
{
    LNode* L = CreateListOfSize(5);
    LNode* found = ListLocateElem(L, 99);
    EXPECT_EQ(found, nullptr);
    ListDestroy(L);
}

TEST(ListLocateElemTest, LocateElem_EmptyList)
{
    LNode* L = ListInit();
    LNode* found = ListLocateElem(L, 1);
    EXPECT_EQ(found, nullptr);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListGetElem
// ============================================================

TEST(ListGetElemTest, GetElem_ValidIndices)
{
    LNode* L = CreateListOfSize(5);
    EXPECT_EQ(ListGetElem(L, 0)->data, 1);
    EXPECT_EQ(ListGetElem(L, 2)->data, 3);
    EXPECT_EQ(ListGetElem(L, 4)->data, 5);
    ListDestroy(L);
}

TEST(ListGetElemTest, GetElem_OutOfRange)
{
    LNode* L = CreateListOfSize(3);
    EXPECT_EQ(ListGetElem(L, 5), nullptr);
    ListDestroy(L);
}

TEST(ListGetElemTest, GetElem_EmptyList)
{
    LNode* L = ListInit();
    EXPECT_EQ(ListGetElem(L, 0), nullptr);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListInsert
// ============================================================

TEST(ListInsertTest, InsertAtHead)
{
    LNode* L = ListInit();
    ListInsert(L, 0, 100);
    EXPECT_EQ(ListSize(L), 1);
    EXPECT_EQ(ListGetElem(L, 0)->data, 100);
    ListDestroy(L);
}

TEST(ListInsertTest, InsertAtMiddle)
{
    LNode* L = CreateListOfSize(3);
    ListInsert(L, 1, 100);
    EXPECT_EQ(ListSize(L), 4);
    EXPECT_EQ(ListGetElem(L, 1)->data, 100);
    EXPECT_EQ(ListGetElem(L, 2)->data, 2);
    ListDestroy(L);
}

TEST(ListInsertTest, InsertAtTail)
{
    LNode* L = CreateListOfSize(3);
    ListInsert(L, 3, 100);
    EXPECT_EQ(ListSize(L), 4);
    EXPECT_EQ(ListGetElem(L, 3)->data, 100);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListDelete
// ============================================================

TEST(ListDeleteTest, DeleteAtHead)
{
    LNode* L = CreateListOfSize(3);
    LDataType val = ListDelete(L, 0);
    EXPECT_EQ(val, 1);
    EXPECT_EQ(ListSize(L), 2);
    EXPECT_EQ(ListGetElem(L, 0)->data, 2);
    ListDestroy(L);
}

TEST(ListDeleteTest, DeleteAtMiddle)
{
    LNode* L = CreateListOfSize(5);
    LDataType val = ListDelete(L, 2);
    EXPECT_EQ(val, 3);
    EXPECT_EQ(ListSize(L), 4);
    EXPECT_EQ(ListGetElem(L, 2)->data, 4);
    ListDestroy(L);
}

TEST(ListDeleteTest, DeleteAtTail)
{
    LNode* L = CreateListOfSize(3);
    LDataType val = ListDelete(L, 2);
    EXPECT_EQ(val, 3);
    EXPECT_EQ(ListSize(L), 2);
    EXPECT_EQ(ListGetElem(L, 1)->data, 2);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListPushFront (head insert)
// ============================================================

TEST(ListPushFrontTest, PushFrontOnEmpty)
{
    LNode* L = ListInit();
    ListPushFront(L, 10);
    EXPECT_EQ(ListSize(L), 1);
    EXPECT_EQ(ListGetElem(L, 0)->data, 10);
    ListDestroy(L);
}

TEST(ListPushFrontTest, PushFrontOnNonEmpty)
{
    LNode* L = CreateListOfSize(3);
    ListPushFront(L, 0);
    EXPECT_EQ(ListSize(L), 4);
    EXPECT_EQ(ListGetElem(L, 0)->data, 0);
    EXPECT_EQ(ListGetElem(L, 1)->data, 1);
    ListDestroy(L);
}

TEST(ListPushFrontTest, PushFront_ReversedOrder)
{
    LNode* L = ListInit();
    ListPushFront(L, 3);
    ListPushFront(L, 2);
    ListPushFront(L, 1);
    EXPECT_EQ(ListSize(L), 3);
    EXPECT_EQ(ListGetElem(L, 0)->data, 1);
    EXPECT_EQ(ListGetElem(L, 2)->data, 3);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListPushBack (tail insert)
// ============================================================

TEST(ListPushBackTest, PushBackOnEmpty)
{
    LNode* L = ListInit();
    ListPushBack(L, 10);
    EXPECT_EQ(ListSize(L), 1);
    EXPECT_EQ(ListGetElem(L, 0)->data, 10);
    ListDestroy(L);
}

TEST(ListPushBackTest, PushBackOnNonEmpty)
{
    LNode* L = CreateListOfSize(3);
    ListPushBack(L, 4);
    EXPECT_EQ(ListSize(L), 4);
    EXPECT_EQ(ListGetElem(L, 3)->data, 4);
    ListDestroy(L);
}

TEST(ListPushBackTest, PushBack_SequentialOrder)
{
    LNode* L = ListInit();
    ListPushBack(L, 1);
    ListPushBack(L, 2);
    ListPushBack(L, 3);
    EXPECT_EQ(ListSize(L), 3);
    EXPECT_EQ(ListGetElem(L, 0)->data, 1);
    EXPECT_EQ(ListGetElem(L, 2)->data, 3);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListPopFront (head delete)
// ============================================================

TEST(ListPopFrontTest, PopFrontSingleElement)
{
    LNode* L = ListInit();
    ListPushBack(L, 42);
    LDataType val = ListPopFront(L);
    EXPECT_EQ(val, 42);
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

TEST(ListPopFrontTest, PopFrontMultipleElements)
{
    LNode* L = CreateListOfSize(3);
    EXPECT_EQ(ListPopFront(L), 1);
    EXPECT_EQ(ListPopFront(L), 2);
    EXPECT_EQ(ListPopFront(L), 3);
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

// ============================================================
// Test suite: ListPopBack (tail delete)
// ============================================================

TEST(ListPopBackTest, PopBackSingleElement)
{
    LNode* L = ListInit();
    ListPushBack(L, 42);
    LDataType val = ListPopBack(L);
    EXPECT_EQ(val, 42);
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

TEST(ListPopBackTest, PopBackMultipleElements)
{
    LNode* L = CreateListOfSize(3);
    EXPECT_EQ(ListPopBack(L), 3);
    EXPECT_EQ(ListPopBack(L), 2);
    EXPECT_EQ(ListPopBack(L), 1);
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

// ============================================================
// Test suite: Combined operations
// ============================================================

TEST(CombinedTest, PushFrontAndPopFront)
{
    LNode* L = ListInit();
    ListPushFront(L, 1);
    ListPushFront(L, 2);
    EXPECT_EQ(ListPopFront(L), 2);
    EXPECT_EQ(ListPopFront(L), 1);
    ListDestroy(L);
}

TEST(CombinedTest, PushBackAndPopBack)
{
    LNode* L = ListInit();
    ListPushBack(L, 1);
    ListPushBack(L, 2);
    EXPECT_EQ(ListPopBack(L), 2);
    EXPECT_EQ(ListPopBack(L), 1);
    ListDestroy(L);
}

TEST(CombinedTest, DeleteAndGetConsistency)
{
    LNode* L = CreateListOfSize(5);
    ListDelete(L, 0);
    ListDelete(L, 1);
    EXPECT_EQ(ListSize(L), 3);
    EXPECT_EQ(ListGetElem(L, 0)->data, 2);
    EXPECT_EQ(ListGetElem(L, 1)->data, 4);
    EXPECT_EQ(ListGetElem(L, 2)->data, 5);
    ListDestroy(L);
}

// ============================================================
// Test suite: ListDestroy
// ============================================================

TEST(ListDestroyTest, DestroyList)
{
    LNode* L = CreateListOfSize(5);
    ListDestroy(L);
}

TEST(ListDestroyTest, DestroyEmptyList)
{
    LNode* L = ListInit();
    ListDestroy(L);
}

// ============================================================
// Test suite: ListPrint
// ============================================================

TEST(ListPrintTest, PrintNonEmpty)
{
    LNode* L = CreateListOfSize(3);
    ListPrint(L);
    ListDestroy(L);
}

TEST(ListPrintTest, PrintEmpty)
{
    LNode* L = ListInit();
    ListPrint(L);
    ListDestroy(L);
}

// ============================================================
// Google Test main entry point
// ============================================================
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
