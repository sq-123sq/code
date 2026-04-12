#include "test.h"
//#define MAX 10
//int main() {
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	for (size_t i = 0; i < 10; i++)
//	{
//		p[i] = i;//这里的p就相当于*(p+i)其实也相当于一个首元素地址
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main() {
//	int n = 0;
//	int m = 0;
//	while (scanf("%d%d", &n, &m) == 2) {
//		int max = n > m ? n : m;
//		int min = n < m ? n : m;
//		int gld;
//		int lcm;
//		while (1) {
//			if (n%min == 0 && m%min == 0) {
//				gld = min;
//				break;
//			}
//			min--;
//		}
//		while (1) {
//			if (max%n == 0 && max%m == 0) {
//				lcm = max;
//				break;
//			}
//			max++;
//		}
//		//while (min!=0) {
//		//	int r = max % min;
//		//	max = min;
//		//	min=r;
//		//}
//		//gld = max;
//		//lcm = n * m / max;
//		printf("%d", gld + lcm);
//	}
//	return 0;
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
//				printf("* ");
//			}
//			else {
//				printf("  ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//struct jk {
//	int n;
//	int arr[];//柔性数组
//};
//int main() {
//	struct jk* ps = (struct jk*)malloc(sizeof(struct jk)+MAX*sizeof(int));//sizeof(struct jk)一定要加这是int n的内存
//	if (ps == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	ps->n = 90;
//	/*for (int i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", ps->arr[i]);
//	}*/
//	struct jk* ptr=(struct jk*)realloc(ps, sizeof(struct jk)+80);//扩容处理sizeof(struct jk)一定要加这是int n的内存
//	if (ptr == NULL) {
//		printf("%s\n", strerror(errno));
//		free(ps);
//		ps = NULL;
//		return 1;
//	}
//	ps=ptr;
//	for (int i = 0; i < 20; i++) {
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 20; i++) {
//		printf("%d ", ps->arr[i]);
//	}
//	free(ptr);
//	ptr = NULL;
//	ps = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//fputc("a", pf);
//	for (char i = 'a'; i < 'z'; i++) {
//		fputc(i, pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int c=0;
//	while ((c = fgetc(pf)) != EOF) {//fgetc判断用EOF
//		putchar(c);//打印单个字符%c也可以打印字符
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//fputs("zxcvsan", pf);
//	char c[10] = { 0 };
//	fgets(c, 10, pf);//fgets判断用null
//	printf("%s\n", c);//%s打印字符串
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//typedef struct peo {
//	char name[20];
//	int age;
//	float weight;
//}p;
//int main() {
//	p s = { "zhangsan",20,90.9f};
//	FILE* pf =fopen("test.txt", "w");
//	if (pf == NULL) {
//		perror("FILE");
//	}
//	fprintf(pf, "%s %d %f", s.name,s.age,s.weight);//打印日志
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	p s = { 0 };
//	FILE* ptf = fopen("test.txt", "r");
//	if (ptf == NULL) {
//		perror("FILE");
//	}
//	fscanf(ptf, "%s %d %f", s.name, &s.age, &s.weight);
//	printf("%s %d %f", s.name, s.age, s.weight);
//	fclose(ptf);
//	ptf = NULL;
//	return 0;
//}
//int main() {
//	p s = { "wangwu",22,89.9f };
//	char buf[20];
//    sprintf(buf, "%s %d %f", s.name, s.age, s.weight);//sprintf是将结构体数据以字符串的形式存到buf里然后打印就可以直接打印buf，这个库函数和文件没有一毛关系
//	printf("字符串%s\n", buf);
//	sscanf(buf,"%s %d %f", s.name, &s.age, &s.weight);//sscanf是将字符串buf搞到结构体数据中，是可以以结构体形式打印出来的，这个库函数和文件没有一毛关系
//	printf("结构体%s %d %f", s.name, s.age, s.weight);
//	return 0;
//}
//int main() {
//	char buf[20] = "asghdaj";
//	FILE* pf = fopen("test.txt", "wb");//二进制写入用wb
//	if (pf == NULL) {
//		perror("FILE");
//		return 1;
//	}
//	fwrite(buf, sizeof(buf), 1, pf);//二进制的写入，buf是一个指针，第二个是类型的大小，第三个是写入一个buf
//	printf("%s\n", buf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	char buf[20] = "asghdaj";
//	FILE* pf = fopen("test.txt", "rb");//二进制读出用rb
//	if (pf == NULL) {
//		perror("FILE");
//		return 1;
//	}
//	fread(buf, sizeof(buf), 1, pf);//二进制的读出，buf是一个指针，第二个是类型的大小，第三个是读的二进制个数fread的返回值就是那个个数如果返回个数相同则读到了那几个二进制
//	printf("%s\n", buf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//	}
//	fputs("fuck you !", pf);
//	fclose(pf);
//    pf = fopen("test.txt", "r");
//	fseek(pf, 2, SEEK_SET);//fseek是用于读文件的
//	int c = fgetc(pf);
//	putchar(c);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//#define SQUARE(x) ((x)*(x))//这里的所有括号都不能省，define的本质是替换不会进行计算并且define后面永远都没有;
//#define print(x) printf("this is "#x"=%d\n",x)//#x是保留原有字符的意思
//int main() {
//	int r = SQUARE(3);
//	printf("%d\n", r);
//	print(r);
//	return 0;
//}
//#define MAX 10
//int main() {
//#if 4==5//每一个#if或#ifdef或#ifndef都要有一个#endif结尾不能少，格式与if语句类似可以嵌套使用
//	printf("%d\n", MAX);
//#endif
//#ifdef MAX
//	printf("%d\n", MAX);
//#endif
//#ifndef MAX//#ifndef相当于#ifdef !MAX就类似等于0
//	printf("%d\n", MAX);
//#endif
//	return 0;
//}
//int main() {
//	int n = 0;
//	//打印箭头
//	while (scanf("%d",&n)==1) {
//		//打印上n行
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n - i; j++) {  //可以把数字带入进去然后把结果想象出来结果对了那就是这个计算式
//				printf("  ");
//			}
//			for (int j = 0; j <= i; j++) {
//				printf("*");
//			}
//			printf("\n");
//		}
//		//打印下n+1行
//		for (int i = 0; i < n + 1; i++) {
//			for (int j = 0; j < i; j++) {
//				printf("  ");
//			}
//			for (int j = 0; j < n + 1 - i; j++) {
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
typedef char str;
struct pfnode {
	str data;//数据
	struct pfnode* next;//指针
};//一个链表
typedef struct pfnode PD;
//void initlist(PD* p) {//单链表的静态初始化
//	p->data = 0;
//	p->next = NULL;
//}
PD* initnode() {//动态初始化返回类型为指针
	PD* pf = (PD*)malloc(sizeof(PD));
	if (pf == NULL) {
		perror("init");
		return NULL;
	}
	pf->data = 0;
	pf->next = NULL;
	return pf;
}
//头插法插入数据--无需特别返回值
void  insertnode(PD* s, str data) {
	PD* p = (PD*)malloc(sizeof(PD));
	if (p == NULL) {
		perror("insertnode");
		return;
	}
	p->data = data;//给数据
	p->next = s->next;//先让新开辟的PD的next指向头结点的next
	s->next = p;//然后再让头结点的next指向这个空间
}
//遍历
void shownode(PD* s) {
	PD* p = s->next;
	while (p!= NULL) {
		//printf("%d ", p->data);
		putchar(p->data);
		p = p->next;
	}
	printf("\n");
}
//找到尾节点
PD* gettail(PD* s) {
	PD* p = s;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
//尾插法--最好有返回值
PD* inserttail(PD* s,str data) {
	PD* p = (PD*)malloc(sizeof(PD));
	if (p == NULL) {
		perror("inserttail");
		return NULL;
	}
	p->data = data;
	s->next = p;
	p->next = NULL;
	return p;
}
//中间插入数据，这个可以替代头插和尾插函数
void insertdata(PD* s, int pos,str data) {
	PD* p = s;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return;
		}
	}
	PD* ps = (PD*)malloc(sizeof(PD));
	if (ps == NULL) {
		perror("insertdata");
		return;
	}
	ps->data = data;
	ps->next = p->next;
	p->next = ps;
}
//删除指定位置的数据
void deldata(PD* s, int pos) {
	PD* p = s;
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;
		if (p == NULL) {
			printf("数据为空无法删除\n");
			break;
		}
	}
	PD* ps = p->next;
	p->next = ps->next;
	free(ps);
	return;
}
//获取链表长度
int lendata(PD* s) {
	PD* p = s;
	int len=0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
//释放链表
void freedata(PD* s) {
	PD* p = s->next;
	PD* ps=NULL;
	while (p != NULL) {
		p->next = ps;
		free(p);
		p = ps;
	}
	s->next = p;
	printf("释放或清理成功\n");
}
//找到倒数第k个数据
void findlast(PD* s,int k) {
	PD* fast = s->next;
	PD* slow = s->next;
	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	printf("%d\n", slow->data);
}
//找到2个链表之间第一个相同的数据
void findsame(PD* a,PD* b) {
	PD* fast=a->next;
	PD* slow=b->next;
	int ma = lendata(fast);
	int mb = lendata(slow);
	int k = abs(ma - mb);
	if (ma > mb) {
		fast = a->next;
		slow = b->next;
	}
	else if (ma < mb) {
		fast = b->next;
		slow = a->next;
	}
	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}
	while (fast->data != slow->data) {
		fast = fast->next;
		slow = slow->next;
	}
	printf("%c\n", slow->data);
}
//添加数据
void adddata(PD* s) {
	PD* p = s;
	str c = 0;
	PD* ps = (PD*)malloc(sizeof(PD));
	if (ps == NULL) {
		perror("adddata");
		return;
	}
	printf("请输入字符\n");
	scanf("%c", &c);
	getchar();//吃掉空格让数据能存入链表中
	ps->data = c;
	ps->next = p->next;
	p->next = ps;
}
//反转链表
PD* reservedata(PD* s) {
	PD* fist = NULL;
	PD* second = s->next;
	PD* third;
	while (second != NULL) {
		third = second->next;
		second->next = fist;
		fist = second;
		second = third;

	}
	PD* new = initnode();
	new->next = fist;
	return new;
}
//删除中间数
void deldis(PD* s) {
	PD* slow = s;
	PD* fast = s->next;
	while (fast->next != NULL && fast != NULL) {//数据个数有奇数个和偶数个
		fast = fast->next->next;
		slow = slow->next;
	}
	PD* q = slow->next;
	slow->next = q->next;
	free(q);
}
//判断是否是循环链表
void findcycle(PD* s) {
	PD* fast = s;
	PD* slow = s;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			printf("有环\n");
			break;
		}
	}
}
//void delsame(PD* s) {
//
//}
int main() {
	//PD s;//已经给s开辟了空间无需malloc是静态的
	//initlist(&s);
	PD* s = initnode();//s是指向头节点的一个指针
	PD* q = initnode();
	/*insertnode(s, 30);
	insertnode(s, 40);
	insertnode(s, 50);*/
	//PD* tail = gettail(s);
	//tail=inserttail(tail, 30);
	//tail=inserttail(tail, 40);
	//tail=inserttail(tail, 50);
	//insertdata(s,4,10);
	//shownode(s);
	//deldata(s, 2);
	//shownode(s);
	//int len = lendata(s);
	//printf("%d\n", len);
	//findlast(s, 2);
	//shownode(s);
	PD* tail = gettail(s);
	//PD* tail1 = gettail(q);
	tail=inserttail(tail, 'l');
	tail=inserttail(tail, 'o');
	tail=inserttail(tail, 'a');
	PD* qq=initnode();//用一个新的节点等于该尾节点，后期再让之后的尾节点是该节点从而构成环
	qq->next = tail;
	tail=inserttail(tail, 'd');
	tail=inserttail(tail, 'i');
	tail=inserttail(tail, 'n');
	tail=inserttail(tail, 'g');
	tail->next=qq;
	findcycle(s);
	//tail1 = inserttail(tail1, 'b');
	//tail1 = inserttail(tail1, 'e');
	//tail1 = inserttail(tail1, 'i');
	//tail1 = inserttail(tail1, 'n');
	//tail1 = inserttail(tail1, 'g');
	//shownode(s);
	//shownode(q);
	//findsame(s, q);
	//adddata(s);
	//adddata(s);
	//adddata(s);
	//adddata(s);
	//adddata(s);
	//adddata(s);
	//shownode(s);
	//adddata(q);
	//adddata(q);
	//adddata(q);
	//shownode(q);
	//q=reservedata(q);
	//shownode(q);
	//deldis(q);
	//shownode(q);
	freedata(s);
	return 0;
}
//求7个数减去最大最小值的平均数
//int compare(const void* e1, const void* e2) {
//	return *(int*)e1 - *(int*)e2;
//}
//int main() {
//	int arr[7] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < 7; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 7; i++) {
//		sum += arr[i];
//	}
//	qsort(arr, 7, sizeof(arr[0]), compare);
//	sum = (sum - arr[0] - arr[6]) / 5;
//	printf("%d\n", sum);
//}
//void swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);//“”里面最好不要写逗号直接空格
//	printf("之前%d,%d\n", a, b);
//	swap(&a, &b);
//	printf("之后%d,%d\n", a, b);
//	return 0;
//}
//int main() {
//	for (int i = 0; i < 6; i++) {
//		for (int j = 0; j < 12; j++) {
//			if ((i == 0 || i == 1) && (j == 5 || j == 6)) {
//				printf("*");
//			}
//			else if (i == 2 || i == 3) {
//				printf("*");
//			}
//			else if ((i == 4 || i == 5) && (j == 4 || j == 7)) {
//				printf("*");
//			}
//			else {
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//void menu() {
//	printf("************图书管理系统*************\n");
//	printf("**1.添加*********2.查找**************\n");
//	printf("**3.删除*********4.更改**************\n");
//	printf("**5.排序*********6.图书信息**********\n");
//	printf("**7.插入图书*****0.退出管理程序******\n");
//	printf("*************************************\n");
//}
//int main() {
//	BL s;
//	init(&s);
//	int intput;
//	do
//	{   menu();
//		printf("请选择选项:");
//		scanf("%d", &intput);
//		switch (intput)
//		{
//		case 1:
//			addbook(&s);
//			break;
//		case 2:
//			findbook(&s);
//			break;
//		case 3:
//			delbook(&s);
//			break;
//		case 4:
//			changebook(&s);
//			break;
//		case 5:
//			qsortbook(&s);
//			break;
//		case 6:
//			showbook(&s);
//			break;
//		case 7:
//			insertbook(&s);
//			break;
//		case 0:
//			printf("退出程序\n");
//			cleanbook(&s);
//			break;
//		default:
//			printf("输入错误没有该选项，请重新选择\n");
//			break;
//		}
//	} while (intput);
//	return 0;
//}
//typedef struct node {
//	int data;
//	struct node* next;
//}N;
//N* initnode() {
//	N* ps = (N*)malloc(sizeof(N));
//	if (ps == NULL) {
//		perror("initnode");
//		return NULL;
//	}
//	ps->data = 0;
//	ps->next = NULL;
//}
//int main() {
//	N* p = initnode();
//	return 0;
//}
