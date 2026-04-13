#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 20
typedef struct students {
	char name[SIZE];
	char id[SIZE];
}s;
typedef struct takestudent {
	s p;
	struct takestudent* next;
}ts;
//初始化
ts* inits() {
	ts* c = (ts*)malloc(sizeof(ts));
	if (c == NULL) {
		perror("inits");
		return NULL;
	}
	/*memset((c->p).id, 0, sizeof(s));
	memset((c->p).name, 0, sizeof(s));*/
	memset(&(c->p), 0, sizeof(s));
	c->next = NULL;
	return c;
}
//反转链表
ts* reservers(ts* c) {
	ts* fist = NULL;
	ts* second = c->next;
	ts* third;
	while (second != NULL) {
		third = second->next;
		second->next = fist;
		fist = second;
		second = third;
	}
	ts* new = inits();
	new->next = fist;
	return new;
}
//遍历
void shows(ts* c) {
	ts* q = c->next;
	while (q != NULL) {
		printf("%s %s", (q->p).name, (q->p).id);
		q = q->next;
		printf("\n");
	}
}
//添加函数
void adds(ts* c) {
	ts* p = c;
	ts* ps = (ts*)malloc(sizeof(ts));
	if (ps == NULL) {
		perror("adds");
		return;
	}
	printf("请输入姓名\n");
	scanf("%s", &((ps->p).name));
	printf("请输入学号\n");
	scanf("%s", &((ps->p).id));
	
	ps->next = p->next;
	p->next = ps;
	printf("添加成功\n");
}
//删除函数
void dels(ts* c) {
	ts* ps = c;
	int k = -1;
	char* buf = (char*)malloc(sizeof(char)*SIZE);
	if (buf == NULL) {
		perror("dels");
		return;
	}
	memset(buf, 0, sizeof(buf));
	printf("请输入要去除的名字\n");
	scanf("%s", buf);
	while (ps->next != NULL) {
		if (strcmp(buf, (ps->next->p).name) == 0) {
			ts* pt = ps->next;
			ps->next = pt->next;
			free(pt);
			k = 0;
			printf("删除成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1) {
		printf("删除失败没有该名字\n");
	}
	free(buf);
	buf = NULL;
}
//查找函数
void finds(ts* c) {
	ts* ps = c;
	int k = -1;
	char* buf = (char*)malloc(sizeof(char)*SIZE);
	if (buf == NULL) {
		perror("dels");
		return;
	}
	memset(buf, 0, sizeof(buf));
	printf("请输入要查找的名字\n");
	scanf("%s", buf);
	while (ps->next != NULL) {
		if (strcmp(buf, (ps->next->p).name) == 0) {
			printf("%s %s", (ps->next->p).name, (ps->next->p).id);
			k = 0;
			printf("查找成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1) {
		printf("查找失败没有该名字\n");
	}
	free(buf);
	buf = NULL;
}
void changes(ts* c) {
	ts* ps = c;
	int k = -1;
	char* buf = (char*)malloc(sizeof(char)*SIZE);
	if (buf == NULL) {
		perror("dels");
		return;
	}
	memset(buf, 0, sizeof(buf));
	printf("请输入要更改的名字\n");
	scanf("%s", buf);
	while (ps->next != NULL) {
		if (strcmp(buf, (ps->next->p).name) == 0) {
			ts* pt = ps->next;
			ps->next = pt->next;
			free(pt);
			ts* pc = (ts*)malloc(sizeof(ts));
			if (pc == NULL) {
				perror("changes");
				return;
			}
			printf("请输入姓名\n");
			scanf("%s", &((pc->p).name));
			printf("请输入学号\n");
			scanf("%s", &((pc->p).id));

			pc->next = ps->next;
			ps->next = pc;
			k = 0;
			printf("更改成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1) {
		printf("更改失败没有该名字\n");
	}
	free(buf);
	buf = NULL;
}
//清空
void delall(ts* c) {
	ts* ps = c->next;
	ts* pt = NULL;
	while (ps != NULL) {
		ps->next = pt;
		free(ps);
		ps = pt;
	}
	c->next = ps;
	printf("已删除所有信息\n");
}
void menu() {
	printf("*************学生管理系统**************\n");
	printf("**1.添加学生信息***2.显示学生信********\n");
	printf("**3.删除学生信息***4.查找学生信息******\n");
	printf("**5.更改学生信息***0.退出管理系统******\n");
	printf("**6.清除所有学生信息***********************\n");
}
int main() {
	/*int c = getchar();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", c);
		}
		printf("\n");
	}*/
	/*int n = 0;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		sum = sum + i * 100;
	}
	printf("%d\n", sum);*/
	int intput = 0;
	ts* c = inits();
	do
	{
		menu();
		printf("请输入选项\n");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
			adds(c);
			break;
		case 2:
			c = reservers(c);
			shows(c);
			break;
		case 3:
			dels(c);
			break;
		case 4:
			finds(c);
			break;
		case 5:
			changes(c);
			break;
		case 6:
			delall(c);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("没有该选项请重新输入\n");
			break;
		}
	} while (intput);
	return 0;
}