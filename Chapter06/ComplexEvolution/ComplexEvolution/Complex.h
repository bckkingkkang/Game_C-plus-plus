#pragma once
#include <cstdio>

struct Complex {
	double real;
	double imag;
};

inline void setcomplex(Complex& c, double r, double i) {
	c.real = r;
	c.imag = i;
}

extern Complex readComplex(const char* msg="복소수");
extern void printfComplex(Complex c, const char* msg="복소수");
extern Complex addComplex(Complex a, Complex b);
