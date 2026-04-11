#include <stdio.h>
int main() {
	int c = getchar();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}