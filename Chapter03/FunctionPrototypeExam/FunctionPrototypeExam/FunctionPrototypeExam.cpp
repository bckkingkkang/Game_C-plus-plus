#include <stdio.h>
// 함수 원형 : 함수의 몸체 없는 선언
// 함수 이름, 매개 변수 리스트(변수 이름을 생략하고 자료형만 선언 가능), 반환형

int factorial(int);
int add(int, int);
void main() {
	int x = 3;
	int y = 4;

	printf("x + y = %d\n", add(x, y));
	printf("x + 10 = %d\n", add(x, 10));
	printf("5 + 10 = %d\n", add(5, 10));

	printf("%d! = %d\n", x, factorial(x));
	printf("5! = %d\n", factorial(5));
}

int add(int a, int b) {
	return a + b;
}
int factorial(int a) {
	int num = 1;
	for (int i = 1; i <= a; i++) {
		num = num * i;
	}
	return num;
}
