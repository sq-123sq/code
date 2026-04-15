#ifndef __STUDENT__
#define __STUDENT__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define namesize 10
#define idsize 20
#define telsize 30
typedef struct students {
	char name[namesize];
	char id[idsize];
	char tel[telsize];
}ST;
typedef struct studentsnode
{
	ST data;
	struct studentsnode* next;
}SN;
SN* initstudents();
void addstudents(SN* p);
void showstudents(SN* p);
#endif // !
