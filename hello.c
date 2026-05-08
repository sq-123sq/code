#include <stdio.h>
#include <stdlib.h>
typedef struct seektree{
    int data;
    struct seektree *lchild;
    struct seektree *rchild;
}seektree;
seektree* seektree_inits(int data){
    seektree *root = (seektree*)malloc(sizeof(seektree));
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}
void seektree_insert(seektree** root,int data){
    if(*root == NULL){
        *root=seektree_inits(data);
        return;
    }
    if(data < (*root)->data){
        seektree_insert(&(*root)->lchild,data);
    }
    else{      
        seektree_insert(&(*root)->rchild,data);
    }
}
void seektree_print(seektree* root){
    if(root == NULL){
        return;
    }
    seektree_print(root->lchild);
    printf("%d ",root->data);
    seektree_print(root->rchild);
}
seektree* findminnode(seektree* root){
    if(root == NULL){
        return NULL;
    }
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}
void search_data(seektree* root,int a){
    if(root == NULL){
        printf("没找到\n");
        return;
    }
    if(a == root->data){
        printf("找到了\n");
        return;
    }
    else if(a < root->data){
        search_data(root->lchild,a);
    }
    else{
        search_data(root->rchild,a);
    }
}
void find_data(seektree* root){
    int a=0;
    printf("\n请输入要查找的数据\n");
    scanf("%d",&a);
    search_data(root,a);
}
void seektree_delete(seektree** root,int data){
    if(*root == NULL){
        return;
    }
    if(data < (*root)->data){
        seektree_delete(&(*root)->lchild,data);
    }
    else if(data > (*root)->data){
        seektree_delete(&(*root)->rchild,data);
    }
    else{
        // 1. 左右孩子都有 → 找右子树最小节点替换，再删最小节点
        if((*root)->lchild != NULL && (*root)->rchild != NULL){
            seektree* minnode = findminnode((*root)->rchild);
            (*root)->data = minnode->data;
            seektree_delete(&(*root)->rchild,(*root)->data);
        }
        // 2. 只有左孩子 → 直接把左孩子提上来
        else if((*root)->lchild != NULL){
            *root = (*root)->lchild;
        }
        // 3. 只有右孩子 → 直接把右孩子提上来
        else if((*root)->rchild != NULL){
            *root = (*root)->rchild;
        }
        // 4. 叶子节点 → 直接释放
        else{
            free(*root);
            *root = NULL;
        }
    }
}
int main() {
    seektree* root = NULL;
    int* arr=(int*)malloc(sizeof(int)*10);
    if(arr == NULL){
        printf("malloc error");
        return 1;
    }
    printf("请输入数据\n");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        seektree_insert(&root,arr[i]);
    }
    seektree_print(root);
    seektree_delete(&root,3);
    printf("\n删除后\n");
    seektree_print(root);
    find_data(root);
    return 0;
}