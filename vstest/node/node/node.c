#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int ss;
typedef struct headnode {
	ss date;
	struct headnode* prv;
	struct headnode* next;
}hd;
//初始化双向链表
hd* inithd() {
	hd* p = (hd*)malloc(sizeof(hd));
	if (p == NULL) {
		perror("inithd");
		return NULL;
	}
	p->date = 0;
	p->next = NULL;
	p->prv = NULL;
	return p;
}
//头插法
void inserthead(hd* p,ss k) {
	hd* ps = inithd();
	/*ss c = 0;
	printf("输入一个整数\n");
	scanf("%d", &c);
	ps->date = c;*/
	ps->date = k;
	ps->prv = p;
	ps->next = p->next;
	if(p->next!=NULL)
	p->next->prv = ps;
	p->next = ps;
}
//遍历
void showhd(hd* p) {
	hd* ps = p->next;
	while (ps != NULL) {
		printf("%d", ps->date);
		ps = ps->next;
	}
	printf("\n");
}
//尾插法
void inserttail(hd* p,ss k) {
	hd* pr = p;
	while (pr->next != NULL) {
		pr = pr->next;
	}
	hd* ps = inithd();
	ps->date = k;
	ps->prv = pr;
	pr->next = ps;
	ps->next = NULL;
}
//插入数据
void insertdata(hd* p,ss k,int pos) {
	hd* ps = p;
	for (int i = 0; i < pos - 1; i++) {
		ps = ps->next;
		if (ps == NULL)return;
	}
	hd* pt = inithd();
	pt->date = k;
	pt->prv = ps;
	pt->next = ps->next;
	ps->next = pt;
	if(ps->next!=NULL)
	ps->next->prv = pt;
}
//删除数据
void delhd(hd* p,int pos) {
	hd* ps = p;
	for (int i = 0; i < pos - 1; i++) {
		ps = ps->next;
		if (ps == NULL)return;
	}
	hd* pt = ps->next;
	ps->next = pt->next;
	pt->next->prv = ps;
	free(pt);
}
int main() {
	hd* qw = inithd();
	/*inserthead(qw,10);
	inserthead(qw, 20);
	inserthead(qw, 30);*/
	inserttail(qw, 10);
	inserttail(qw, 20);
	inserttail(qw, 30);
	showhd(qw);
	insertdata(qw, 40, 2);
	showhd(qw);
	delhd(qw,2);
	showhd(qw);
	return 0;
}