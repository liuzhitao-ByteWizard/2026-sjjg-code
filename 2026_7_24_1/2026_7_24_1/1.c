#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//bool validateStackSequences(int* pushed, int pushedSize,
//    int* popped, int poppedSize) {
//    int stackArr[1000];  // 使用数组模拟栈
//    int top = 0;         // 栈顶位置，同时表示当前栈中元素个数
//    int j = 0;           // 当前需要匹配的出栈元素下标
//
//    // 按照 pushed 的顺序依次将元素压入栈中
//    for (int i = 0; i < pushedSize; ++i) {
//        stackArr[top++] = pushed[i];
//
//        /*
//         * 如果栈顶元素与当前待出栈元素相同，
//         * 就立即执行出栈，并继续匹配下一个出栈元素。
//         */
//        while (top != 0 &&
//            j < poppedSize &&
//            stackArr[top - 1] == popped[j]) {
//            --top;  // 弹出栈顶元素
//            ++j;    // 检查出栈序列中的下一个元素
//        }
//    }
//
//    // 所有出栈元素均成功匹配，说明出栈序列合法
//    return j == poppedSize;
//    //return top == 0
//}

//判断是否是操作数
//bool isOperand(char* s) {
//    if (*s >= '0' && *s <= '9')
//        return true;
//    else if (s[0] == '-' && s[1] >= '0' && s[1] <= '9')
//        return true;
//    else
//        return false;
//}
//
//int evalRPN(char** tokens, int tokensSize) {
//    //创建静态栈
//    int stackArr[10000];
//    int top = 0;
//
//    //遍历字符串
//    for (int i = 0; i < tokensSize; i++) {
//        if (isOperand(tokens[i])) {
//            //入栈
//            stackArr[top++] = atoi(tokens[i]);
//        }
//        else {
//            int right = stackArr[--top]; //右操作数
//            int left = stackArr[--top]; //左操作数
//            switch (tokens[i][0]) {
//            case '+':
//                //入栈
//                stackArr[top++] = right + left;
//                break;
//            case '-':
//                stackArr[top++] = left - right;
//                break;
//            case '*':
//                stackArr[top++] = left * right;
//                break;
//            case '/':
//                stackArr[top++] = left / right;
//                break;
//            }
//        }
//    }
//    return stackArr[0];
//}


// 计算递归求阶乘 Fac 算法的空间复杂度？
long long Fac(size_t N)
{
    if (N <= 0)
        return 1;

    return Fac(N - 1) * N;
}

int main() {
    int r = Fac(5);
    return 0;
}