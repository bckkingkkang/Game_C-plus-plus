#include <stdio.h>
#include <math.h>
double myPow(double x, int y) {
	double result = 1.0;
	for (int i = 0; i < y; i++) {
		result = result * x;
	}
	return result;
}

void main() {
	printf("라이브러리 함수 pow(2.0, 5) = %lf\n", pow(2.0, 5));
	printf("사용자 정의 함수 myPow(2.0, 5) = % lf\n", myPow(2.0, 5));
}