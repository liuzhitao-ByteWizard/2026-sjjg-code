#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//int cmp_int(const void* x, const void* y)
//{
//	return *((int*)x) - *((int*)y);
//}
//
//int main()
//{
//	int arr[10] = { 8,7,6,9,5,4,3,1,2,0 };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}

//struct Stu
//{
//    char name[20];
//    int age;
//};
//
//int cmp_stu_name(const void* p1, const void* p2)
//{
//    return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
//}
//
//int main()
//{
//    // 定义结构体数组，用来存储学生信息
//    struct Stu p[] = { {"zhangsan",21} ,{"lisi",19 }, {"wangwu",20 } };
//
//    size_t sz = sizeof(p) / sizeof(p[0]);
//    qsort(p, sz, sizeof(p[0]), cmp_stu_name);
//    for (int i = 0; i < sz; i++)
//        printf("%s ", p[i].name);
//    
//}

// 找出数组中只出现一次的数字
// 前提：除一个数字只出现一次外，其余数字均出现两次
int singleNumber(int* nums, int numsLen)
{
    // 异或运算中，0 与任意数字异或仍得到该数字
    int result = 0;

    // 将数组中的所有元素依次进行异或
    for (int i = 0; i < numsLen; i++)
    {
        /*
         * 相同数字异或的结果为 0，即 a ^ a = 0。
         * 数组中成对出现的数字会相互抵消，
         * 最终只剩下那个仅出现一次的数字。
         */
        result ^= nums[i];
    }

    // 返回只出现一次的数字
    return result;
}
