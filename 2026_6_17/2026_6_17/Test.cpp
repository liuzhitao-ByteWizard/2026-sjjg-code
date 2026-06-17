//#define _CRT_SECURE_NO_WARNINGS
// 抽象数据类型
//ADT LinearList{
//    //////////////////////////数据结构/////////////////////////////
//
//    数据对象: D = {ai | ai ∈ ElemSet, i = 1, 2, 3, ..., n, n >= 0}
//    数据关系: R = { < a{i - 1}, ai > | ai - 1, ai ∈ D, i = 1, 2, 3, ..., n}
//
//    //////////////////////////基本操作的定义/////////////////////////////
//    // 需要注意的是下面定义中的&L是指的C++中的引用
//    // 线性表的创建和销毁
//
//    InitList(&L)              // 初始化一个空的线性表
//    Destroy(&L)               // 销毁线性表：释放线性表内部的内存空间
//
//    // 线性表中元素获取
//    GetElem(L, i)             // 获取线性表中第 i 个数据元素并返回
//    LocateElem(L, e, compare) // 返回线性表中与 e 满足 compare 关系的第一个元素，返回其位序
//
//    // 线性表中插入及删除元素
//    ListInsert(&L, i, e)      // 在线性表的第 i 个位置上插入元素 e
//    ListDelete(&L, i, &e)     // 删除线性表中第 i 个位置的元素，并用 e 返回删除元素的值
//
//    // 线性表的其他辅助操作
//    ListPrint(L)              // 打印线性表中的所有元素
//    ListEmpty(L)              // 若线性表为空表返回真，否则返回假
//    ListLength(L)             // 返回线性表中有效元素的个数
//} ADT LinearList

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int& b = a;
//
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//	return 0;
//}
//

////注意：使用引用语法时要用 C++ 编写 ， 将代码文件改为后缀为.cpp的文件
//// Test.cpp
//#include <stdio.h>
//
//int main() {
//    int a = 0;
//
//    // 引用：b和c是a的别名
//    int& b = a;
//    int& c = a;
//
//    // 也可以给别名b取别名，d相当于还是a的别名
//    int& d = b;
//
//    ++d;
//
//    // 这里取地址我们看到是一样的
//    printf("%p\n", &a);
//    printf("%p\n", &b);
//    printf("%p\n", &c);
//    printf("%p\n", &d);
//
//    return 0;
//}

//#include <stdio.h>
//
//void add(int& x) {
//    x++;
//}
//
//int main()
//{
//    int x = 0;
//    add(x);
//    printf("%d\n", x);
//    return 0;
//}

//#include <stdio.h>
//
////tyedef是为了方便类型转换
//typedef int SqDataType;
//
////顺序表的最大存储的数据个数
//#define Sq_MAX_SIZE 10
//
////静态顺序表的结构定义
//typedef struct SequenceList
//{
//	SqDataType arr[Sq_MAX_SIZE]; //存储数据的静态数组
//	int size; //记录顺序表中已经存入的数据个数
//}SqList;
//
//typedef struct
//{
//	SqDataType arr[Sq_MAX_SIZE]; //存储数据的静态数组
//	int size; //记录顺序表中已经存入的数据个数
//}SqList;
//
//int main()
//{
//	return 0;
//}

#include "SqList.h"

int main()
{
	SqList ps;
	SqListInit(&ps);
	SqListInsert(&ps, 0, 1);
	SqListInsert(&ps, 1, 2);
	SqListInsert(&ps, 2, 3);
	SqListInsert(&ps, 3, 4);
	SqListPrint(&ps);
	return 0;
}
