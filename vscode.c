#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int data;
    struct stack *next;
}stack;
stack* inits_stack(){
    stack* head=(stack*)malloc(sizeof(stack));
    if(head==NULL){
        perror("inits_stack");
        return NULL;
    }
    head->data=0;
    head->next=NULL;
    return head;
}
void push(stack* head,int data){
    stack* new=inits_stack();
    new->data=data;
    new->next=head->next;
    head->next=new;
}
void pop(stack* head){
    if(head->next==NULL){
        perror("pop");
        return;
    }
    stack* temp=head->next;
    head->next=temp->next;
    free(temp);
}
int peek(stack* head){
    if(head->next==NULL){
        perror("peek");
        return -1;
    }
    return head->next->data;
}
int stack_min(stack* head){
    if(head->next==NULL){
        perror("stack_min");
        return -1;
    }
    stack* temp=head->next;
    int min=temp->data;
    while(temp!=NULL){
        if(temp->data<min){
            min=temp->data;
        }
        temp=temp->next;
    }
    return min;
}
void print_stack(stack* head){
    stack* temp=head->next;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    stack* head=inits_stack();
    printf("将元素压入栈中\n");
    push(head,1);
    push(head,2);
    push(head,3);
    print_stack(head);
    printf("删除栈顶元素\n");
    pop(head);
    print_stack(head);
    printf("栈顶元素为%d\n",peek(head));
    printf("栈中最小元素为%d\n",stack_min(head));
    return 0;
}
// int main(){
//     int a;
//     printf("请输入一个整数:");
//     scanf("%d",&a);
//     int* arr=(int*)malloc(sizeof(int)*a*a);
//     if (arr==NULL)
//     {
//        perror("malloc");
//        return 1;
//     }
//     for(int i=0;i<a*a;i++){
//         scanf("%d",&arr[i]);
//     }
//     for(int i=0;i<a;i++){
//         for(int j=i+1;j<a;j++){
//            int tmp=arr[i*a+j];
//            arr[i*a+j]=arr[i*a+j+i];
//            arr[i*a+j+i]=tmp;
//     }
// }
//     for(int i=0;i<a;i++){
//         for(int j=0;j<a;j++){
//             printf("%d ",arr[i*a+j]);
//         }
//         printf("\n");
//     }
//     free(arr);
//     return 0;
// }
// int main(){
//     int a=0;
//     printf("请输入矩阵的边长:");
//     scanf("%d",&a);
//     int* arr=(int*)malloc(sizeof(int)*a*a);
//     if (arr==NULL)
//     {
//         perror("malloc");
//         return 1;
//     }
//     printf("请输入%d*%d的矩阵\n",a,a);
//     for(int i=0;i<a;i++){
//         for(int j=0;j<a;j++){
//             scanf("%d",&arr[i*a+j]);
//         }
//     }
//     for(int i=0;i<a*a-1;i++){
//         for(int j=0;j<a*a-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int tmp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=tmp;
//         }
//     }
// }
//     printf("排序后的矩阵为:\n");
//     for(int i=0;i<a*a;i++){
//         printf("%d ",arr[i]);
//     }
//     free(arr);
//     arr=NULL;
//     return 0;
// }