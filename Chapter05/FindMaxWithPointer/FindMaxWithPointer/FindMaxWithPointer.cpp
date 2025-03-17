#include <stdio.h>

// 포인터를 사용하면 *를 이용하여 값을 변경하고, 참조자를 사용하면 * 없이 값을 직접 수정할 수 있다.

// 주소에 의한 호출
void findMinMaxValue(int* a, int len, int* min, int* max) {
	int maxVal = a[0];
	
	if (min != NULL) {
		*min = a[0];
		for (int i = 1; i < len; i++) {
			if (*min > a[i]) {
				*min = a[i];
			}
		}
	}
	if (max != NULL) {
		*max = a[0];
		for (int i = 1; i < len; i++) {
			if (*max < a[i]) {
				*max = a[i];
			}
		}
	}
}

void main() {
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int min, max;

	findMinMaxValue(arr, 10, &min, &max);
	printf("최소 ~ 최대 : %d ~ %d\n", min, max);

}
/*
* 참조에 의한 호출
#include <stdio.h>

void findMinMaxValue(int* a, int len, int &min, int &max) {
	int maxVal = a[0];

	min = a[0];
	for (int i = 1; i < len; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	
	max = a[0];
	for (int i = 1; i < len; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	
}

void main() {
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int min, max;

	findMinMaxValue(arr, 10, min, max);
	printf("최소 ~ 최대 : %d ~ %d\n", min, max);
}
*/