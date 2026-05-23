// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// // int main()
// // {
// //     srand(time(NULL));
// //     int ret=rand(); //生成随机数
// //     int a=0;
// //     do
// //     {
// //     printf("请输入一个数字：");
// //     scanf("%d",&a);
// //     if(a>ret)
// //     {
// //         printf("猜大了\n");
// //     }else if(a<ret)
// //     {
// //         printf("猜小了\n");
// //     }else
// //     {
// //         printf("恭喜你猜对了\n");
// //         break;
// //     }
// //     } while (a);
// //     return 0;
// // }


// // #define countsize 100
// // typedef struct task_niu{
// //     int top;
// //     int data[countsize];
// // }task_niu;
// // task_niu* init_stack(){
// //     task_niu* p=(task_niu*)malloc(sizeof(task_niu));
// //     if(p==NULL)
// //     {
// //         perror("malloc error");
// //         return NULL;
// //     }
// //     memset(p->data,0,sizeof(p->data));
// //     p->top=-1;
// //     return p;
// // }
// // void push(task_niu* p,int data){
// //     if(p==NULL)
// //     {
// //         printf("空栈\n");
// //         return;
// //     }
// //     if(p->top==countsize-1)
// //     {
// //         printf("栈已满\n");
// //         return;
// //     }
// //     p->top++;
// //     p->data[p->top]=data;
// // }
// // void pop(task_niu* p){
// //     if(p==NULL)
// //     {
// //         printf("空栈\n");
// //         return;
// //     }
// //     if(p->top==-1)
// //     {
// //         printf("栈已空\n");
// //         return;
// //     }
// //     int data=p->data[p->top];
// //     p->top--;
// // }
// // void print_stack(task_niu* p){
// //     if(p==NULL)
// //     {
// //         printf("空栈\n");
// //         return;
// //     }
// //     if(p->top==-1)
// //     {
// //         printf("栈已空\n");
// //         return;
// //     }
// //     for(int i=0;i<=p->top;i++)
// //     {
// //         printf("%d ",p->data[i]);
// //     }
// //     printf("\n");
// // }



// // // int main(){
// // //     double a,b,ret;
// // //     char c;
// // //     scanf("%lf %c %lf",&a,&c,&b);
// // //     switch (c)
// // //     {
// // //     case '+':
// // //         ret=a+b;
// // //         break;
// // //     case '-':
// // //         ret=a-b;
// // //         break;
// // //     case '*':
// // //         ret=a*b;
// // //         break;
// // //     case '/':
// // //         ret=a/b;
// // //         break;
// // //     default:
// // //         printf("运算符输入错误");
// // //         break;
// // //     }
// // //     printf("%lf",ret);
// // //     return 0;
// // // }


// // int main(){
// //     task_niu* p=init_stack();
// //     push(p,1);
// //     push(p,2);
// //     push(p,3);
// //     push(p,4);
// //     push(p,5);
// //     print_stack(p);
// //     pop(p);
// //     pop(p);
// //     print_stack(p);
// //     return 0;
// // }

// #define datasize 100
// #define opsize 4
// typedef struct task_num{
//     double data[datasize];
//     int top; //栈顶指针
// }task_num;
// typedef struct task_op{
//     char data[opsize];
//     int top;
// }task_op;
// task_num* init_stack_num(){
//     task_num* p=(task_num*)malloc(sizeof(task_num));
//     if(p==NULL)
//     {
//         perror("malloc error");
//         return NULL;
//     }
//     memset(p,0,sizeof(p));
//     p->top=-1;
//     return p;
// }
// task_op* init_stack_op(){
//     task_op* p=(task_op*)malloc(sizeof(task_op));
//     if(p==NULL)
//     {
//         perror("malloc error");
//         return NULL;
//     }
//     memset(p,0,sizeof(p));
//     p->top=-1;
//     return p;
// }
// int push_num(task_num* p,double data){
//     if(p==NULL)
//     {
//         printf("空栈\n");
//         return 0;
//     }
//     if(p->top==datasize-1)
//     {
//         printf("栈已满\n");
//         return 0;
//     }
//     p->top++;
//     p->data[p->top]=data;//数字入栈
//     return 1;
// }
// int  push_op(task_op* p,char data){
//     if(p==NULL)
//     {
//         printf("空栈\n");
//         return 0;
//     }
//     if(p->top==opsize-1)
//     {
//         printf("栈已满\n");
//         return 0;
//     }
//     p->top++;
//     p->data[p->top]=data;//符号入栈
//     return 1;
// }
// double pop_num(task_num* p){
//     if(p==NULL)
//     {
//         printf("空栈\n");
//         return 0;
//     }
//     // if(p->top==-1)
//     // {
//     //     printf("栈已空\n");
//     //     return 0;
//     // }
//     double data=p->data[p->top];
//     p->top--;
//     return data;//数字出栈
// }
// char pop_op(task_op* p){
//     if(p==NULL)
//     {
//         printf("空栈\n");
//         return 0;
//     }
//     // if(p->top==-1)
//     // {
//     //     printf("栈已空\n");
//     //     return 0;
//     // }
//     char data=p->data[p->top];
//     p->top--;
//     return data;//符号出栈
// }
// int is_num(char c)
// {
//     if(c>='0'&&c<='9')
//     {
//         return 1;
//     }
//     return 0;
// }
// char get_op_top(task_op* p){
//     if(p==NULL)
//     {
//         printf("空栈\n");
//         return 0;
//     }
//     // if(p->top==-1)
//     // {
//     //     printf("栈已空\n");
//     //     return 0;
//     // }
//     return p->data[p->top];
// }
// int get_op_priority(char c)//获取运算符优先级
// {
//     switch (c)
//     {
//     case '+':
//     case '-':
//         return 1;
//     case '*':
//     case '/':
//         return 2;
//     default:
//         return 0;
//     }
// }
// double calculate1(double a,char c,double b)//单次计算
// {
//     switch (c)
//     {
//     case '+':
//         return a+b;
//     case '-':
//         return a-b;
//     case '*':
//         return a*b;
//     case '/':
//     if(b==0)
//     {
//         printf("除数不能为0");
//         return 0;
//     }
//         return a/b;
//     default:
//         return 0;
//     }
// }
// double calculate(char* str)
// {
//     task_num* p_num=init_stack_num();
//     task_op* p_op=init_stack_op();
//     int i=0;
//     while(str[i]!='\0')
//     {
//         if(is_num(str[i])|| str[i]=='.')
//         {
//             double num=0;
//             double point=0.1;
//             int flag=0;//小数点标志
//             while(is_num(str[i])|| str[i]=='.')
//             {
//                 if(str[i]=='.')
//                 {
//                     flag=1;
//                     i++;
//                     continue;
//                 }
//                 if(flag==0)
//                 {
//                     num=num*10+str[i]-'0';
//                 }
//                 else
//                 {
//                     num=num+point*(str[i]-'0');
//                     point*=0.1;
//                 }
//             i++;
//         }
//         push_num(p_num,num);
//         }
//         else if(str[i]=='(')
//         {
//             push_op(p_op,str[i]);
//             i++;
//         }
//         else if(str[i]==')')
//         {
//             while(get_op_top(p_op)!='(')
//             {
//                 char op=pop_op(p_op);
//                 double b=pop_num(p_num);
//                 double a=pop_num(p_num);
//                 double ret=calculate1(a,op,b);
//                 push_num(p_num,ret);
//             }
//             pop_op(p_op);
//             i++;
//         }
//         else
//         {
//             while(get_op_top(p_op)!='('&&
//             get_op_priority(str[i])<=get_op_priority(get_op_top(p_op)))
//             {
//                 char op=pop_op(p_op);
//                 double b=pop_num(p_num);
//                 double a=pop_num(p_num);
//                 double ret=calculate1(a,op,b);
//                 push_num(p_num,ret);
//             }
//             push_op(p_op,str[i]);
//             i++;
//         }
// }
//     while(p_op->top!=-1)
//     {
//     char op=pop_op(p_op);
//     double b=pop_num(p_num);
//     double a=pop_num(p_num);
//     double ret=calculate1(a,op,b);
//     push_num(p_num,ret);
//     }
// return pop_num(p_num);
// }
// // int main(){
// //     char str[datasize];
// //     scanf("%s",str);
// //     double ret=calculate(str);
// //     printf("%lf",ret);
// //     return 0;
// // }