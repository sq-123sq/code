#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//静态的通讯录
//void infotcon(con* pc) {
//   assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//动态的添加通讯录
void check_add(con* pc) {
	assert(pc);
	if (pc->count == pc->sc) {
		peo* ptr = (peo*)realloc(pc->data, (pc->sc + ASD) * sizeof(peo));
		if (ptr == NULL) {
			perror("contactadd");
			return;
		}
		else {
			pc->data = ptr;
			pc->sc += ASD;
			printf("增容成功\n");
		}
	}
}//增容函数
void loadcontact(con* pc) {
	FILE* pfread = fopen("contact.txt","rb");
	if (pfread == NULL) {
		perror("loadcontact");
		return;
	}
	peo tmp = { 0 };
	while (fread(&tmp, sizeof(peo), 1, pfread) == 1) {
		check_add(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfread);
	pfread = NULL;
}
//动态的通讯录
void infotcon(con* pc) {
	assert(pc);
	pc->count = 0;
	pc->data = (peo*)calloc(ZXC, sizeof(peo));
	if (pc->data == NULL) {
			perror("infotcon");
			return;
	}
	pc->sc = ZXC;
	loadcontact(pc);
}
//清除函数
void clean_all(con* pc) {
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}
int findname(con* pc, char name[]) {
	for (int i = 0; i < pc->count; i++) {
		if (0 == strcmp(pc->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}
void menu2() {
	printf("******************************\n");
	printf("****1.name         2.sex******\n");
	printf("****3.tel        4.address****\n");
	printf("****0.exit********************\n");
	printf("******************************\n");
}
int comp_by_name(const void* e1, const void* e2) {
	return strcmp(((peo*)e1)->name, ((peo*)e2)->name);
}
int comp_by_sex(const void* e1, const void* e2) {
	return strcmp(((peo*)e1)->sex, ((peo*)e2)->sex);
}
int comp_by_tel(const void* e1, const void* e2) {
	return strcmp(((peo*)e1)->tel, ((peo*)e2)->tel);
}
int comp_by_address(const void* e1, const void* e2) {
	return strcmp(((peo*)e1)->addr, ((peo*)e2)->addr);
}
//静态添加通讯录
//void contactadd(con* pc) {
//	assert(pc);
//	if (pc->count == MAX) {
//		printf("通讯录已满不能添加\n");
//		return;
//	}
//	printf("请输入姓名：");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->count].tel);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->count].addr);
//	pc->count++;
//	printf("输入成功\n");
//}
//动态的添加通讯录
void contactadd(con* pc) {
	assert(pc);
	check_add(pc);
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->count].tel);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("输入成功\n");
}
void contactshow(con* pc) {
	assert(pc);
	printf("%s %s %s %s\n", "姓名", "性别", "电话", "地址");
	for (int i = 0; i < pc->count; i++) {
		printf("%s %s %s %s\n", pc->data[i].name
			, pc->data[i].sex
			, pc->data[i].tel
			, pc->data[i].addr);
	}
}
void contactdel(con* pc) {
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要删除的姓名\n");
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1) {
		printf("要删除的人不存在\n");
		return;
	}
	for (int i = pos; i < pc->count - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}
void contactfind(con* pc) {
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要查找的姓名\n");
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1) {
		printf("要查找的人不存在\n");
		return;
	}
	printf("%s %s %s %s\n", "姓名", "性别", "电话", "地址");
	printf("%s %s %s %s\n", pc->data[pos].name
		, pc->data[pos].sex
		, pc->data[pos].tel
		, pc->data[pos].addr);
}
void contactchange(con* pc) {
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要改变人的姓名\n");
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1) {
		printf("要更改的人不存在\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pos].tel);
	printf("请输入地址：");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功\n");
}
void contactqsout(con* pc) {
	assert(pc);
	int input1 = 0;
	printf("程序开始\n");
	printf("请选择你想要的排序选项\n");
	menu2();
	scanf("%d", &input1);
	switch (input1) {
	case 1:
		qsort(pc->data, pc->count, sizeof(peo), comp_by_name);
		printf("排序成功\n");
		break;
	case 2:
		qsort(pc->data, pc->count, sizeof(peo), comp_by_sex);
		printf("排序成功\n");
		break;
	case 3:
		qsort(pc->data, pc->count, sizeof(peo), comp_by_tel);
		printf("排序成功\n");
		break;
	case 4:
		qsort(pc->data, pc->count, sizeof(peo), comp_by_address);
		printf("排序成功\n");
		break;
	case 0:
		printf("退出排序程序\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}
}
void savecontact(con* pc) {
	assert(pc);
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (pfwrite == NULL) {
		perror("savecontact");
		return;
	}
	for (int i = 0; i < pc->count; i++) {
		fwrite(pc->data+i, sizeof(peo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}