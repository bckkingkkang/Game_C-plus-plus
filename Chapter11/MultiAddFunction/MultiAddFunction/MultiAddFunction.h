#pragma once
#include <stdio.h>

class Complex {
	double real;
	double imag;

public:
	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i) {}

	void print(const char* msg = "복소수") {
		printf("%s : %4.2f + %4.2fi\n", msg, real, imag);
	}

	// 첫번째 방법 : 멤버함수로 구현되어, 객체를 반환할 필요가 없다.
	void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}

	// 두번째 방법 : friend 선언으로 일반 함수로 구현한다. 
	//               일반함수이지만 friend로 선언되었기 때문에 Complex의 private 멤버인 real과 imag에 접근할 수 있다.
	friend Complex add(Complex a, Complex b) {
		return Complex(a.real + b.real, a.imag + b.imag);
	}

	// 세번째 방법 : 멤버함수로 구현, Complex 객체를 반환한다.
	Complex add(Complex b) {
		return Complex(real + b.real, imag + b.imag);
	}

	// 네번째 방법 : 연산자 중복 함수로 구현
	Complex operator+(Complex b) {
		return Complex(real + b.real, imag + b.imag);
	}
};