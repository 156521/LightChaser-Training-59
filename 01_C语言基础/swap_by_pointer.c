/*
 * 用指针交换两个变量的值（自己实现 swap，不用临时变量之外的库函数）
 *
 * 编译：gcc swap_by_pointer.c -o swap_by_pointer
 * 运行：./swap_by_pointer   （Windows 下为 swap_by_pointer.exe）
 */
#include <stdio.h>

/*
 * 交换两个 int 变量的值
 * 参数是指针，接收的是变量的"地址"，所以能真正修改到外面的变量。
 * 如果写成 void swap(int a, int b) 就只是交换了副本，外面不变。
 */
void swap(int *px, int *py)
{
    int temp = *px;   /* *px 表示"px 指向的那个变量的值" */
    *px = *py;        /* 把 py 指向的值写进 px 指向的地址 */
    *py = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("交换前：a = %d, b = %d\n", a, b);

    swap(&a, &b);     /* 传地址，&a 就是变量 a 的地址 */

    printf("交换后：a = %d, b = %d\n", a, b);

    return 0;
}
