#ifndef __STUDENT__
#define __STUDENT__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define namesize 10
#define idsize 20
#define telsize 30
#define sexsize 10
#define addresssize 100
typedef struct students {
	char name[namesize];
	char sex[sexsize];
	char id[idsize];
	char tel[telsize];
	char address[addresssize];
}ST;
typedef struct studentsnode
{
	ST data;
	struct studentsnode* next;
}SN;
SN* initstudents();
SN* addstudents(SN* p);
SN* gettail(SN* p);
void showstudents(SN* p);
void delstudents(SN* p);
void changestudents(SN* p);
void findstudents(SN* p);
void qsortstudents(SN* p);
#endif // !
