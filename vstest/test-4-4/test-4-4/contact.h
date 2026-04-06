#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 12
#define MAX_ADDR 20
#define ZXC 3
#define ASD 2
struct people {
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};
typedef struct people peo;
//静态的通讯录
//struct contact {
//	peo data[MAX];//存放人的信息
//	int count;//记录当前人的个数
//};
//动态的通讯录
struct contact {
	peo* data;//存放人的信息
	int sc;
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
//清除通讯录
void clean_all(con* pc);
//保留通讯录
void savecontact(con* pc);
//加载通讯录加载出上次写入的通讯录信息
void loadcontact(con* pc);