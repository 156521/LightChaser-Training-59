#include <stdio.h>
#include <string.h>

#define NAME_LEN 32   /* 姓名最大长度 */
#define MAX_NUM  50   /* 最多支持的学生人数 */

/* 定义一个"学生"结构体，把姓名和分数打包在一起 */
struct Student {
    char name[NAME_LEN];
    int  score;
};

int main(void)
{
    struct Student stu[MAX_NUM];
    int n, i, j;
    double sum = 0.0;
    int    max_score;

    printf("===== 成绩单 =====\n");
    printf("请输入学生人数（1~%d）：", MAX_NUM);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_NUM) {
        printf("人数不合法。\n");
        return 1;
    }

    /* 用循环逐个录入学生信息 */
    for (i = 0; i < n; i++) {
        printf("请输入第 %d 个学生的姓名和分数（例如：小明 95）：", i + 1);
        /* %s 读字符串，会自动在末尾补 '\0'；%d 读分数 */
        if (scanf("%31s %d", stu[i].name, &stu[i].score) != 2) {
            printf("输入格式有误，请重新输入。\n");
            i--;                 /* 这一次不算，重新录入 */
            while (getchar() != '\n') { }   /* 清空本行 */
            continue;
        }
        sum += stu[i].score;
    }

    /* 冒泡排序：按分数从高到低，顺便把姓名一起交换 */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (stu[j].score < stu[j + 1].score) {
                struct Student temp = stu[j];   /* 结构体整体赋值 */
                stu[j]     = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    /* 找出最高分（排完序后第 0 个就是最高分） */
    max_score = stu[0].score;

    /* 打印成绩单 */
    printf("\n================ 成绩单 ================\n");
    printf("%-6s %-16s %-8s %s\n", "排名", "姓名", "分数", "等级");
    printf("--------------------------------------\n");
    for (i = 0; i < n; i++) {
        char grade;
        if (stu[i].score >= 90)      grade = 'A';
        else if (stu[i].score >= 80) grade = 'B';
        else if (stu[i].score >= 70) grade = 'C';
        else if (stu[i].score >= 60) grade = 'D';
        else                         grade = 'F';

        printf("%-6d %-16s %-8d %c\n", i + 1, stu[i].name, stu[i].score, grade);
    }
    printf("======================================\n");

    /* 统计信息 */
    printf("总人数  ：%d 人\n", n);
    printf("平均分  ：%.2f\n", sum / n);
    printf("最高分  ：%d\n", max_score);

    printf("\n最高分同学：");
    for (i = 0; i < n; i++) {
        if (stu[i].score == max_score) {
            printf("%s ", stu[i].name);
        }
    }
    printf("\n");

    return 0;
}
