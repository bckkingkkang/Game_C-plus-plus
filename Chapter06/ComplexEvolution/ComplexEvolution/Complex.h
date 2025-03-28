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

	void readComplex(const char* msg = "복소수");
	void printfComplex(const char* msg = "복소수");
	void addComplex(Complex a, Complex b);
};

//inline void setcomplex(Complex& c, double r, double i) {
//	c.real = r;
//	c.imag = i;
//}

//extern Complex readComplex(const char* msg="복소수");
//extern void printfComplex(Complex c, const char* msg="복소수");
//extern Complex addComplex(Complex a, Complex b);
