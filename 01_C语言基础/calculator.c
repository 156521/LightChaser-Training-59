#include<stdio.h>
int main()
{
    int a;
    int b;                                                  //赋值要计算的数字
    printf("请输入数字");                                    //输入要计算的数字
    scanf("%d %d",&a,&b);
    printf("请输入你要求的计算：\n1:加\n2:减\n3:乘\n4:除");    //选择计算方式
    int d;
    scanf("%d",&d);                                          //用条件语句给用户提供计算方式的选择
    if(d==1)
    {
        printf("计算结果为：%d\n",a+b);
    }
    else if (d==2)
    {
       printf("计算结果为:%d\n",a-b);
    }
    else if (d==3)
    {
       printf("计算结果为:%d\n",a*b);
    }
    else if (d==4)
    {
        if (d!=0)                                                 //用除法的前提是分母不为零
        {
             printf("计算结果为:%d\n",a/b);
        }
        else
        {
            printf("无法计算");
        }
    }
return 0;

}