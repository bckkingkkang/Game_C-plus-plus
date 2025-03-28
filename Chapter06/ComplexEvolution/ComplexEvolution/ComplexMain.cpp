#include "Complex.h"

/*
	v1 : 구조체와 일반 함수로 구현한 복소수
	v2 : 복소수 클래스로의 전환
	v3 : 멤버 함수 이름의 단순화
*/

void main() {
	Complex a, b, c;
	//a = readComplex("A : ");
	//b = readComplex("B : ");
	//c = addComplex(a, b);
	//printfComplex(a, " A : ");
	//printfComplex(b, " B : ");
	//printfComplex(c, " A+B : ");

	a.readComplex("A : ");
	b.readComplex("B : ");
	c.addComplex(a, b);
	a.printfComplex(" A : ");
	b.printfComplex(" B : ");
	c.printfComplex(" A+B : ");
}