#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 12
#define MAX_ADDR 20
struct people{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};
typedef struct people peo;
struct contact{
    peo data[MAX];//存放人的信息
	int count;//记录当前人的个数
};
typedef struct contact con;
//初始化
void infotcon(con* pc);
//添加函数
void contactadd(con* pc);
//展示函数
void contactshow(con* pc);
//删除函数
void contactdel(con* pc);
//查找函数
void contactfind(con* pc);
//改变函数
void contactchange(con* pc);
//根据姓名排序函数
void contactqsout(con* pc);
