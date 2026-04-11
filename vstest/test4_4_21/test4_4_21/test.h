#define _CRT_SECURE_NO_WARNINGS 1
#ifndef TH//这里的#ifndef的作用是头文件只包含一次
#define TH 
//int ADD(int x, int y);
#endif
//#gragma once//这个也可以头文件只包含一次但vs2017不认识所以用上一种办法
//int ADD(int x, int y);
#ifndef TER
#define TER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <math.h>
#define EPS 1e-6
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
void init(BL* p);
void addbook(BL* p);
void findbook(BL* p);
void delbook(BL* p);
void changebook(BL* p);
void qsortbook(BL* p);
void showbook(BL* p);
void insertbook(BL* p);
void cleanbook(BL* p);
#endif // !1
