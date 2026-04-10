#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
//struct pfnode {
//	int data;
//	struct pfnode* next;
//};//一个链表
//typedef struct pfnode PD;
//int main() {
//
//	return 0;
//}
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
#define MAXSIZE 100
#define DEL 10
#define START 3
#define ADD 2
typedef struct book {
	char id[20];
	char name[20];
	double price;
}B;
//typedef struct BOOKLIST {
//	B data[MAXSIZE];
//	int count;
//}BL;
typedef struct BOOKLIST {
	B* data;
	int count;//表示现有数据个数
	int py;//表示现有的容量
}BL;
//初始化函数
//void init(BL* p) {
//	p->count = 0;
//	memset(p->data, 0, sizeof(p->data));//初始化book
//}
//动态初始化
void init(BL* p) {
	p->count = 0;
	p->data=(B*)calloc(START,sizeof(B));//初始化book并进行扩容
	if (p->data == NULL) {
		perror("init");
	}
	p->py = START;
}
//添加函数
//void addbook(BL* p) {
//	if (p->count >= MAXSIZE) {
//		printf("已满不可添加\n");
//	}
//	printf("请输入书号书名及价格\n");
//	scanf("%s", &p->data[p->count].id);
//	scanf("%s", &p->data[p->count].name);
//	scanf("%lf", &p->data[p->count].price);
//	p->count++;
//	printf("添加成功\n");
//}
//动态添加
void addbook(BL* p) {
	if (p->count >= p->py) {
		B* pf = (B*)realloc(p->data, (p->py + ADD) * sizeof(B));//如果内容大于容量进行增容
		if (pf == NULL) {
			perror("addbook");
		}
		p->data = pf;
		p->py += ADD;
		printf("增容成功\n");
	}
	printf("请输入书号书名及价格\n");
	scanf("%s", &p->data[p->count].id);
	scanf("%s", &p->data[p->count].name);
	scanf("%lf", &p->data[p->count].price);
	p->count++;
	printf("添加成功\n");
}
//遍历函数
void showbook(BL* p) {
	for (int i = 0; i < p->count; i++) {
		printf("书号为%s 书名为%s 价格为%lf\n", 
			p->data[i].id,
			p->data[i].name,
			p->data[i].price);
	}
}
//插入函数
//void insertbook(BL* p) {
//	int pos = 0;
//	printf("请输入要插入的位置\n");
//	scanf("%d", &pos);
//	if (p->count >= MAXSIZE) {
//		printf("已满不可添加\n");
//	}
//	if (pos<1 || pos>MAXSIZE) {
//		printf("插入位置输入错误\n");
//	}
//	if (pos <= p->count) {
//		for (int i = p->count - 1; i >= pos-1; i--) {
//			p->data[i + 1] = p->data[i];
//		}
//		printf("请输入书号书名及价格\n");
//		scanf("%s", &p->data[pos-1].id);
//		scanf("%s", &p->data[pos-1].name);
//		scanf("%lf", &p->data[pos-1].price);
//		p->count++;
//		printf("插入成功\n");
//	}
//}
//动态插入
void insertbook(BL* p) {
	int pos = 0;
	printf("请输入要插入的位置\n");
	scanf("%d", &pos);
	if (p->count >= p->py) {
		B* pf = (B*)realloc(p->data, (p->py+ADD) * sizeof(B));//如果内容大于容量进行增容
		if (pf == NULL) {
			perror("addbook");
		}
		p->data = pf;
		p->py += ADD;
		printf("增容成功\n");
	}
	if (pos<1 || pos>p->py) {
		printf("插入位置输入错误\n");
	}
	if (pos <= p->count) {
		for (int i = p->count - 1; i >= pos - 1; i--) {
			p->data[i + 1] = p->data[i];
		}
		printf("请输入书号书名及价格\n");
		scanf("%s", &p->data[pos - 1].id);
		scanf("%s", &p->data[pos - 1].name);
		scanf("%lf", &p->data[pos - 1].price);
		p->count++;
		printf("插入成功\n");
	}
}
//删除函数
void delbook(BL* p) {
	char del[DEL] = { 0 };
	printf("请输入要删除的书名\n");
	scanf("%s", del);
	int pos = 0;
	for (int i = 0; i < p->count; i++) {
		if (strcmp(p->data[i].name, del) == 0) {
			pos=i;//找到名字相同的下标然后退出循环
			break;
		}
	}
	for (int i = pos; i < p->count-1; i++) {
		p->data[i] = p->data[i + 1];//用找到的pos让pos的位置等于下一个的位置以实现覆盖删除
	}
	p->count--;
	printf("删除成功\n");
}
//查找函数
void findbook(BL* p) {
	char del[DEL] = { 0 };
	printf("请输入要查找的书名\n");
	scanf("%s", del);
	for (int i = 0; i < p->count; i++) {
		if (strcmp(p->data[i].name, del) == 0) {
			printf("书号为%s 书名为%s 价格为%lf\n",
				p->data[i].id,
				p->data[i].name,
				p->data[i].price);
			break;
		}
	}
}
int main() {
	BL s;
	init(&s);
	for (int i = 0; i <START; i++) {
		addbook(&s);
	}
	showbook(&s);
	insertbook(&s);
	showbook(&s);
	delbook(&s);
	showbook(&s);
	findbook(&s);
	return 0;
}
