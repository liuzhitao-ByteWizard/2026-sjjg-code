#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <stdbool.h>

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);

void QuickSort(int* a, int left, int right);
int PartitionDigHole(int* a, int left, int right);
int PartitionLomuto(int* a, int left, int right);