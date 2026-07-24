#define _CRT_SECURE_NO_WARNINGS

// test.c
#include "LinkStack.h"

int main() {
    LinkStack s;
    LinkStackInit(&s);

    // 入栈，检测栈顶数据元素和栈中有效数据元素是否正确
    LinkStackPush(&s, 1);
    LinkStackPush(&s, 2);
    LinkStackPush(&s, 3);
    printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
    printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

    LinkStackPush(&s, 4);
    LinkStackPush(&s, 5);
    printf("栈中元素总数为：%d\n", LinkStackSize(&s));
    printf("栈顶元素为：%d\n", LinkStackTop(&s));

    // 出栈
    printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
    printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
    printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
    // printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
    // printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

    // 断言报错
    // printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

    //LinkStackDestroy(&s);

    return 0;
}

//bool isValid(char* s) {
//    LinkStack st;
//    LinkStackInit(&st);
//
//    while (*s) {
//        if (*s == '(' || *s == '[' || *s == '{') {
//            // 左括号入栈
//            LinkStackPush(&st, *s);
//        }
//        else {
//            // 栈为空，说明右括号多于左括号
//            if (LinkStackEmpty(&st)) {
//                LinkStackDestroy(&st);
//                return false;
//            }
//
//            STDataType top = LinkStackPop(&st);
//
//            // 判断左右括号的类型是否匹配
//            if ((top == '(' && *s != ')')
//                || (top == '[' && *s != ']')
//                || (top == '{' && *s != '}')) {
//                LinkStackDestroy(&st);
//                return false;
//            }
//        }
//
//        ++s;
//    }
//
//    // 栈不为空，说明存在未匹配的左括号
//    bool empty = LinkStackEmpty(&st);
//    LinkStackDestroy(&st);
//
//    return empty;
//}