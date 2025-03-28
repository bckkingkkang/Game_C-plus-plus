#pragma once
#include <cstdio>

class Complex {
	double real;
	double imag;

// inline으로 구현된 멤버 함수. 매개변수가 하나 줄고, 코드가 단순해짐 
public:
	void setComplex(double r, double i) {
		real = r;
		imag = i;
	}

	//void readComplex(const char* msg = "복소수");
	//void printfComplex(const char* msg = "복소수");
	//void addComplex(Complex a, Complex b);

	// 일반 멤버 함수들의 이름을 단순하게 변경, 이 클래스에서만 의미가 있으므로 이름 변경 시에도 의미가 명확함
	//void read(const char* msg = "복소수");
	//void print(const char* msg = "복소수");
	//void add(Complex a, Complex b);

	// 모든 멤버 함수를 inline으로 구현, ComplexEvolution.cpp가 필요없음
	void read(const char* msg = "복소수") {
		printf("%s", msg);
		scanf_s("%lf%lf", &real, &imag);
	}
	void print(const char* msg = "복소수") {
		printf("%s %4.2f + %4.2fi\n", msg, real, imag);
	}

	void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}

};

//inline void setcomplex(Complex& c, double r, double i) {
//	c.real = r;
//	c.imag = i;
//}

//extern Complex readComplex(const char* msg="복소수");
//extern void printfComplex(Complex c, const char* msg="복소수");
//extern Complex addComplex(Complex a, Complex b);
