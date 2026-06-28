#include <gtest/gtest.h>

#include <algorithm>
#include <initializer_list>
#include <string>
#include <vector>

#if defined(_MSC_VER) && defined(_DEBUG)
#include <crtdbg.h>
#endif

extern "C" {
#include "../DCList/DCList.h"
}

namespace {

// 将链表中的有效数据结点转换为 vector，便于和期望顺序做比较。
std::vector<int> ToVector(DCListNode* L)
{
    std::vector<int> values;
    for (DCListNode* cur = L->next; cur != L; cur = cur->next)
    {
        values.push_back(cur->data);
    }

    return values;
}

// 同时检查链表数据顺序和双向循环指针，避免只验证数据而漏掉 prev/next 连接错误。
void ExpectListEquals(DCListNode* L, std::initializer_list<int> expectedValues)
{
    ASSERT_NE(nullptr, L);
    EXPECT_EQ(std::vector<int>(expectedValues), ToVector(L));

    size_t guard = 0;
    const size_t maxSteps = expectedValues.size() + 1;
    DCListNode* cur = L;
    do
    {
        ASSERT_NE(nullptr, cur->next);
        ASSERT_NE(nullptr, cur->prev);
        EXPECT_EQ(cur, cur->next->prev);
        EXPECT_EQ(cur, cur->prev->next);

        cur = cur->next;
        ++guard;
    } while (cur != L && guard <= maxSteps);

    EXPECT_EQ(L, cur);
    EXPECT_LE(guard, maxSteps);
}

// Google Test 捕获 stdout 时，Windows 环境可能带有 CRLF，这里统一成 LF 后再断言。
std::string NormalizeNewline(std::string text)
{
    text.erase(std::remove(text.begin(), text.end(), '\r'), text.end());
    return text;
}

#if defined(_MSC_VER) && defined(_DEBUG)
// Debug 断言死亡测试中关闭弹窗报告，保证测试进程能自动结束并被 gtest 捕获。
void ConfigureAssertForDeathTest()
{
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
}
#endif

class DCListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        list = DCListInit();
    }

    void TearDown() override
    {
        DCListDestroy(list);
        list = nullptr;
    }

    DCListNode* list = nullptr;
};

} // namespace

TEST_F(DCListTest, InitCreatesEmptyCircularHeadNode)
{
    // 初始化后的链表只有头结点，头结点的 next/prev 都指向自己。
    ASSERT_NE(nullptr, list);
    EXPECT_EQ(list, list->next);
    EXPECT_EQ(list, list->prev);
    ExpectListEquals(list, {});
}

TEST_F(DCListTest, InsertSupportsFrontBackAndMiddlePositions)
{
    // DCListInsert 的语义是在 pos 后插入，因此连续在头结点后插入会形成头插效果。
    DCListInsert(list, 1);
    DCListInsert(list, 2);
    DCListInsert(list, 3);
    ExpectListEquals(list, {3, 2, 1});

    // 在尾结点后插入，等价于追加到链表尾部。
    DCListInsert(list->prev, 4);
    ExpectListEquals(list, {3, 2, 1, 4});

    // 取下标为 1 的结点，在它后面插入，验证中间插入后的前后指针仍然正确。
    DCListNode* middle = DCListGetElem(list, 1);
    ASSERT_NE(nullptr, middle);
    EXPECT_EQ(2, middle->data);

    DCListInsert(middle, 99);
    ExpectListEquals(list, {3, 2, 99, 1, 4});
}

TEST_F(DCListTest, GetElemUsesZeroBasedIndexAndReturnsHeadForEmptyIndexZero)
{
    // 空链表中查询 0 号位置时，当前实现会返回头结点，这里锁定这个既有行为。
    EXPECT_EQ(list, DCListGetElem(list, 0));

    DCListPushBack(list, 10);
    DCListPushBack(list, 20);
    DCListPushBack(list, 30);

    EXPECT_EQ(10, DCListGetElem(list, 0)->data);
    EXPECT_EQ(20, DCListGetElem(list, 1)->data);
    EXPECT_EQ(30, DCListGetElem(list, 2)->data);
}

TEST_F(DCListTest, DeleteRemovesFrontMiddleAndBackNodes)
{
    // 先构造稳定顺序，再分别删除头部、中间、尾部结点。
    DCListPushBack(list, 1);
    DCListPushBack(list, 2);
    DCListPushBack(list, 3);
    DCListPushBack(list, 4);
    ExpectListEquals(list, {1, 2, 3, 4});

    DCListDelete(list->next);
    ExpectListEquals(list, {2, 3, 4});

    DCListDelete(DCListGetElem(list, 1));
    ExpectListEquals(list, {2, 4});

    DCListDelete(list->prev);
    ExpectListEquals(list, {2});
}

TEST_F(DCListTest, PushAndPopFrontKeepExpectedOrder)
{
    // 头插会让新元素成为首元素，头删会删除当前首元素。
    DCListPushFront(list, 1);
    DCListPushFront(list, 2);
    DCListPushFront(list, 3);
    ExpectListEquals(list, {3, 2, 1});

    DCListPopFront(list);
    ExpectListEquals(list, {2, 1});

    DCListPopFront(list);
    DCListPopFront(list);
    ExpectListEquals(list, {});
}

TEST_F(DCListTest, PushAndPopBackKeepExpectedOrder)
{
    // 尾插会保持插入顺序，尾删会删除当前最后一个元素。
    DCListPushBack(list, 1);
    DCListPushBack(list, 2);
    DCListPushBack(list, 3);
    ExpectListEquals(list, {1, 2, 3});

    DCListPopBack(list);
    ExpectListEquals(list, {1, 2});

    DCListPopBack(list);
    DCListPopBack(list);
    ExpectListEquals(list, {});
}

TEST_F(DCListTest, PrintWritesElementsInForwardOrder)
{
    // 捕获 DCListPrint 的标准输出，验证打印格式和链表顺序一致。
    DCListPushBack(list, 1);
    DCListPushBack(list, 2);
    DCListPushBack(list, 3);

    testing::internal::CaptureStdout();
    DCListPrint(list);
    const std::string output = NormalizeNewline(testing::internal::GetCapturedStdout());

    EXPECT_EQ("1->2->3->\n", output);
}

#if defined(_DEBUG) && !defined(NDEBUG) && GTEST_HAS_DEATH_TEST

TEST(DCListDeathTest, PopFrontOnEmptyListTriggersAssertInDebug)
{
    // Debug 版本中，空链表头删属于非法操作，应触发断言。
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    DCListNode* list = DCListInit();

    EXPECT_DEATH(
        {
            ConfigureAssertForDeathTest();
            DCListPopFront(list);
        },
        "");

    DCListDestroy(list);
}

TEST(DCListDeathTest, PopBackOnEmptyListTriggersAssertInDebug)
{
    // Debug 版本中，空链表尾删属于非法操作，应触发断言。
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    DCListNode* list = DCListInit();

    EXPECT_DEATH(
        {
            ConfigureAssertForDeathTest();
            DCListPopBack(list);
        },
        "");

    DCListDestroy(list);
}

TEST(DCListDeathTest, GetElemInvalidIndexTriggersAssertInDebug)
{
    // 负数下标和超过当前实现容忍范围的越界下标都应由 DCListGetElem 的断言拦截。
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    DCListNode* list = DCListInit();
    DCListPushBack(list, 10);

    EXPECT_DEATH(
        {
            ConfigureAssertForDeathTest();
            DCListGetElem(list, -1);
        },
        "");

    EXPECT_DEATH(
        {
            ConfigureAssertForDeathTest();
            DCListGetElem(list, 2);
        },
        "");

    DCListDestroy(list);
}

#endif
