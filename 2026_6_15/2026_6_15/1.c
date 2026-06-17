#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int missingNumber(int* nums, int numsSize) 
{
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = 0; j < numsSize - 1 - i; j++)
		{
			if (nums[i] > nums[i + 1])
			{
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < numsSize; i++)
		nums[i] -= i;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
			return i;
	}
}

int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int r = missingNumber(nums, sz);
	printf("%d\n", r);
	return 0;
}