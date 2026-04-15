#include "students.h"
SN* initstudents() {
	SN* p1 = (SN*)malloc(sizeof(SN));
	if (p1 == NULL) {
		perror("initstudents");
		return NULL;
	}
	memset(&(p1->data), 0, sizeof(ST));
	p1->next = NULL;
	return p1;
}
void addstudents(SN* p) {
	SN* ps = p;
	SN* pt = initstudents();
	printf("请输入学生姓名\n");
	scanf("%s", &((pt->data).name));
	printf("请输入学生学号\n");
	scanf("%s", & ((pt->data).id));
	printf("请输入学生电话\n");
	scanf("%s", & ((pt->data).tel));
	ps->next = pt;
	pt->next = NULL;
}
void showstudents(SN* p) {
	SN* ps = p->next;
	while (ps != NULL) {
		printf("姓名：%s 学号：%s 电话：%s", ((ps->data).name), ((ps->data).id), ((ps->data).tel));
		ps = ps->next;
		printf("\n");
	}
}