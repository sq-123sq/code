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



// int main()
// {
//     int* str=(int*)malloc(sizeof(int)*30);
//     if(str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<6;i++){
//         scanf("%d",&str[i]);
//     }
//     for(int i=0;i<6;i++){
//         printf("%d ",str[i]);
//     }
//     free(str);
//     str=NULL;
//     return 0;
// }


// #define n 16
// #define row 4
// #define col 3
// int main(){
//     int* str=(int*)malloc(sizeof(char)*100);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<n;i++){
//         scanf("%d",&str[i]);
//     }
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-1-i;j++){
//             if(str[j]>str[j+1]){
//                 int temp=str[j];
//                 str[j]=str[j+1];
//                 str[j+1]=temp;
//             }
//         }
//     }
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             printf("%d ",str[i*col+j]);
//         }
//         printf("\n");
//     }
//     free(str);
//     str=NULL;
//     return 0;
// }


// int cal(int* str,int a){
//     int sum=0;
//     for(int i=0;i<a;i++){
//         sum+=str[i];
//     }
//     return sum;
// }
// int main(){
//     int a=0;
//     scanf("%d",&a);
//     int* str=(int*)malloc(sizeof(int)*a);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<a;i++){
//         scanf("%d",&str[i]);
//     }
//     int sum=cal(str,a);
//     printf("%d",sum);
//     free(str);
//     str=NULL;
//     return 0;
// }

// void sort(int* str,int a){
//     for(int i=0;i<a-1;i++){
//         for(int j=0;j<a-1-i;j++){
//             if(str[j]>str[j+1]){
//                 int temp=str[j];
//                 str[j]=str[j+1];
//                 str[j+1]=temp;
//             }
//         }
//     }
// }
// int main(){
//     int a=0;
//     scanf("%d",&a);
//     int* str=(int*)malloc(sizeof(int)*a);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<a;i++){
//         scanf("%d",&str[i]);
//     }
//     sort(str,a);
//     for(int i=0;i<a;i++){
//         printf("%d ",str[i]);
//     }
//     return 0;
// }


// typedef struct node{
//     int data;
//     struct node* next;
// }node;
// node* creatnode_niu(){
//     node* newnode=(node*)malloc(sizeof(node));
//     if(newnode==NULL){
//         perror("malloc error");
//         return NULL;
//     }
//     newnode->data=0;
//     newnode->next=NULL;
//     return newnode;
// }
// void insert_niu(node* head,int data){
//     node* ps=head;
//     while(ps->next!=NULL){
//         ps=ps->next;
//     }
//     node* tail=ps;
//     node* newnode=creatnode_niu();
//     newnode->data=data;
//     tail->next=newnode;
// }
// void print_niu(node* head){
//     node* ps=head->next;
//     while(ps!=NULL){
//         printf("%d ",ps->data);
//         ps=ps->next;
//     }
// }
// int main(){
//     int a=0;
//     scanf("%d",&a);
//     node* head=creatnode_niu();
//     int *str=(int*)malloc(sizeof(int)*a);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<a;i++){
//         scanf("%d",&str[i]);
//     }
//     for(int i=0;i<a;i++){
//         insert_niu(head,str[i]);
//     }
//     print_niu(head);
//     return 0;
// }



typedef struct node{
    int data;
    struct node* next;
}node;
node* creatnode_niu(){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        perror("malloc error");
        return NULL;
    }
    newnode->data=0;
    newnode->next=NULL;
    return newnode;
}
void insert_niu(node* head,int data){
    node* ps=head;
    while(ps->next!=NULL){
        ps=ps->next;
    }
    node* tail=ps;
    node* newnode=creatnode_niu();
    newnode->data=data;
    tail->next=newnode;
}
void print_niu(node* head){
    node* ps=head->next;
    while(ps!=NULL){
        printf("%d ",ps->data);
        ps=ps->next;
    }
}
int length_niu(node* head){
    node* ps=head->next;
    int count=0;
    while(ps!=NULL)
    {
        count++;
        ps=ps->next;
    }
    return count;
}
void swap(node* a,node* b)
{
    if(a==NULL||b==NULL){
        return;
    }
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
void change_niu(node* head)
{
    node* ps=head->next;
    node* pre_tail=head->next;
    int length=length_niu(head);
    if(length>=2){//链表长度大于等于2，交换前两个节点
        swap(ps,ps->next);
    }
    if(length>=2){//链表长度大于等于2，交换最后一个节点和倒数第二个节点
        while(pre_tail->next->next!=NULL){
            pre_tail=pre_tail->next;
    }
    swap(pre_tail,pre_tail->next);
    }
}
void sum_niu(node* head){
    node* ps=head->next;
    int sum=0;
    while(ps!=NULL){
        sum+=ps->data;
        ps=ps->next;
    }
    printf("%d\n",sum);
}
// int main(){
//     int a=0;
//     scanf("%d",&a);
//     node* head=creatnode_niu();
//     int* str=(int*)malloc(sizeof(int)*a);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<a;i++){
//         scanf("%d",&str[i]);
//     }
//     for(int i=0;i<a;i++){
//         insert_niu(head,str[i]);
//     }
//     change_niu(head);
//     print_niu(head);
//     free(str);
//     str=NULL;
//     return 0;
// }



// int main(){
//     int a=0;
//     scanf("%d",&a);
//     node* head=creatnode_niu();
//     int *str=(int*)malloc(sizeof(int)*a);
//     if (str==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     for(int i=0;i<a;i++){
//         scanf("%d",&str[i]);
//     }
//     for(int i=0;i<a;i++){
//         insert_niu(head,str[i]);
//     }
//     sum_niu(head);
//     free(str);
//     str=NULL;
//     return 0;
// }

void stdin_niu(int* arr,int a)
{
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
}
void arr_to_node_niu(node* head,int* arr,int a)
{
    for(int i=0;i<a;i++){
        insert_niu(head,arr[i]);
    }
}
node* node_to_node_niu(node* head1,node* head2)
{
    node* ps1=head1->next;
    node* ps2=head2->next;
    node* newnode=creatnode_niu();
    while(ps1!=NULL&&ps2!=NULL){
        insert_niu(newnode,ps1->data+ps2->data);
        ps1=ps1->next;
        ps2=ps2->next;
    }
    return newnode;
}
// int main(){
//     int n;
//     scanf("%d",&n);
//     node* head1=creatnode_niu();
//     node* head2=creatnode_niu();
//     int* str1=(int*)malloc(sizeof(int)*n);
//     int* str2=(int*)malloc(sizeof(int)*n);
//     if (str1==NULL||str2==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     stdin_niu(str1,n);
//     stdin_niu(str2,n);
//     arr_to_node_niu(head1,str1,n);
//     arr_to_node_niu(head2,str2,n);
//     node* head=node_to_node_niu(head1,head2);
//     print_niu(head);
//     return 0;
// }


void delate_node_niu(node* head,int x)
{
    node* ps=head->next;
    node* pre=head;
    while(ps!=NULL){
        if(ps->data==x){
            pre->next=ps->next;
            free(ps);
            ps=pre->next;
        }
        else{
            pre=ps;
            ps=ps->next;
        }
    }
}
// int main(){
//     int n,x;
//     scanf("%d %d",&n,&x);
//     node* head=creatnode_niu();
//     int* arr=(int*)malloc(sizeof(int)*n);
//     if (arr==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     stdin_niu(arr,n);
//     for(int i=0;i<n;i++){
//         insert_niu(head,arr[i]);
//     }
//     delate_node_niu(head,x);
//     print_niu(head);
// }

void add_node_niu(node* head,int i)
{
    node* pre=head;
    if(pre==NULL)
    return;
    for(int j=0;j<i;j++){
        pre=pre->next;
    }
    node* newnode=creatnode_niu();
    newnode->data=i;
    newnode->next=pre->next;
    pre->next=newnode;
}
// int main(){
//     int n,i;
//     scanf("%d %d",&n,&i);
//     node* head=creatnode_niu();
//     int *arr=(int*)malloc(sizeof(int)*n);
//     if (arr==NULL)
//     {
//         perror("malloc error");
//         return -1;
//     }
//     stdin_niu(arr,n);
//     arr_to_node_niu(head,arr,n);
//     add_node_niu(head,i);
//     print_niu(head);
// }