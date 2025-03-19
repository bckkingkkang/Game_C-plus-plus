// 이진 모드로 정수 배열을 파일에 저장하고 읽는 프로그램
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void fprintArray(int a[], int len, FILE* fp = stdout) {	// 마지막 매개변수 디폴트는 표준 출력
	// 매개변수를 전달받는 경우 파일에 출력
	// fprintf() 함수의 첫 번째 매개변수가 stdout이면 printf() 함수와 전적으로 동일하게 동작한다.
	for (int i = 0; i < len; i++) {
		fprintf(fp, "%d ", a[i]);
	}
	fprintf(fp, "\n");
}

void main() {
	FILE* fp = NULL;

	int a[10], b[10];

	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100 + 1;
	}

	printf("원본 데이터 : ");
	fprintArray(a, 10);

	fp = fopen("이진파일.bin", "w");
	if (fp != NULL) {
		fwrite(a, sizeof(int), 10, fp);
		// 데이터 주소, 자료형의 크기, 자료의 개수, 파일 포인터
		fclose(fp);
	}

	fp = fopen("이진파일.bin", "r");
	if (fp != NULL) {
		fread(b, sizeof(int), 10, fp);
		printf("이진 파일 : ");
		fprintArray(b, 10);
		fclose(fp);
	}
}