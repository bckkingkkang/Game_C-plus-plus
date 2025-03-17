/*	구조체를 이용한 함수 호출과 반환
	구조체도 함수 호출에서 인자로 사용하거나 함수의 반환 값으로 사용할 수 있다.
	복소수 구조체를 선언하고 함수를 구현한다.

	1. 출력 함수 printComplex : 복소수를 보기 좋게 화면으로 출력함
	2. 입력 함수 reaComplex : 사용자로부터 실수부와 허수부를 읽어 결과 복소수를 반환함
	3. 덧셈 함수 addComplex : 두 복소수의 합을 구해 결과 복소수를 반환한다.

	* resetComplex 복소수 초기화
*/
#include <stdio.h>
struct Complex {
	double real;
	double imag;
};

void printComplex(Complex c, const char msg[] = "복소수") {
	printf("%s : %4.2f + %4.2fi\n", msg, c.real, c.imag);
}

Complex readComplex(const char msg[] = "복소수 입력") {
	Complex c;
	printf("%s", msg);
	scanf_s("%lf%lf", &c.real, &c.imag);
	return c;
}

Complex addComplex(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

void resetComplex(Complex &c) {
	c.real = 0.0;
	c.imag = 0.0;
}

void main() {
	Complex a, b, c;
	a = readComplex("a(입력) : ");
	b = readComplex("b(입력) : ");
	c = addComplex(a, b);
	printComplex(a);
	printComplex(b);
	printComplex(c);

	resetComplex(c);
	printComplex(c);
}