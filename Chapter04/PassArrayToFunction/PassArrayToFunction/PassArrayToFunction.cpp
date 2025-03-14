// 배열과 문자열에서 각각 가장 큰 값을 찾아 반환하는 함수

// 함수로 배열을 전달
#include <string.h>
#include <stdio.h>

int findMaxValue(int a[], int len) {
	int maxValue = a[0];
	// 배열의 길이만큼 반복
	for (int i = 1; i < len; i++) {
		if (maxValue < a[i]) {
			maxValue = a[i];
		}
	}
	return maxValue;
}

char findMaxChar(char a[]) {
	char maxChar = a[0];
	for (int i = 1; i < strlen(a); i++) {
		if (maxChar < a[i]) {
			maxChar = a[i];
		}
	}
	return maxChar;
}

void main() {
	int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
	printf("max value = %d\n", findMaxValue(arr, 10));

	char str[] = "game over!";
	printf("max char value = %c\n", findMaxChar(str));
}