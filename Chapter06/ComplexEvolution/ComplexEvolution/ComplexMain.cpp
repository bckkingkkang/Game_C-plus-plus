#include "Complex.h"

/*
	v1 : 구조체와 일반 함수로 구현한 복소수
*/

void main() {
	Complex a, b, c;
	a = readComplex("A : ");
	b = readComplex("B : ");
	c = addComplex(a, b);
	printfComplex(a, " A : ");
	printfComplex(b, " B : ");
	printfComplex(c, " A+B : ");
}