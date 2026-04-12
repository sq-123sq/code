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
}
//删除函数
void dels(ts* c) {
	ts* ps = c;
	char* buf = (char*)malloc(sizeof(char)*SIZE);
	if (buf == NULL) {
		perror("dels");
		return;
	}
	memset(buf, 0, sizeof(buf));
	printf("请输入要去除的名字\n");
	scanf("%s", buf);
	while (ps->next != NULL) {
		ps = ps->next;
		if (strcmp(buf, (ps->next->p).name) == 0) {
			ts* pt = ps->next;
			ps->next = pt->next;
			free(pt);
			printf("删除成功\n");
			break;
		}
	}
	free(buf);
	buf = NULL;
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
		printf("请输入1或2,3，输入0则退出\n");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
			adds(c);
			break;
		case 2:
			shows(c);
			break;
		case 3:
			dels(c);
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