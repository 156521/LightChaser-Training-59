//打印 1~100 的奇数和
#include <stdio.h>

int main(void)
{
    int sum = 0;   /* 累加结果，初值必须为 0 */
    int i;

    printf("1~100 之间的奇数：\n");

    for (i = 1; i <= 100; i++) {
        if (i % 2 == 1) {          /* 模 2 余 1 => 奇数 */
            printf("%3d ", i);
            sum += i;              /* 累加到 sum */
        }
    }

    printf("\n\n1~100 的奇数和为：%d\n", sum);

    return 0;
}
