#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void rotate(int* nums, int numsSize, int k) 
//{
//	k = k % 7;
//	while (k--)
//	{
//		int end = nums[numsSize - 1];
//		for (int i = numsSize - 1; i > 0; i--)
//		{
//			nums[i] = nums[i - 1];
//		}
//		nums[0] = end;
//	}
//
//}

//void rotate(int* nums  ,int numsSize, int k)
//{
//	k %= numsSize;
//
//	if (k == 0)
//		return;
//	int arr[numsSize];
//	int i = 0;
//	int j = numsSize - k;
//	int k1 = k;
//	while (k1-- && j < numsSize)
//		arr[i++] = nums[j++];
//	
//	for (j = 0; j < numsSize - k; j++)
//	{
//		arr[i++] = nums[j];
//	}
//	for (int i = 0; i < numsSize; i++)
//		nums[i] = arr[i];
//}

//void rotate(int* nums, int numsSize, int k) {
//	k %= numsSize;
//	if (k == 0)
//		return;
//	//变长数组，在 C99 中支持，但在 Visual Studio 的 C 编译器中通常不支持。
//	int tmp[k];
//	// 拷贝nums中的后k个到tmp的前k个位置
//	int j = 0;
//	for (int i = numsSize - k; i < numsSize; ++i) {
//		tmp[j++] = nums[i];
//	}
//
//	// 从后往前拷贝nums前n-k个到后n-k个位置
//	for (int i = numsSize - k - 1; i >= 0; --i) {
//		nums[i + k] = nums[i];
//	}
//
//	// 将tmp数组中的值拷贝回到nums数组
//	for (int i = 0; i < k; ++i) {
//		nums[i] = tmp[i];
//	}
//}




int main()
{
	int nums[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int k = 0;
	scanf("%d", &k);

	rotate(nums, sz, k);
	
	for (int i = 0; i < sz; i++)
		printf("%d ", nums[i]);
	return 0;
}