#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// int main()
// {
//     srand(time(NULL));
//     int ret=rand(); //生成随机数
//     int a=0;
//     do
//     {
//     printf("请输入一个数字：");
//     scanf("%d",&a);
//     if(a>ret)
//     {
//         printf("猜大了\n");
//     }else if(a<ret)
//     {
//         printf("猜小了\n");
//     }else
//     {
//         printf("恭喜你猜对了\n");
//         break;
//     }
//     } while (a);
//     return 0;
// }


int main(){
    double a,b,ret;
    char c;
    scanf("%lf %c %lf",&a,&c,&b);
    switch (c)
    {
    case '+':
        ret=a+b;
        break;
    case '-':
        ret=a-b;
        break;
    case '*':
        ret=a*b;
        break;
    case '/':
        ret=a/b;
        break;
    default:
        printf("运算符输入错误");
        break;
    }
    printf("%lf",ret);
    return 0;
}