#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int a[], int len, const char msg[] = "Array") {
	printf("%s : ", msg);
	for (int i = 0; i < len; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}

void addDescending(int a[], int val) {
	if (val > a[4]) {
		a[4] = val;
		for (int i = 3; i >= 0; i--) {
			if (a[i] > val) {
				return;
			}
			if (a[i] < val) {
				a[i+1] = a[i];
				a[i] = val;
			}
		}
	}
	else if (val < a[4]) {
		printf("순위권에 들지 않습니다.\n");
	}
}

void main() {
	srand((unsigned)time(NULL));

	int score[5] = {0, 0, 0, 0, 0};
	for (int i = 0; i < 8; i++) {
		int newScore = rand() % 100;
		addDescending(score, newScore);
		printf("새로 등록된 수 : %d\n", newScore);
		printArray(score, 5, "순위");
		printf("\n");
	}
}