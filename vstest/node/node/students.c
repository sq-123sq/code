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
	printf("请输入学生性别\n");
	scanf("%s", &((pt->data).sex));
	printf("请输入学生学号\n");
	scanf("%s", & ((pt->data).id));
	printf("请输入学生电话\n");
	scanf("%s", & ((pt->data).tel));
	printf("请输入学生住址\n");
	scanf("%s", &((pt->data).address));
	pt->next = ps->next;
	ps->next = pt;
}
void showstudents(SN* p) {
	SN* ps = p->next;
	while (ps != NULL) {
		printf("姓名：%s 性别：%s 学号：%s 电话：%s 地址：%s", 
			((ps->data).name),
			((ps->data).sex),
			((ps->data).id), 
			((ps->data).tel),
			((ps->data).address));
		ps = ps->next;
		printf("\n");
	}
}
void delstudents(SN* p) {
	SN* ps = p->next;
	int k = -1;
	char buf[namesize];
	printf("请输入要删除的学生姓名\n");
	scanf("%s", buf);
	//if (ps== NULL) {
	//	printf("空表\n");
	//}
	//////删除第一个数据
	//if (strcmp(buf, (ps->data).name) == 0) {
	//	SN* pt = ps->next;
	//	ps->next = NULL;
	//	free(pt);
	//	printf("删除成功\n");
	//}
	while (ps!= NULL) {
		if (strcmp(buf, (ps->data).name) == 0) {
			SN* pt = ps->next;
			ps->next = pt->next;
			free(pt);
			k = 0;
			printf("删除成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1)
	printf("该学生不存在\n");
}
void changestudents(SN* p) {
	SN* ps = p;
	int k = -1;
	char buf[namesize];
	printf("请输入要更改的学生姓名\n");
	scanf("%s", &buf);
	while (ps->next != NULL) {
		if (strcmp(buf, (ps->data).name) == 0) {
			SN* pt = initstudents();
			printf("请输入学生姓名\n");
			scanf("%s", &((pt->data).name));
			printf("请输入学生性别\n");
			scanf("%s", &((pt->data).sex));
			printf("请输入学生学号\n");
			scanf("%s", &((pt->data).id));
			printf("请输入学生电话\n");
			scanf("%s", &((pt->data).tel));
			printf("请输入学生住址\n");
			scanf("%s", &((pt->data).address));
			ps->next = pt;
			pt->next = ps->next;
			k = 0;
			printf("更改成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1)
		printf("该学生不存在\n");
}
void findstudents(SN* p) {
	SN* ps = p;
	int k = -1;
	char buf[namesize];
	printf("请输入要查找的学生姓名\n");
	scanf("%s", &buf);
	while (ps->next != NULL) {
		if (strcmp(buf, (ps->data).name) == 0) {
			printf("姓名：%s 性别：%s 学号：%s 电话：%s 地址：%s",
				((ps->data).name),
				((ps->data).sex),
				((ps->data).id),
				((ps->data).tel),
				((ps->data).address));
			k = 0;
			printf("查找成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1)
		printf("该学生不存在\n");
}