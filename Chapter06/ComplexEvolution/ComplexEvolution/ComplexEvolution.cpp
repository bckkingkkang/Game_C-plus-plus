#include "Complex.h"

// 모든 멤버 함수에 범위 연산자 :: 적용, 모두 Complex 클래스의 멤버 함수임을 명시

// 반환형이 void로 바뀜, scanf의 인수가 단순해진다.
void Complex:: readComplex(const char* msg) {
	printf("%s", msg);
	scanf_s("%lf%lf", &real, &imag);
}


// 매개변수 줄어듦, 직접 real, imag 사용
void Complex:: printfComplex(const char* msg) {
	printf("%s %4.2f + %4.2fi\n", msg, real, imag);
}

void Complex:: addComplex(Complex a, Complex b) {
	real = a.real + b.real;
	imag = a.imag + b.imag;
}