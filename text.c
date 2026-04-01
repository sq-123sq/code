#include "contact.h"
#include "contact.c"
void menu(){
	printf("*****************************\n");
	printf("****1.add         2.del******\n");
	printf("****3.find       4.change****\n");
	printf("****5.show         6.qsout****\n");
	printf("****0.exit*******************\n");
	printf("*****************************\n");
}
int main(){
	int input;
	con c;
	infotcon(&c);
	do{
		menu();
		printf("请输入选项：");
		scanf("%d",&input);
		switch (input) {
		case 1:
			contactadd(&c);
			break;
		case 2:
			contactdel(&c);
			break;
		case 3:
			contactfind(&c);
			break;
		case 4:
			contactchange(&c);
			break;
		case 5:
			contactshow(&c);
			break;
		case 6:
			contactqsout(&c);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重新输入选项\n");
			break;
		}
	}while(input);
	return 0;
}
