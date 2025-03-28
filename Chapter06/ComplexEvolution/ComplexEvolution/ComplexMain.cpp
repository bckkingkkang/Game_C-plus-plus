#include "Complex.h"

/*
	v1 : 구조체와 일반 함수로 구현한 복소수
	v2 : 복소수 클래스로의 전환
	v3 : 멤버 함수 이름의 단순화
	v4 : 모든 멤버 함수의 inline 구현
*/

void main() {
	Complex a, b, c;
	//a = readComplex("A : ");
	//b = readComplex("B : ");
	//c = addComplex(a, b);
	//printfComplex(a, " A : ");
	//printfComplex(b, " B : ");
	//printfComplex(c, " A+B : ");

	/*a.readComplex("A : ");
	b.readComplex("B : ");
	c.addComplex(a, b);
	a.printfComplex(" A : ");
	b.printfComplex(" B : ");
	c.printfComplex(" A+B : ");*/

	// 멤버 함수 이름의 단순화에 따라 호출 코드도 단순해짐
	a.read("A : ");
	b.read("B : ");
	c.add(a, b);
	a.print(" A : ");
	b.print(" B : ");
	c.print(" A+B : ");
}