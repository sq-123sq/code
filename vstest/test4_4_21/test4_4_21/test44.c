#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
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
//		/*while (1) {
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
//		}*/
//		while (min!=0) {
//			int r = max % min;
//			max = min;
//			min=r;
//		}
//		gld = max;
//		lcm = n * m / max;
//		printf("%d", gld + lcm);
//	}
//	return 0;
//}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}