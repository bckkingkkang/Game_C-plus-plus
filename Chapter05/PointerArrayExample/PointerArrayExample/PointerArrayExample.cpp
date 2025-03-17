#include <stdio.h>
void main() {
	int list[5] = { 1, 2, 3, 4, 5 };
	int* p = list;
	int sum = 0;

	printf("list : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *p++);
	}

	// 포인터에 배열 주소 복사
	p = list;
	for (int i = 0; i < 5; i++) {
		sum += p[i];
	}
	printf("\nsum = %d\n", sum);
}