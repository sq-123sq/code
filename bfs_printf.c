#include <stdio.h>
#include <stdlib.h>
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
int main(){
    treenode* root=creatnode(8);
    root->lchild=creatnode(6);
    root->rchild=creatnode(10);
    root->lchild->lchild=creatnode(5);
    root->lchild->rchild=creatnode(0);
    root->rchild->lchild=creatnode(3);
    root->rchild->rchild=creatnode(11);
    leve_order(root);
    free(root);
    return 0;
}