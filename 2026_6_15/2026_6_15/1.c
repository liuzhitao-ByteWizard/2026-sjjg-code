#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    int a = 3;
    int b = 5;
    int ret = 0;
    ret = Add(a, b);
    printf("%d\n", ret);
    return 0;
}
