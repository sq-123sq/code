#include "students.h"
//typedef int ss;
//typedef struct headnode {
//	ss date;
//	struct headnode* prv;
//	struct headnode* next;
//}hd;
////初始化双向链表
//hd* inithd() {
//	hd* p = (hd*)malloc(sizeof(hd));
//	if (p == NULL) {
//		perror("inithd");
//		return NULL;
//	}
//	p->date = 0;
//	p->next = NULL;
//	p->prv = NULL;
//	return p;
//}
////头插法
//void inserthead(hd* p,ss k) {
//	hd* ps = inithd();
//	/*ss c = 0;
//	printf("输入一个整数\n");
//	scanf("%d", &c);
//	ps->date = c;*/
//	ps->date = k;
//	ps->prv = p;
//	ps->next = p->next;
//	if(p->next!=NULL)
//	p->next->prv = ps;
//	p->next = ps;
//}
////遍历
//void showhd(hd* p) {
//	hd* ps = p->next;
//	while (ps != NULL) {
//		printf("%d", ps->date);
//		ps = ps->next;
//	}
//	printf("\n");
//}
////尾插法
//void inserttail(hd* p,ss k) {
//	hd* pr = p;
//	while (pr->next != NULL) {
//		pr = pr->next;
//	}
//	hd* ps = inithd();
//	ps->date = k;
//	ps->prv = pr;
//	pr->next = ps;
//	ps->next = NULL;
//}
////插入数据
//void insertdata(hd* p,ss k,int pos) {
//	hd* ps = p;
//	for (int i = 0; i < pos - 1; i++) {
//		ps = ps->next;
//		if (ps == NULL)return;
//	}
//	hd* pt = inithd();
//	pt->date = k;
//	pt->prv = ps;
//	pt->next = ps->next;
//	ps->next = pt;
//	if(ps->next!=NULL)
//	ps->next->prv = pt;
//}
////删除数据
//void delhd(hd* p,int pos) {
//	hd* ps = p;
//	for (int i = 0; i < pos - 1; i++) {
//		ps = ps->next;
//		if (ps == NULL)return;
//	}
//	hd* pt = ps->next;
//	ps->next = pt->next;
//	pt->next->prv = ps;
//	free(pt);
//}
////获取链表长度
//int lenhd(hd* p) {
//	hd* ps = p;
//	int len = 0;
//	while (ps != NULL) {
//		ps = ps->next;
//		len++;
//	}
//	return len;
//}
////释放链表
//void cleanhd(hd* p) {
//	hd* ps = p->next;
//	hd* pt = NULL;
//	while (ps != NULL) {
//		ps->next=pt;
//		free(ps);
//		ps = pt;
//	}
//	p->next = ps;
//	printf("释放成功\n");
//}
//int main() {
//	hd* qw = inithd();
//	/*inserthead(qw,10);
//	inserthead(qw, 20);
//	inserthead(qw, 30);*/
//	inserttail(qw, 10);
//	inserttail(qw, 20);
//	inserttail(qw, 30);
//	showhd(qw);
//	insertdata(qw, 40, 2);
//	showhd(qw);
//	delhd(qw,2);
//	showhd(qw);
//	int len = lenhd(qw);
//	printf("%d\n", len);
//	cleanhd(qw);
//	return 0;
//}
//栈的静态存储
//#define MAXSIZE 100
//typedef int anytype;
//typedef struct stack {
//	int top;//用来表示栈顶
//	anytype data[MAXSIZE];//用数组存储数据
//}S;
////初始化栈
//void initstack(S* p) {
//	//for (int i = 0; i < MAXSIZE ; i++) {
//	//	p->data[i] = 0;//数组都初始化为0
//	//}
//	memset(p->data, 0, sizeof(p->data));
//	p->top = -1;//让top表示数组的下标，为-1表示为空栈
//}
////判断栈内存的情况
//void isemptystack(S* p) {
//	if (p->top == -1) {
//		printf("为空栈\n");
//		return;
//	}
//	else if (p->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return;
//	}
//}
////入栈
//void insertstack(S* p) {
//	if (p->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return;
//	}
//	anytype c = 0;
//	printf("请输入数据\n");
//	scanf("%d", &c);
//	p->top++;
//	p->data[p->top] = c;
//}
////出栈
//void delstack(S* p) {
//	if (p->top == -1) {
//		printf("为空栈\n");
//		return;
//	}
//	//p->data[p->top] = 0;可有可无
//	p->top--;
//}
////遍历
//void showstack(S* p) {
//	if (p->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return;
//	}
//	for (int i = 0; i <=p->top; i++) {
//		printf("%d ", p->data[i]);
//	}
//	printf("\n");
//}
//int main() {
//	S qw;
//	initstack(&qw);
//	isemptystack(&qw);
//	insertstack(&qw);
//	insertstack(&qw);
//	insertstack(&qw);
//	printf("%d\n", qw.data[qw.top]);//获取栈顶元素
//	showstack(&qw);
//	delstack(&qw);
//	showstack(&qw);
//	return 0;
//}
//typedef int anytype;
//typedef struct stack1 {
//	anytype data;
//	struct stack1* next;
//}S;
////栈(链表)的初始化最好返回指针
//S* initstack1() {
//	S* p = (S*)malloc(sizeof(S));//头指针
//	if (p == NULL) {
//		perror("initstack1");
//		return;
//	}
//	p->data = 0;
//	p->next = NULL;
//	return p;
//}
////入栈即头插法
//void insertstack1(S* p) {
//	/*if (p->next == NULL) {
//		printf("为空栈\n");
//		return;
//	}*/
//	S*  ps = p;
//	S* pt = (S*)malloc(sizeof(S));
//	if (pt == NULL) {
//		perror("insertstack1");
//		return;
//	}
//	printf("请输入数据\n");
//	scanf("%d", &(pt->data));
//	pt->next = ps->next;
//	ps->next = pt;
//
//}
////出栈
//void delstack1(S* p) {
//	if (p->next == NULL) {
//		printf("为空栈\n");
//		return;
//	}
//	S* ps = p->next;
//	p->next = ps->next;
//	free(ps);
//}
////遍历
//void showstack1(S* p) {
//	S* ps = p->next;
//	if (ps == NULL) {
//		printf("为空栈\n");
//		return;
//	}
//	while (ps != NULL) {
//		printf("%d ", ps->data);
//		ps = ps->next;
//	}
//	printf("\n");
//}
//int main() {
//	S* qw = initstack1();
//	insertstack1(qw);
//	insertstack1(qw);
//	insertstack1(qw);
//	showstack1(qw);
//	delstack1(qw);
//	showstack1(qw);
//	return 0;
//}
//
//typedef int anytype;
//typedef struct queuenode {
//	anytype data;
//	struct queuenode* next;
//}QN;
//typedef struct queue {
//	QN* front;//QN的结构体指针表示队头
//	QN* rear;
//}Q;
////初始化
//Q* initqueue() {
//	QN* p = (QN*)malloc(sizeof(QN));
//	Q* ps = (Q*)malloc(sizeof(Q));
//	if (p == NULL) {
//		perror("initqueue");
//		return NULL;
//	}
//	if (ps == NULL) {
//		perror("initqueue");
//		return NULL;
//	}
//	p->data = 0;
//	p->next = NULL;
//	ps->front = p;
//	ps->rear = p;
//	return ps;
//}
////入队即尾插法
//Q* insertqueue(Q* p) {
//	QN* ps = (QN*)malloc(sizeof(QN));
//	if (ps == NULL) {
//		perror("insertqueue");
//		return;
//	}
//	printf("请输入数据\n");
//	scanf("%d", &(ps->data));
//	p->rear->next = ps;
//	ps->next = NULL;
//	p->rear = ps;
//	return p;
//}
////出队
//void delqueue(Q* p) {
//	if (p->front == p->rear) {
//		printf("空队列\n");
//		return;
//	}
//	QN* ps = p->front->next;
//	p->front->next = ps->next;
//	if (p->rear == ps) {
//		p->rear = p->front;
//	}
//	free(ps);
//}
////遍历
//void showqueue(Q* p) {
//	QN* ps = p->front->next;
//	while (ps != NULL) {
//		printf("%d ", ps->data);
//		ps = ps->next;
//	}
//	printf("\n");
//}
//int main() {
//	Q* p = initqueue();
//	p=insertqueue(p);
//	p=insertqueue(p);
//	p=insertqueue(p);
//	showqueue(p);
//	delqueue(p);
//	showqueue(p);
//	return 0;
//}
//循环队列
//#define MAXSIZE 10
//typedef struct queue {
//	int data[MAXSIZE];
//	int front;
//	int rear;
//}Q;
//void initqueue(Q* p) {
//	p->front = 0;
//	p->rear = 0;
//	memset(p->data, 0, sizeof(p->data));
//}
////入队
//void insertqueue(Q* p) {
//	if ((p->rear + 1) % MAXSIZE == p->front) {
//		printf("满了\n");
//		return;
//	}
//	printf("请输入数据\n");
//	scanf("%d", &(p->data[p->rear]));
//	p->rear = (p->rear + 1) % MAXSIZE;
//}
////出队
//void delqueue(Q* p) {
//	if (p->rear  == p->front) {
//		printf("空的\n");
//		return;
//	}
//	//int a = p->data[p->front];
//	p->front = (p->front + 1) % MAXSIZE;
//}
//void showqueue(Q* p) {
//	for (int i = p->front; i <p->rear; i=(i+1)%MAXSIZE) {//循环队列的遍历
//		printf("%d ", p->data[i]);
//	}
//	printf("\n");
//}
//int main() {
//	Q qw;
//	initqueue(&qw);
//	insertqueue(&qw);
//	insertqueue(&qw);
//	insertqueue(&qw);
//	showqueue(&qw);
//	delqueue(&qw);
//	showqueue(&qw);
//	return 0;
//}
//void menu() {
//	printf("**************学生信息管理系统**************\n");
//	printf("*****1.添加学生信息**2.删除学生信息*********\n");
//	printf("*****3.更改学生信息**4.查找学生信息*********\n");
//	printf("*****5.学生信息排序**6.显示所有学生信息*****\n");
//	printf("**************0.退出管理系统****************\n");
//	printf("********************************************\n");
//}
//int main() {
//	SN* qw = initstudents();
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入选项\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			addstudents(qw);
//			break;
//		case 2:
//			delstudents(qw);
//			break;
//		case 3:
//			changestudents(qw);
//			break;
//		case 4:
//			findstudents(qw);
//			break;
//		case 5:
//			qsortstudents(qw);
//			break;
//		case 6:
//			showstudents(qw);
//			break;
//		case 0:
//			printf("退出管理系统\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//typedef char anytype;
//typedef struct treenode {
//	anytype data;
//	struct treenode* lchild;//左节点
//	struct treenode* rchild;//右节点
//}TN;
//typedef TN* bittree;
//char str[] = "ashdw##sdw#sdfew";
//int i = 0;
////前序遍历
//void preorder(bittree t) {
//	if (t == NULL) {
//		return;
//	}
//	printf("%c", t->data);
//	preorder(t->lchild);//递归，先执行左节点再执行右节点，类似入栈和出栈，一定要先入栈再出栈
//	preorder(t->rchild);
//}
////创建树
//void creattree(bittree* t) {
//	anytype ch;
//	ch = str[i++];
//	if (ch == '#') {
//		*t = NULL;
//	}
//	else {
//		*t = (TN*)malloc(sizeof(TN));
//		(*t)->data = ch;
//		creattree(&(*t)->lchild);//递归
//		creattree(&(*t)->rchild);
//	}
//}
////中序遍历
//void inorder(bittree t) {
//	if (t == NULL) {
//		return;
//	}
//	inorder(t->lchild);//递归，从左往右执行，类似入栈和出栈，一定要先入栈再出栈
//	printf("%c", t->data);
//	inorder(t->rchild);
//}
////后序遍历
//void afterorder(bittree t) {
//	if (t == NULL) {
//		return;
//	}
//	afterorder(t->lchild);//递归，从左往右执行，类似入栈和出栈，一定要先入栈再出栈
//	afterorder(t->rchild);
//	printf("%c", t->data);
//}
//typedef int anytype;
//typedef struct bittree {
//	anytype data;
//	struct bittree* lchild;
//	struct bittree* rchild;
//}bit;
//typedef bit* bit1;
////查找
//int findtreenode(bit1 t,int a,bit1 parent,bit1 *pos) {
//	if (t == NULL) {
//		*pos = parent;//parent指传入的树的父节点
//		return 0;
//	}
//	if (t->data == a) {
//		*pos = t;
//		return 1;
//	}
//	if (t->data > a) {
//		return findtreenode(t->lchild, a, t, pos);
//	}
//	else {
//		return findtreenode(t->rchild, a, t, pos);
//	}
//}
////插入
//int inserttreenode(bit1* t, int a) {
//	bit1 parent, pos;
//	int b = findtreenode(*t, a, NULL, &pos);
//	if (b == 0) {
//		bit1 arr = (bit1)malloc(sizeof(bit));
//		arr->data = a;
//		arr->lchild = NULL;
//		arr->rchild = NULL;
//		if (pos == NULL) {
//			*t = arr;
//		}
//		else {
//			if (a < pos->data) {
//				pos->lchild = arr;
//			}
//			else if (a > pos->data) {
//				pos->rchild = arr;
//			}
//			return 0;
//		}
//	}
//	return 1;
//}
////删除有3种情况
//int delede(bit1* t) {
//	bit1 tmp, crr;
//	if ((*t)->lchild == NULL) {//树根的左孩子为空,树根是找到的那个数据的节点
//		tmp = *t;
//		*t = (*t)->rchild;
//		free(tmp);
//	}if ((*t)->rchild == NULL) {//树根的右孩子为空
//		tmp = *t;
//		*t = (*t)->lchild;
//		free(tmp);
//	}
//	else {//树根左右都不为空，这是往左寻找也可以往右
//		tmp = *t;
//		crr = (*t)->lchild;
//		while (crr->rchild != NULL) {
//			tmp = crr;
//			crr = crr->rchild;
//		}
//		(*t)->data = crr->data;
//		if (tmp != *t) {
//			tmp->rchild = crr->lchild;
//		}
//		else {
//			tmp->lchild = crr->lchild;
//		}
//		free(crr);
//	}
//	return 1;
//}
////删除数据
//int deltreenode(bit1* t,int a) {
//	if (*t == NULL) {
//		printf("为空\n");
//		return 0;
//	}
//	if ((*t)->data == a) {
//		return delede(t);//如果数据相同则跳到删除函数
//	}
//	if ((*t)->data > a) {
//		return deltreenode(&((*t)->lchild), a);//数据不同则递归继续寻找
//	}
//	else if ((*t)->data < a) {
//		return deltreenode(&((*t)->rchild), a);
//	}
//}
////前序遍历
//void perorder(bit1 t) {
//	if (t == NULL) {
//		return;
//	}
//	printf("%d ", t->data);
//	perorder(t->lchild);
//	perorder(t->rchild);
//}
//void inorder(bit1 t) {
//	if (t == NULL) {
//		return;
//	}
//	inorder(t->lchild);
//	printf("%d ", t->data);
//	inorder(t->rchild);
//}
//void afterorder(bit1 t) {
//	if (t == NULL) {
//		return;
//	}
//	afterorder(t->lchild);
//	afterorder(t->rchild);
//	printf("%d ", t->data);
//}
//int main() {
//	bit1 root = NULL;//初始化
//	int arr[] = { 67,45,34,23,90,45,12 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (int i = 0; i < sz; i++) {
//		inserttreenode(&root, arr[i]);
//	}
//	perorder(root);
//	return 0;
//}
//int main() {
//	int arr[] = { 12,23,34,12,45,56 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (int i = 0; i < sz; i++) {
//		for (int j = 0; j < sz - i - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//typedef struct arrs {
//	int data;
//	struct arrs* next;
//}node;
//node* inits() {
//	node* p = (node*)malloc(sizeof(node));
//	if (p == NULL) {
//		perror("inits");
//		return NULL;
//	}
//	p->data = 0;
//	p->next = NULL;
//	return p;
//}
//int addnode(node* p) {
//	node* ps = p->next;
//	int sum = 0;
//	while (ps != NULL) {
//		sum = sum + (ps->data);
//		ps = ps->next;
//	}
//	return sum;
//}
//void insertnode(node* p, int a) {
//	node* pt = inits();
//	pt->data=a;
//	pt->next = p->next;
//	p->next = pt;
//}
//int main() {
//	int n = 0;
//	printf("请输入一个正整数n\n");
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int)*n);
//	if (arr == NULL) {
//		perror("数组错误\n");
//	}
//	printf("请输入n个正整数数字\n");
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	node* ps = inits();
//	for (int i = 0; i < n; i++) {
//		insertnode(ps, arr[i]);
//	}
//	int sum = addnode(ps);
//	printf("%d", sum);
//	free(arr);
//	return 0;
//}
int cal(int* p, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + (*(p + i));
	}
	return sum;
}
void sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main() {
	/*int arr[6] = { 0 };
	printf("请输入6个整数\n");
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
	}
	int* p = arr;
	for (int i = 0; i < 6; i++) {
		printf("%d ", *(p + i));
	}*/
	/*int n = 0;
	printf("请输入一个正整数n\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	if (arr == NULL) {
		perror("数组错误");
	}
	printf("请输入n个正整数\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int* p = arr;
	int sum = cal(p,n);
	printf("%d", sum);
	free(arr);*/
	/*int n = 0;
	printf("请输入一个正整数n\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	if (arr == NULL) {
		perror("数组错误");
	}
	printf("请输入n个正整数\n");
	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}
	sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);*/
	return 0;
}