#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//
//struct opPD {
//    char op;  // 运算符
//    int pd;   // 优先级
//};
//
//int operatorPrecedence(char ch) {
//    // '('的优先级需要很低，方便'('后面的下一个运算符入栈
//    static struct opPD arr[5] = {
//        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}
//    };
//
//    for (int i = 0; i < 5; ++i) {
//        if (arr[i].op == ch) {
//            return arr[i].pd;
//        }
//    }
//
//    // 如果获取优先级运算符不是以上运算符则报错
//    assert(false);
//    return -1;
//}
//
//// 判断是否是操作数
//bool isOperand(const char* str) {
//    // 只有一个字符，且是+-*/等运算符
//    if (str[0] >= '0' && str[0] <= '9')
//        return true;
//    else if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
//        return true;
//
//    return false;
//}
//
//void toRPN(const char* tokens[], int tokensSize) {
//    // 假设tokensSize<=10000
//    // 所以这里我们直接创建一个10000静态数组做栈
//    char stackArr[10000];
//
//    // top标记栈顶数据下一个位置
//    int top = 0;
//
//    for (int i = 0; i < tokensSize;) {
//        const char* str = tokens[i];
//
//        if (isOperand(str)) {  // 操作数
//            // 操作数直接输出
//            printf("%s ", str);
//            ++i;
//        }
//        else {  // 界限符
//            if (str[0] == '(') {
//                // 左括号入栈
//                stackArr[top++] = str[0];
//                ++i;
//            }
//            else if (str[0] == ')') {
//                // 右括号，则将所有的栈中的运算符全部出栈，直到遇到左括号
//                while (stackArr[top - 1] != '(') {
//                    printf("%c ", stackArr[--top]);
//                }
//
//                --top;  // 删除左括号
//                ++i;
//            }
//            else {
//                // 运算符
//                // 1、如果栈为空或者栈不为空且当前运算符比栈顶运算符优先级高，则当前运算符入栈
//                // 2、如果栈不为空且比栈顶运算符优先级低或相等，说明栈顶的运算符可以运算了，
//                // 输出栈顶运算符，当前运算符循环一圈，走运算法判断的逻辑。
//                if (top == 0 ||
//                    operatorPrecedence(str[0]) >
//                    operatorPrecedence(stackArr[top - 1])) {
//                    stackArr[top++] = str[0];
//                    ++i;
//                }
//                else {
//                    printf("%c ", stackArr[--top]);
//                }
//            }
//        }
//    }
//
//    // 栈中的运算符全部输出
//    while (top != 0) {
//        printf("%c ", stackArr[--top]);
//    }
//}
//
//int main()
//{
//    //"1+2-3";
//    //const char* expression[] = { "1", "+", "2", "-", "3" };
//
//    //"1+2-(3*4+5)-6";
//    const char* expression[] = {
//        "1", "+", "2", "-", "(", "3", "*", "4", "+", "5", ")", "-", "6"
//    };
//
//    //"1+2-(3*(4+5))-6";
//    //const char* expression[] = {
//    //    "1", "+", "2", "-", "(", "3", "*", "(", "4", "+", "5", ")", ")", "-", "6"
//    //};
//
//    toRPN(expression, sizeof(expression) / sizeof(expression[0]));
//
//    return 0;
//}

#include <stdio.h>

int main() {
    // 定义3行4列的二维数组A
    int A[3][4] = { {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12} };

    // C语言二维数组就是按照行优先存储
    // 下标第2行、第3列的数据是12，下面我们直接打印它的地址
    printf("%p\n", &A[2][3]);

    // Type A[M][N]的二维数组，假设二维数组的起始地址为start，
    // 则A[i][j]的存储地址 = start + (i * n + j) * sizeof(Type)

    // 这里我们按照行优先存储公式，由首地址计算12的地址，跟上一句是一样的
    // 需要额外说明的是&A[0][0]的类型是int*，int*变量加1是加一个
    // int大小，即4 byte，所以这里没有乘以sizeof(int)
    printf("%p\n", &A[0][0] + 2 * 4 + 3);

    return 0;
}

