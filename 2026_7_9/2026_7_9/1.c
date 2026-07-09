#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 反转字符串
 * @param str string字符串
 * @return string字符串
 */
//char* solve(char* str) {
//    // write code here
//    char str1[1010]  = "\0";
//    size_t len = strlen(str);
//    char* p = str + len - 1; //指向的末尾字符串
//    int cnt = 0;
//    while (len--)
//    {
//        str1[cnt] = *(p--);
//        cnt++;
//    }
//    strncpy(str, str1, cnt + 1);
//    return str;
//}

//char* solve(char* str) {
//    // write code here
//    size_t len = strlen(str);
//    char* left = str; //指向首元素
//    char* right = str + len - 1; //指向末尾元素
//    while (left <= right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//    return str;
//}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param str string字符串
 * @return int整型
 */
//int FirstNotRepeatingChar(char* str) {
//    // write code here
//    size_t len = strlen(str);
//    int arr[26] = { 0 };
//    int arr1[26] = { 0 };
//    char* p = str; //遍历字符串
//    int flag = 1; //标记只出现一次的字符
//    while (*p != '\0')
//    {
//        if (islower(*p))
//            arr[*p - 'a']++;
//        else
//            arr1[*p - 'A']++;
//        p++;
//    }
//    int min1 = 10010, min2 = 10010, min = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (arr[i] == 1)
//        {
//            p = str;
//            flag = 0;
//            int x = 0; //找到第一次出现的元素在字符串中的下标
//            while (*p != i + 'a')
//            {
//                p++;
//                x++;
//            }
//            if (x < min1)
//                min1 = x; //最小下标
//        }
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (arr1[i] == 1)
//        {
//            p = str;
//            flag = 0;
//            int x = 0; //找到第一次出现的元素在字符串中的下标
//            while (*p != i + 'A')
//            {
//                p++;
//                x++;
//            }
//            if (x < min2)
//                min2 = x; //最小下标
//        }
//    }
//
//    if (min1 >= min2)
//        min = min2;
//    else
//        min = min1;
//    if (flag == 1)
//        return -1;
//    else
//        return min;
//}


/**
 *
 * @param A int整型一维数组
 * @param ALen int A数组长度
 * @param B int整型一维数组
 * @param BLen int B数组长度
 * @return void
 */
//void merge(int* A, int ALen, int m, int* B, int BLen, int n) 
//{
//    // write code here
//    
//    ////第一种极端情况：B中所有元素小于等于A
//    //if (A[0] >= B[n - 1])
//    //{
//    //    for (int i = 0; i < n; i++)
//    //    {
//    //        for (int j = m + n - 1; j >= 1; j--)
//    //            A[j] = A[j - 1];
//    //    }
//    //    for (int i = 0; i < n; i++)
//    //        A[i] = B[i];
//    //    return;
//    //}
//    //
//    ////第二种极端情况：A中所有元素小于等于B
//    //if (A[m -1] <= B[0])
//    //{ 
//    //    int j = 0;
//    //    for (int i = m; i < m + n; i++)
//    //    {
//    //        A[i] = B[j];
//    //        j++;
//    //    }   
//    //    return;
//    //}
//    //第三种情况：部分小或者部分大
//    int j = 0;
//    for (int i = m; i < m + n; i++)
//    {
//        A[i] = B[j];
//        j++;
//    }
//    for (int i = 0; i < m + n - 1; i++)
//    {
//        for (int j = 0;j < m + n - i - 1;j++)
//        {
//            if (A[j] > A[j + 1])
//            {
//                int tmp = A[j];
//                A[j] = A[j + 1];
//                A[j + 1] = tmp;
//            }
//        }
//    }
//}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @return int整型
 */
int singleNumber(int* nums, int numsLen) {
    // write code here
    if (numsLen == 1)
        return nums[0];
    else
    {
        int* cur1 = nums;
        int* cur2 = nums;
        for (int i = 0; i < numsLen; i++)
        {
            int cnt = 0;
            for (int j = 0; j < numsLen; j++)
            {
                if (*(cur1 + i) == *(cur2 + j))
                    cnt++;
            }
            if (cnt == 1)
                return *(cur1 + i);
        }
        return -1;
    }
}


