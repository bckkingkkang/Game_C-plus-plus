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
	printf("���̺귯�� �Լ� pow(2.0, 5) = %lf\n", pow(2.0, 5));
	printf("����� ���� �Լ� myPow(2.0, 5) = % lf\n", myPow(2.0, 5));
}