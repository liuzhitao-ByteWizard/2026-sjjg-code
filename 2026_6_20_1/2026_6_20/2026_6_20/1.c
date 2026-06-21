#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
//int removeElement(int* nums, int numsSize, int val) {
//    int tmp[numsSize];   // 创建临时数组
//    int k = 0;           // 记录不等于 val 的元素个数
//
//    // 1. 遍历 nums，把不等于 val 的元素放入 tmp
//    for (int i = 0; i < numsSize; i++) {
//        if (nums[i] != val) {
//            tmp[k] = nums[i];
//            k++;
//        }
//    }
//
//    // 2. 把 tmp 中的有效元素拷贝回 nums
//    for (int i = 0; i < k; i++) {
//        nums[i] = tmp[i];
//    }
//
//    // 3. 返回不等于 val 的元素个数
//    return k;
//}

//int removeElement(int* nums, int numsSize, int val) 
//{
//	assert(nums);
//	int src = 0, dst = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] == val)
//			src++;
//		else
//		{
//			nums[dst] = nums[src];
//			dst++;
//			src++;
//		}
//	}
//	return dst;
//}

//int removeDuplicates(int* nums, int numsSize) {
//    int src = 0, dst = 1;
//    while (src < numsSize)
//    {
//        if (nums[src] == nums[dst])
//        {
//            src++;
//        }
//        else
//        {
//            dst++;
//            nums[dst] = nums[src];
//            src++;
//        }
//    }
//    return dst + 1;
//}

int removeDuplicates(int* nums, int numsSize) {
    // src 用来从前往后遍历数组
    // dst 指向当前最后一个不重复元素的位置
    int src = 0;
    int dst = 0;

    // src 遍历整个数组
    while (src < numsSize)
    {
        // 如果 nums[src] 和 nums[dst] 相等，
        // 说明 nums[src] 是重复元素，直接跳过
        if (nums[src] == nums[dst])
        {
            src++;
        }
        else
        {
            // 如果 nums[src] 和 nums[dst] 不相等，
            // 说明 nums[src] 是新的唯一元素

            // dst 后移，指向下一个可以存放唯一元素的位置
            dst++;

            // 把新的唯一元素放到 nums[dst]
            nums[dst] = nums[src];

            // src 后移，继续遍历
            src++;
        }
    }

    // dst 是最后一个唯一元素的下标
    // 所以唯一元素个数为 dst + 1
    return dst + 1;
}