#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX 10
//int main() {
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	for (size_t i = 0; i < 10; i++)
//	{
//		p[i] = i;//这里的p就相当于*(p+i)其实也相当于一个首元素地址
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main() {
//	int n = 0;
//	int m = 0;
//	while (scanf("%d%d", &n, &m) == 2) {
//		int max = n > m ? n : m;
//		int min = n < m ? n : m;
//		int gld;
//		int lcm;
//		while (1) {
//			if (n%min == 0 && m%min == 0) {
//				gld = min;
//				break;
//			}
//			min--;
//		}
//		while (1) {
//			if (max%n == 0 && max%m == 0) {
//				lcm = max;
//				break;
//			}
//			max++;
//		}
//		//while (min!=0) {
//		//	int r = max % min;
//		//	max = min;
//		//	min=r;
//		//}
//		//gld = max;
//		//lcm = n * m / max;
//		printf("%d", gld + lcm);
//	}
//	return 0;
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
//				printf("* ");
//			}
//			else {
//				printf("  ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//struct jk {
//	int n;
//	int arr[];//柔性数组
//};
//int main() {
//	struct jk* ps = (struct jk*)malloc(sizeof(struct jk)+MAX*sizeof(int));//sizeof(struct jk)一定要加这是int n的内存
//	if (ps == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	ps->n = 90;
//	/*for (int i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", ps->arr[i]);
//	}*/
//	struct jk* ptr=(struct jk*)realloc(ps, sizeof(struct jk)+80);//扩容处理sizeof(struct jk)一定要加这是int n的内存
//	if (ptr == NULL) {
//		printf("%s\n", strerror(errno));
//		free(ps);
//		ps = NULL;
//		return 1;
//	}
//	ps=ptr;
//	for (int i = 0; i < 20; i++) {
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 20; i++) {
//		printf("%d ", ps->arr[i]);
//	}
//	free(ptr);
//	ptr = NULL;
//	ps = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//fputc("a", pf);
//	for (char i = 'a'; i < 'z'; i++) {
//		fputc(i, pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 1;
	}
	int c=0;
	while ((c = fgetc(pf)) != EOF) {
		putchar(c);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}