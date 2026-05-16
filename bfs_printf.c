#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode{
    int data;
    struct treenode *lchild,*rchild;
}treenode;
typedef struct qnode{
    treenode* val;
    struct qnode* next;
}qnode;
typedef struct queue{
    qnode* front;
    qnode* rear;
}queue;
treenode* creatnode(int data){
    treenode* newnode=(treenode*)malloc(sizeof(treenode));
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}
queue* creatqueue(){
    queue* newqueue=(queue*)malloc(sizeof(queue));
    newqueue->front=NULL;
    newqueue->rear=NULL;
    return newqueue;
}
void enqueue(queue* q,treenode* node){
    qnode* newnode=(qnode*)malloc(sizeof(qnode));
    newnode->val=node;
    newnode->next=NULL;
    if(q->rear==NULL){
        q->front=newnode;
        q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
treenode* dequeue(queue* q){
    if(q->front==NULL){
        return NULL;
    }
    else{
        qnode* temp=q->front;
        treenode* val=temp->val;
        q->front=q->front->next;
        if(q->front==NULL){
            q->rear=NULL;
        }
        free(temp);
        return val;
    }  
}
void leve_order(treenode* root){
    if(root==NULL){
        return;
    }
    queue* q=creatqueue();
    enqueue(q,root);
    while(q->front!=NULL){
        treenode* temp=dequeue(q);
        printf("%d ",temp->data);
        if(temp->lchild!=NULL){
            enqueue(q,temp->lchild);
        }
        if(temp->rchild!=NULL){
            enqueue(q,temp->rchild);
        }
    }
    printf("\n");
    free(q);
}
// int main(){
//     treenode* root=creatnode(8);
//     root->lchild=creatnode(6);
//     root->rchild=creatnode(10);
//     root->lchild->lchild=creatnode(5);
//     root->lchild->rchild=creatnode(0);
//     root->rchild->lchild=creatnode(3);
//     root->rchild->rchild=creatnode(11);
//     leve_order(root);
//     free(root);
//     return 0;
// }
// 
// 
// 
// int main(){
//     char* len=(char*)malloc(sizeof(char)*30);
//     char* newlen=(char*)malloc(sizeof(char)*30);
//     if(len==NULL||newlen==NULL){
//         perror("malloc error");
//         return -1;
//     }
//     fgets(len,30,stdin);
//     len[strcspn(len,"\n")]='\0';
//     int m=0;
//     scanf("%d",&m);
//     for(int i=0;i<strlen(len)+1-m;i++){
//         newlen[i]=len[m-1+i];
//     }
//     printf("%s\n",newlen);
//     free(len);
//     free(newlen);
//     len=NULL;
//     newlen=NULL;
//     return 0;
// }


// int main()
// {
//     char* str=(char*)malloc(sizeof(char)*100);
//     if(str==NULL){
//         return 1;
//     }
//     fgets(str,100,stdin);
// //    str[strcspn(str,"\n")]='\0';
//     printf("%d\n",strlen(str)-1);
//     free(str);
//     str=NULL;
//     return 0;
// }


// int main(){
//     char* str=(char*)malloc(sizeof(char)*100);
//     if(str==NULL)
//     return -1;
//     int i=1;
//     while (1)
//     {
//         printf("请输入字符串:");
//         scanf("%s",str);
//         if(strcmp(str,"exit")==0){
//             break;
//         }
//     }
//     printf("这里是第%d行，输入的字符串为:%s\n",i,str);
//     i++;
//     free(str);
//     str=NULL;
//     return 0;
// }

// void swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// {
//     int a=0,b=0;
//     scanf("%d%d",&a,&b);
//     printf("交换前:a=%d b=%d\n",a,b);
//     swap(&a,&b);
//     printf("交换后:a=%d b=%d\n",a,b);
//     return 0;
// }



int main()
{
    int* str=(int*)malloc(sizeof(int)*30);
    if(str==NULL)
    {
        perror("malloc error");
        return -1;
    }
    for(int i=0;i<6;i++){
        scanf("%d",&str[i]);
    }
    for(int i=0;i<6;i++){
        printf("%d ",str[i]);
    }
    free(str);
    str=NULL;
    return 0;
}