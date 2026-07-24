#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <assert.h>

//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[10] = "world";
//
//	int cmp = strcmp(arr1, arr2);
//
//	printf("%d\n", cmp);
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[10] = "worlderf";
//
//	strncpy(arr1, arr2,5);
//	printf("%s\n", arr1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str1[20] = "hello\0----- ";
//    char str2[] = "worldxxxxxx";
//    strncat(str1, str2, 5);
//    printf("%s\n", str1); //helloworld
//    return 0;
//}

//int main()
//{
//	char str1[] = "abcdef";
//	char str2[] = "def";
//	char* tmp = strstr(str1, str2);
//	printf("%s\n", tmp);
//}

//char* my_strstr(const char* str1,const char* str2)
//{
//    assert(str1 && str2);
//    size_t len = strlen(str2);
//
//    const char* tmp1 = str1;
//    const char* tmp2 = str2;
//    const char* save = NULL;
//    int final = 0;
//    int cnt = 0;
//    size_t len1 = len;
//    while (*tmp1 != '\0')
//    {
//        if (*tmp1 != *tmp2)
//            tmp1++;
//        else
//        {
//            len1 = len;
//            cnt = 0;
//            int flag = 1;
//            while (len1--)
//            {
//                if (*tmp1 != *tmp2)
//                {
//                    flag = 0;
//                    break;
//                }
//                else
//                {
//                    if (cnt == 0)
//                        save = tmp1;
//                    tmp1++;
//                    tmp2++;
//                    cnt++;
//                }
//            }
//            if (flag == 0) //没找到
//                tmp2 = str2; //让子字符串重新回到初始位置
//            else //找到了
//            {
//                final = 1;
//                break;
//            }
//        }
//    }
//    if (final == 1)
//        return (char*)save;
//    else
//        return NULL;
//}
//
//int main()
//{
//    char str1[] = "abcdefabcdef";
//    char str2[] = "fabd";
//    char* p = my_strstr(str1, str2);
//    if (p != NULL)
//        printf("%s\n", p);
//    else
//        printf("没有找到\n");
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str[] = "byte-wizard@byte";// 原始字符串，里面包含 '-' 和 '@' 作为分隔符
//    // 定义分隔符字符串
//    const char* sep = "@-";// 注意：这里的 '@' 和 '-' 都会被当作分隔符
//    char buf[30] = { 0 };
//    strncpy(buf, str, 30);
//    /*
//        for 循环结构说明：
//        1. char* p = strtok(buf, sep)
//           第一次调用 strtok，传入要分割的字符串 buf
//        2. p != NULL
//           判断是否还分割出了有效的子字符串
//        3. p = strtok(NULL, sep)
//           后续调用 strtok，传入 NULL，表示继续分割上一次的字符串
//    */
//    for (char* p = strtok(buf, sep); p != NULL; p = strtok(NULL, sep))
//    {
//        // 打印每次分割得到的子字符串
//        printf("%s\n", p);
//    }
//    return 0;
//}

//1 1 2 3 5 8 13

//递归
//int fuc(int x)
//{
//	if (x == 1 || x == 2)
//		return 1;
//	else
//		return fuc(x - 1) + fuc(x - 2);
//}

//int func(int x)
//{
//	int a = 1;
//	int b = 1;
//	int c = a + b;
//	if (x == 1 || x == 2)
//		return 1;
//	else
//	{
//		while (x - 3)
//		{
//			a = b;
//			b = c;
//			c = a + b;
//			x--;
//		}
//		return c;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int final = func(n);
//	printf("%d\n", final);
//	return 0;
//}

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void getmemory(char* p)
//{
//    p = (char*)malloc(100);
//    strcpy(p, "hello world");
//}
//
//int main()
//{
//    char* str = NULL;
//    getmemory(str);
//    printf("%s\n", str);
//    free(str);
//    return 0;
//}
