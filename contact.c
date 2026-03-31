#include "contact.h"
void infotcon(con* pc){
	pc->count=0;
	memset(pc->data,0,sizeof(pc->data));
}
int findname(con* pc,char name[]){
	for(int i=0;i<pc->count;i++){
		if(0==strcmp(pc->data[i].name,name)){
			return i;
		}
	}
	return -1;
}
int comp_by_name(const void* e1,const void* e2){
	return strcmp(((peo*)e1)->name,((peo*)e2)->name);
}
void contactadd(con* pc){
	assert(pc);
	if(pc->count==MAX){
		printf("通讯录已满不能添加\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s",pc->data[pc->count].name);
	printf("请输入性别：");
	scanf("%s",pc->data[pc->count].sex);
	printf("请输入电话：");
	scanf("%s",pc->data[pc->count].tel);
	printf("请输入地址：");
	scanf("%s",pc->data[pc->count].addr);
	pc->count++;
	printf("输入成功\n");
}
void contactshow(con* pc){
	assert(pc);
	printf("%s %s %s %s\n","姓名","性别","电话","地址");
	for(int i=0;i<pc->count;i++){
		printf("%s %s %s %s\n",pc->data[i].name
			   ,pc->data[i].sex
			   ,pc->data[i].tel
			   ,pc->data[i].addr);
	}
}
void contactdel(con* pc){
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要删除的姓名\n");
	scanf("%s",name);
	int pos=findname(pc,name);
	if(pos==-1){
		printf("要删除的人不存在\n");
		return;
	}
	for(int i=pos;i<pc->count-1;i++){
		pc->data[i]=pc->data[i+1];
	}
	pc->count--;
	printf("删除成功\n");
}
void contactfind(con* pc){
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要查找的姓名\n");
	scanf("%s",name);
	int pos=findname(pc,name);
	if(pos==-1){
		printf("要查找的人不存在\n");
		return;
	}
	printf("%s %s %s %s\n","姓名","性别","电话","地址");
	printf("%s %s %s %s\n",pc->data[pos].name
			   ,pc->data[pos].sex
			   ,pc->data[pos].tel
			   ,pc->data[pos].addr);
}
void contactchange(con* pc){
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要改变人的姓名\n");
	scanf("%s",name);
	int pos=findname(pc,name);
	if(pos==-1){
		printf("要更改的人不存在\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s",pc->data[pos].name);
	printf("请输入性别：");
	scanf("%s",pc->data[pos].sex);
	printf("请输入电话：");
	scanf("%s",pc->data[pos].tel);
	printf("请输入地址：");
	scanf("%s",pc->data[pos].addr);
	printf("修改成功\n");
}
void contactqsout(con* pc){
	assert(pc);
	qsort(pc->data,pc->count,sizeof(peo),comp_by_name);
	printf("排序成功\n");
}
