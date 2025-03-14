// 함수로부터의 배열 반환 : 역순 배열을 구하는 함수
#include <string.h>
#include <stdio.h>

void printArray(const int a[], int len, const char msg[] = "Array") {
	printf("%s : ", msg);
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void reverseArray(const int a[], int b[], int len) {
	for (int i = 0; i < len; i++) {
		b[i] = a[len - i -1];
	}
}

void reverseString(const char src[], char dst[]) {
	int len = strlen(src);
	for (int i = 0; i < len; i++) {
		dst[i] = src[len - i - 1];
	}
	dst[len] = '\0';
}

void main() {
	int a[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
	int b[10];

	// 배열 a의 역순을 b에 저장
	reverseArray(a, b, 10);
	
	printArray(a, 10, "배열 a");
	printArray(b, 10, "배열 b");

	char src[] = "game over !";
	char dsc[40];
	
	reverseString(src, dsc);
	printf("src : %s\n", src);
	printf("dsc : %s\n", dsc);
}