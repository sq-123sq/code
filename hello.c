// #include <stdio.h>
// #include <stdlib.h>
// typedef char datatype;
// typedef struct seektree{
//     datatype data;
//     struct seektree *lchild;
//     struct seektree *rchild;
// }seektree;
// seektree* seektree_inits(datatype data){
//     seektree *root = (seektree*)malloc(sizeof(seektree));
//     root->data = data;
//     root->lchild = NULL;
//     root->rchild = NULL;
//     return root;
// }
// void seektree_insert(seektree** root,datatype data){
//     if(*root == NULL){
//         *root=seektree_inits(data);
//         return;
//     }
//     if(data < (*root)->data){
//         seektree_insert(&(*root)->lchild,data);
//     }
//     else{      
//         seektree_insert(&(*root)->rchild,data);
//     }
// }
// void seektree_print(seektree* root){
//     if(root == NULL){
//         return;
//     }
//     seektree_print(root->lchild);
//     seektree_print(root->rchild);
//     printf("%c ",root->data);   
// }
// seektree* findminnode(seektree* root){
//     if(root == NULL){
//         return NULL;
//     }
//     while (root->lchild != NULL)
//     {
//         root = root->lchild;
//     }
//     return root;
// }
// void search_data(seektree* root,datatype a){
//     if(root == NULL){
//         printf("没找到\n");
//         return;
//     }
//     if(a == root->data){
//         printf("找到了\n");
//         return;
//     }
//     else if(a < root->data){
//         search_data(root->lchild,a);
//     }
//     else{
//         search_data(root->rchild,a);
//     }
// }
// void find_data(seektree* root){
//     int a=0;
//     printf("\n请输入要查找的数据\n");
//     scanf("%d",&a);
//     search_data(root,a);
// }
// void seektree_delete(seektree** root,datatype data){
//     if(*root == NULL){
//         return;
//     }
//     if(data < (*root)->data){
//         seektree_delete(&(*root)->lchild,data);
//     }
//     else if(data > (*root)->data){
//         seektree_delete(&(*root)->rchild,data);
//     }
//     else{
//         // 1. 左右孩子都有 → 找右子树最小节点替换，再删最小节点
//         if((*root)->lchild != NULL && (*root)->rchild != NULL){
//             seektree* minnode = findminnode((*root)->rchild);
//             (*root)->data = minnode->data;
//             seektree_delete(&(*root)->rchild,(*root)->data);
//         }
//         // 2. 只有左孩子 → 直接把左孩子提上来
//         else if((*root)->lchild != NULL){
//             *root = (*root)->lchild;
//         }
//         // 3. 只有右孩子 → 直接把右孩子提上来
//         else if((*root)->rchild != NULL){
//             *root = (*root)->rchild;
//         }
//         // 4. 叶子节点 → 直接释放
//         else{
//             free(*root);
//             *root = NULL;
//         }
//     }
// }
// void delete_gooddata(seektree** root){
//     if(*root == NULL){
//         return;
//     }
//     if((*root)->data=='#'){
//         seektree_delete(root,(*root)->data);
//     }else{
//         delete_gooddata(&(*root)->lchild);
//         delete_gooddata(&(*root)->rchild);
//     }
// }
// // int main() {
//     // seektree* root = NULL;
//     // int* arr=(int*)malloc(sizeof(int)*10);
//     // if(arr == NULL){
//     //     printf("malloc error");
//     //     return 1;
//     // }
//     // printf("请输入数据\n");
//     // for(int i=0;i<10;i++){
//     //     scanf("%d",&arr[i]);
//     // }
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     seektree_insert(&root,arr[i]);
//     // }
//     // seektree_print(root);
//     // seektree_delete(&root,3);
//     // printf("\n删除后\n");
//     // seektree_print(root);
//     // find_data(root);
//     // seektree* root = NULL;
//     // char arr[100];
//     // printf("请输入字符串\n");
//     // scanf("%s",arr);
//     // for(int i=0;arr[i]!='\0';i++){
//     //     seektree_insert(&root,arr[i]);
//     // }
//     // seektree_print(root);
//     // delete_gooddata(&root);
//     // printf("\n删除后\n");
//     // seektree_print(root);
// //     return 0;
// // }
// typedef struct queue{
//     int data;
//     struct queue* next;
// }queue;
// queue* create_queue(){
//     queue* head = (queue*)malloc(sizeof(queue));
//     head->next = NULL;
//     return head;
// }
// //入队
// void push(queue* head,int data){
//     queue* new = (queue*)malloc(sizeof(queue));
//     new->data = data;
//     new->next = NULL;
//     queue* p = head;
//     while(p->next != NULL){
//         p = p->next;
//     }
//     p->next = new;
// }
// //出队
// void pop(queue* head){
//     queue* p = head->next;
//     head->next = p->next;
//     free(p);
// }
// //找到队头
// int front(queue* head){
//     return head->next->data;
// }
// void print_queue(queue* head){
//     queue* p = head->next;
//     while(p != NULL){
//         printf("%d ",p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
// // int main(){
// //     queue* q = create_queue();
// //     push(q,1);
// //     push(q,2);
// //     push(q,3);
// //     print_queue(q);
// //     pop(q);
// //     print_queue(q);
// //     printf("%d\n",front(q));
// //     return 0;
// // }