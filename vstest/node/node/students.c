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
SN* gettail(SN* p) {
	SN* ps = p;
	while (ps->next != NULL) {
		ps = ps->next;
	}
	return ps;
}
int compare_name(const void* e1, const void* e2) {
	return strcmp(((ST*)e1)->name, ((ST*)e2)->name);
}
int compare_id(const void* e1, const void* e2) {
	return strcmp(((ST*)e1)->id, ((ST*)e2)->id);
}
int compare_tel(const void* e1, const void* e2) {
	return strcmp(((ST*)e1)->tel, ((ST*)e2)->tel);
}
int compare_address(const void* e1, const void* e2) {
	return strcmp(((ST*)e1)->address, ((ST*)e2)->address);
}
void freadstudents(SN* p) {
	SN* tail = p;
	ST tmp;
	FILE* pf = fopen("node.txt", "rb");
	if (pf == NULL) {
		perror("freadstudents");
		return;
	}
	while (fread(&tmp, sizeof(ST), 1, pf)==1)
	{
		SN* node = (SN*)malloc(sizeof(SN));
		if (node == NULL) {
			perror("freadstudents");
			return;
		}
		node->data = tmp;
		node->next = NULL;
		while (tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next = node;
		/*printf("姓名：%s 性别：%s 学号：%s 电话：%s 地址：%s",
			((node->data).name),
			((node->data).sex),
			((node->data).id),
			((node->data).tel),
			((node->data).address));
		printf("\n");*/
	}
	printf("数据加载成功\n");
	fclose(pf);
	pf = NULL;
}
SN* addstudents(SN* p) {
	SN* pt = initstudents();
	printf("请输入学生姓名\n");
	scanf("%s", (pt->data).name);
	printf("请输入学生性别\n");
	scanf("%s", (pt->data).sex);
	printf("请输入学生学号\n");
	scanf("%s", (pt->data).id);
	printf("请输入学生电话\n");
	scanf("%s", (pt->data).tel);
	printf("请输入学生住址\n");
	scanf("%s", (pt->data).address);
	SN* tail = gettail(p);
	tail->next = pt;
	pt->next = NULL;
	return p;
}
void showstudents(SN* p) {
	SN* ps = p->next;
	if (ps == NULL) {
		printf("学生信息不存在\n");
		return;
	}
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
	SN* ps = p;
	int k = -1;
	char buf[namesize];
	printf("请输入要删除的学生姓名\n");
	scanf("%s", buf);
	if (ps->next== NULL && strcmp(buf, (ps->next->data).name) == 0) {
		free(ps);
		p->next = NULL;
		k = 0;
		printf("删除成功\n");
	}
	while (ps->next!= NULL) {
		if (strcmp(buf, (ps->next->data).name) == 0) {
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
		if (strcmp(buf, (ps->next->data).name) == 0) {
			SN* pt = initstudents();
			printf("请输入学生姓名\n");
			scanf("%s", (pt->data).name);
			printf("请输入学生性别\n");
			scanf("%s", (pt->data).sex);
			printf("请输入学生学号\n");
			scanf("%s", (pt->data).id);
			printf("请输入学生电话\n");
			scanf("%s", (pt->data).tel);
			printf("请输入学生住址\n");
			scanf("%s", (pt->data).address);
			ps->next = pt;
			pt->next=ps->next->next;
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
	SN* ps = p->next;
	int k = -1;
	char buf[namesize];
	printf("请输入要查找的学生姓名\n");
	scanf("%s", &buf);
	while (ps!= NULL) {
		if (strcmp(buf, (ps->data).name) == 0) {
			printf("姓名：%s 性别：%s 学号：%s 电话：%s 地址：%s",
				((ps->data).name),
				((ps->data).sex),
				((ps->data).id),
				((ps->data).tel),
				((ps->data).address));
			k = 0;
			printf("\n查找成功\n");
			break;
		}
		ps = ps->next;
	}
	if (k == -1)
		printf("该学生不存在\n");
}
void menu1() {
	printf("**************学生信息排序**************\n");
	printf("*****1.按姓名排序**2.按学号排序*********\n");
	printf("*****3.按电话排序**4.按地址排序*********\n");
	printf("******0.退出学生信息排序****************\n");
	printf("****************************************\n");
}
void qsortstudents1(SN* p,int(*cmp)(const void*,const void* )) {//cmp为函数指针
	SN* ps = p->next;
	int len = 0;
	while (ps != NULL) {
		ps = ps->next;
		len++;
	}
	ST* arr = (ST*)malloc(sizeof(ST)*len);
	ps = p->next;
	for (int i = 0; i < len; i++) {
		arr[i] = ps->data;
		ps = ps->next;
	}
	qsort(arr, len, sizeof(ST), cmp);
	ps = p->next;
	for (int i = 0; i < len; i++) {
		ps->data = arr[i];
		ps = ps->next;
	}
	free(arr);
}
void qsortstudents(SN* p) {
	menu1();
	int input;
	printf("请选择排序方式\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		qsortstudents1(p, compare_name);
		printf("按姓名排序成功\n");
		break;
	case 2:
		qsortstudents1(p, compare_id);
		printf("按学号排序成功\n");
		break;
	case 3:
		qsortstudents1(p, compare_tel);
		printf("按电话排序成功\n");
		break;
	case 4:
		qsortstudents1(p, compare_address);
		printf("按地址排序成功\n");
		break;
	case 0:
		printf("退出学生信息排序\n");
		break;
	default:
		printf("输入错误，退出排序程序\n");
		break;
	}
}
void freestudents(SN* p) {
	SN* ps = p->next;
	SN* pt=NULL;
	while (ps!=NULL)
	{
		ps->next = pt;
		free(ps);
		ps = pt;
	}
	p->next = ps;
	printf("释放空间成功\n");
}
void fwritestudents(SN* p) {
	SN* ps = p->next;
	FILE* pf = fopen("node.txt", "wb");
	if (pf == NULL) {
		perror("fwritestudents");
		return;
	}
	while (ps!=NULL)
	{
		fwrite(&ps->data, sizeof(ST), 1, pf);
		ps = ps->next;
	}
	printf("数据载入成功\n");
	fclose(pf);
	pf = NULL;
}