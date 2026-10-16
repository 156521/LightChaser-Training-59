//用指针交换两个变量的值
#include <stdio.h>

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

    printf("交换前:a = %d, b = %d\n", a, b);

    swap(&a, &b);     /* 传地址，&a 就是变量 a 的地址 */

    printf("交换后:a = %d, b = %d\n", a, b);

    return 0;
}
