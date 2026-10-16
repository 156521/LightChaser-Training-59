/*
 * 计算器
 * 用 scanf / printf 实现 + - * / 四则运算，除数为 0 时给出提示
 *
 * 编译：gcc calculator.c -o calculator
 * 运行：./calculator   （Windows 下为 calculator.exe）
 */
#include <stdio.h>

int main(void)
{
    double a, b;      /* 两个操作数，用 double 才能支持小数和浮点除法 */
    char   op;        /* 运算符 */
    char   line[128]; /* 用来丢弃非法的整行输入，防止死循环 */

    printf("===== 简易计算器 =====\n");
    printf("输入格式：数字 运算符 数字，例如 3.5 * 2\n");
    printf("输入 q 退出\n\n");

    for (;;) {
        printf("> ");

        /* 先读一个字符，看看是不是退出指令 */
        if (scanf(" %c", &op) != 1) {
            break;                  /* 输入流结束 */
        }
        if (op == 'q' || op == 'Q') {
            printf("已退出。\n");
            break;
        }

        /* 这个字符其实是数字的开头，把它还回输入流，
           再按 double 完整读取第一个操作数 */
        if (ungetc(op, stdin) == EOF) {
            break;
        }
        if (scanf("%lf", &a) != 1) {
            printf("输入有误：第一个操作数不是合法数字。\n\n");
            if (fgets(line, sizeof(line), stdin) == NULL) break;  /* 清空这一行 */
            continue;
        }

        /* 读运算符 */
        if (scanf(" %c", &op) != 1) {
            printf("输入有误：缺少运算符。\n\n");
            if (fgets(line, sizeof(line), stdin) == NULL) break;
            continue;
        }
        if (op == 'q' || op == 'Q') {
            printf("已退出。\n");
            break;
        }
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("输入有误：不支持的运算符 '%c'（仅支持 + - * /）。\n\n", op);
            if (fgets(line, sizeof(line), stdin) == NULL) break;
            continue;
        }

        /* 读第二个操作数 */
        if (scanf("%lf", &b) != 1) {
            printf("输入有误：第二个操作数不是合法数字。\n\n");
            if (fgets(line, sizeof(line), stdin) == NULL) break;
            continue;
        }

        /* 计算并输出结果 */
        switch (op) {
        case '+':
            printf("%g + %g = %g\n\n", a, b, a + b);
            break;
        case '-':
            printf("%g - %g = %g\n\n", a, b, a - b);
            break;
        case '*':
            printf("%g * %g = %g\n\n", a, b, a * b);
            break;
        case '/':
            if (b == 0.0) {                       /* 除数不能为 0 */
                printf("错误：除数不能为 0！\n\n");
            } else {
                printf("%g / %g = %g\n\n", a, b, a / b);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
