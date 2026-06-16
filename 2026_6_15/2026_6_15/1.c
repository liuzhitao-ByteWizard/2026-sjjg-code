#define _CRT_SECURE_NO_WARNINGS
//// 这里我们给出了一个简单的 summation 累加算法，根据上面的事前估算公式可以得到
//// 算法的运行时间 F(N) = C1*1 + C2*1 + C3*(N+1) + C4*N + C5*N + C6*1
//
//int Summation(int N) {        // 消耗时间    执行次数
//    int ret = 0;              // C1          1
//    int i = 1;                // C2          1
//
//    while (i <= N) {          // C3          N+1
//        ret += i;             // C4          N
//        i++;                  // C5          N
//    }
//
//    return ret;               // C6          1
//}

//#include <stdio.h>
//
//// 计算BubbleSort的时间复杂度?
//void BubbleSort(int* a, int n) {
//    assert(a);
//    for (size_t end = n; end > 0; --end) {
//        for (size_t i = 1; i < end; ++i) {
//            if (a[i - 1] > a[i]) {
//                Swap(&a[i - 1], &a[i]);
//            }
//        }
//    }
//}

//#define N 3
//
//void MatrixMultiply(int A[][N], int B[][N], int C[][N]) {
//    // 矩阵相乘
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            C[i][j] = 0;
//            for (int k = 0; k < N; k++) {
//                C[i][j] += A[i][k] * B[k][j];
//            }
//        }
//    }
//
//    // 打印结果
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("%d ", C[i][j]);
//        }
//        printf("\n");
//    }
//}

//#include <stdio.h>
//
//void Count(int n) {
//    for (int i = 1; i < n; i *= 2) {
//        printf("%d\n", i);
//    }
//}
//
//int main() {
//    Count(100);
//    return 0;
//}

//int Find(int* a, int n, int x) {
//    for (int i = 1; i < n; i++) {
//        if (a[i] == x)
//            return i;
//    }
//    return -1;
//}

//long long Fac(size_t N) {
//    if (0 == N)
//        return 1;
//
//    return Fac(N - 1) * N;
//}

// 算法的运行空间F(N) = C1*1 + C2*2 + C3*N
double Func(int N) {        // 空间大小(字节)  变量个数
    double ret = 0;         // C1             1
    int i = 1;              // C2             1
    char tmp[N];            // C3             N
    while (i <= N) {
        ret += i;
        i++;
    }
    return ret;
}