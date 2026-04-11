#include "test.h"
void init(BL* p) {
	p->count = 0;
	p->data = (B*)calloc(START, sizeof(B));//初始化book并进行扩容
	if (p->data == NULL) {
		perror("init");
	}
	p->py = START;
}
void addroom(BL* p) {
	if (p->count >= p->py) {
		B* pf = (B*)realloc(p->data, (p->py + ADD) * sizeof(B));//如果内容大于容量进行增容
		if (pf == NULL) {
			perror("addbook");
		}
		p->data = pf;
		p->py += ADD;
		printf("增容成功\n");
	}
}
void menu1() {
	printf("**请输入排序选项**\n");
	printf("**1.按书号********\n");
	printf("**2.按书名********\n");
	printf("**3.按价格********\n");
	printf("**0.退出排序选项**\n");
}
//初始化函数
//void init(BL* p) {
//	p->count = 0;
//	memset(p->data, 0, sizeof(p->data));//初始化book
//}
//动态初始化
int comparebook_id(const void* e1, const void* e2) {
	return strcmp(((B*)e1)->id, ((B*)e2)->id);
}
int comparebook_name(const void* e1, const void* e2) {
	return strcmp(((B*)e1)->name, ((B*)e2)->name);
}
int comparebook_price(const void* e1, const void* e2) {
	double s1 = ((B*)e1)->price;
	double s2 = ((B*)e2)->price;
	if (fabs(s1 - s2) < EPS) {
		return 0;
	}
	return s1 > s2 ? -1:1;
}
//添加函数
//void addbook(BL* p) {
//	if (p->count >= MAXSIZE) {
//		printf("已满不可添加\n");
//	}
//	printf("请输入书号书名及价格\n");
//	scanf("%s", &p->data[p->count].id);
//	scanf("%s", &p->data[p->count].name);
//	scanf("%lf", &p->data[p->count].price);
//	p->count++;
//	printf("添加成功\n");
//}
//动态添加
void addbook(BL* p) {
	assert(p);
	addroom(p);
	printf("请输入书号书名及价格\n");
	scanf("%s", &p->data[p->count].id);
	scanf("%s", &p->data[p->count].name);
	scanf("%lf", &p->data[p->count].price);
	p->count++;
	printf("添加成功\n");
}
//遍历函数
void showbook(BL* p) {
	assert(p);
	for (int i = 0; i < p->count; i++) {
		printf("书号为%s 书名为%s 价格为%lf\n",
			p->data[i].id,
			p->data[i].name,
			p->data[i].price);
	}
}
//插入函数
//void insertbook(BL* p) {
//	int pos = 0;
//	printf("请输入要插入的位置\n");
//	scanf("%d", &pos);
//	if (p->count >= MAXSIZE) {
//		printf("已满不可添加\n");
//	}
//	if (pos<1 || pos>MAXSIZE) {
//		printf("插入位置输入错误\n");
//	}
//	if (pos <= p->count) {
//		for (int i = p->count - 1; i >= pos-1; i--) {
//			p->data[i + 1] = p->data[i];
//		}
//		printf("请输入书号书名及价格\n");
//		scanf("%s", &p->data[pos-1].id);
//		scanf("%s", &p->data[pos-1].name);
//		scanf("%lf", &p->data[pos-1].price);
//		p->count++;
//		printf("插入成功\n");
//	}
//}
//动态插入
void insertbook(BL* p) {
	assert(p);
	int pos = 0;
	printf("请输入要插入的位置\n");
	scanf("%d", &pos);
	addroom(p);
	if (pos<1 || pos>p->count) {
		printf("插入位置输入错误\n");
	}
	if (pos <= p->count) {
		for (int i = p->count - 1; i >= pos - 1; i--) {
			p->data[i + 1] = p->data[i];
		}
		printf("请输入书号书名及价格\n");
		scanf("%s", &p->data[pos - 1].id);
		scanf("%s", &p->data[pos - 1].name);
		scanf("%lf", &p->data[pos - 1].price);
		p->count++;
		printf("插入成功\n");
	}
}
//删除函数
void delbook(BL* p) {
	assert(p);
	char del[DEL] = { 0 };
	printf("请输入要删除的书名\n");
	scanf("%s", del);
	int pos = 0;
	int k = -1;
	for (int i = 0; i < p->count; i++) {
		if (strcmp(p->data[i].name, del) == 0) {
			pos = i;//找到名字相同的下标然后退出循环
			k = 0;
			break;
		}
	}
	if (k == -1) {
		printf("删除失败，没有此书名\n");
	}
	else if (k == 0) {
		for (int i = pos; i < p->count - 1; i++) {
			p->data[i] = p->data[i + 1];//用找到的pos让pos的位置等于下一个的位置以实现覆盖删除
		}
		p->count--;
		printf("删除成功\n");
	}
}
//更改函数
void changebook(BL* p) {
	assert(p);
	char del[DEL] = { 0 };
	printf("请输入要更改的书名\n");
	scanf("%s", del);
	int pos=0;
	int k = -1;
	for (int i = 0; i < p->count; i++) {
		if (strcmp(p->data[i].name, del) == 0) {
			pos = i;//找到名字相同的下标然后退出循环
			k = 0;
			break;
		}
	}
	if (k == -1) {
		printf("更改失败没有此书名\n");
	}else if (k == 0) {
		printf("请输入书号书名及价格\n");
		scanf("%s", &p->data[pos].id);
		scanf("%s", &p->data[pos].name);
		scanf("%lf", &p->data[pos].price);
		printf("更改成功\n");
	}
}
//查找函数
void findbook(BL* p) {
	assert(p);
	char del[DEL] = { 0 };
	printf("请输入要查找的书名\n");
	scanf("%s", del);
	int k = -1;
	for (int i = 0; i < p->count; i++) {
		if (strcmp(p->data[i].name, del) == 0) {
			printf("书号为%s 书名为%s 价格为%lf\n",
				p->data[i].id,
				p->data[i].name,
				p->data[i].price);
			k = 0;
			break;
		}
	}
	if (k == -1) {
		printf("书名不存在\n");
	}
}
void qsortbook(BL* p) {
	assert(p);
	int ps = 0;
	menu1();
	scanf("%d", &ps);
	switch (ps)
	{
	case 1:
		qsort(p->data, p->count, sizeof(B), comparebook_id);
		printf("排序成功\n");
		break;
	case 2:
		qsort(p->data, p->count, sizeof(B), comparebook_name);
		printf("排序成功\n");
		break;
	case 3:
		qsort(p->data, p->count, sizeof(B), comparebook_price);
		printf("排序成功\n");
		break;
	case 0:
		printf("退出排序选项\n");
		break;
	default:
		printf("输入错误，退出排序选项\n");
		break;
	}
}
void cleanbook(BL* p) {
	free(p->data);
	p->data = NULL;
	p->count = 0;
	p->py = 0;
}