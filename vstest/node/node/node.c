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
void menu() {
	printf("**************学生信息管理系统**************\n");
	printf("*****1.添加学生信息**2.删除学生信息*********\n");
	printf("*****3.更改学生信息**4.查找学生信息*********\n");
	printf("*****5.学生信息排序**6.显示所有学生信息*****\n");
	printf("**************0.退出管理系统****************\n");
	printf("********************************************\n");
}
int main() {
	SN* qw = initstudents();
	addstudents(qw);//1
	/*addstudents(qw);
	addstudents(qw);*/
	showstudents(qw);//6
	delstudents(qw);//2
	showstudents(qw);
	changestudents(qw);//3
	showstudents(qw);
	findstudents(qw);//5
	showstudents(qw);
	return 0;
}
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