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
int main() {
	int a = 0;
	scanf("%d", &a);
	while (a!=0) {
		int i = 0;
		for (i = 0; i <a;i++) {
			for (int j = 0; j < a; j++) {
				printf("  ");
			}
			for (int s = 0; s <= a - i; s++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}