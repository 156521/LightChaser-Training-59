/*
 * 用 malloc 动态申请数组，输入若干个数并求平均值，最后 free 释放内存
 *
 * 编译：gcc dynamic_average.c -o dynamic_average
 * 运行：./dynamic_average   （Windows 下为 dynamic_average.exe）
 */
#include <stdio.h>
#include <stdlib.h>   /* malloc / free / exit 需要的头文件 */

int main(void)
{
    int     n;
    int    *arr = NULL;   /* 指向动态数组的指针 */
    int     i;
    double  sum = 0.0;    /* 总和，用 double 保证平均值有小数 */

    printf("请输入数字的个数 n：");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("输入不合法，n 必须是正整数。\n");
        return 1;
    }

    /* 申请 n 个 int 的内存空间（sizeof(int) 是每个元素占的字节数） */
    arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {    /* 申请失败一定要判断，否则后面会崩 */
        printf("内存申请失败！\n");
        return 1;
    }

    printf("请输入 %d 个整数（空格或回车分隔）：\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("第 %d 个输入不是合法整数。\n", i + 1);
            free(arr);            /* 出错也要先释放，避免内存泄漏 */
            arr = NULL;
            return 1;
        }
        sum += arr[i];
    }

    printf("\n你输入的数据：");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    /* 强制转换为 double 再相除，否则整数除法会丢掉小数部分 */
    printf("\n总和 = %g\n", sum);
    printf("平均值 = %.2f\n", sum / (double)n);

    /* 用完必须释放，并把指针置空，避免"悬空指针" */
    free(arr);
    arr = NULL;

    printf("内存已释放。\n");

    return 0;
}
