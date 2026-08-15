#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// 使用LSD（最低位优先）基数排序对非负整数数组进行升序排序  
// 前提：数组不能为空、n大于0，且数组中不包含负数  
void RadixSortLSD(int a[], int n)
{
	// 申请临时数组，用于保存每轮按当前数位分配后的结果  
	int* tmp = (int*)malloc(sizeof(int) * n);

	// 判断内存是否申请成功  
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	// 查找数组中的最大值，用于确定需要处理的数位数量  
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	// radix表示当前处理的数位：1为个位，10为十位，100为百位  
	int radix = 1;

	// 从最低位开始，依次处理每一个数位  
	while (max / radix > 0)
	{
		// count[i]记录当前数位为i的元素个数  
		int count[10] = { 0 };

		// addr[i]记录第i个虚拟桶在tmp数组中的起始位置  
		int addr[10] = { 0 };

		// 统计当前数位上0～9分别出现的次数  
		for (int i = 0; i < n; i++)
		{
			// 提取a[i]在当前数位上的数字  
			int x = (a[i] / radix) % 10;
			count[x]++;
		}

		// 通过前缀和计算每个虚拟桶在tmp数组中的起始位置  
		for (int i = 1; i < 10; i++)
		{
			addr[i] = addr[i - 1] + count[i - 1];
		}

		// 分配：按照当前数位将元素放入对应的虚拟桶  
		// 按原数组顺序遍历，可以保证排序的稳定性  
		for (int i = 0; i < n; i++)
		{
			int x = (a[i] / radix) % 10;

			// addr[x]自增后指向该虚拟桶的下一个空闲位置  
			tmp[addr[x]++] = a[i];
		}

		// 收集：将本轮排序结果复制回原数组  
		memcpy(a, tmp, sizeof(int) * n);

		// 将radix扩大10倍，进入下一个更高的数位  
		radix *= 10;
	}

	// 释放临时数组占用的内存  
	free(tmp);
}

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

// 测试LSD基数排序  
void TestRadixSortLSD()
{
	int a[] = { 274,109,63,930,589,184,269,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	RadixSortLSD(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



int main() {
	TestRadixSortLSD();
	return 0;
}

