#include "Point.h"
int main() {
	//Point a;
	//Point::version = 3;
	//Point::count++;

	// 변수 앞에 클래스명과 범위 연산자 :: 를 붙여 정적 멤버 사용
	// Point::count 는 Point 클래스에 선언된 정적 변수 count를 말한다.
	// 물론 해당 클래스의 멤버 함수에서는 Point::를 생략할 수 있다. 함수 자체가 그 클래스의 멤버이기 때문

	Point p(1, 2), q(3, 4), r;
	p.print("p = ");
	q.print("q = ");

	Point::printCount();

	Point* pPt;
	pPt = new Point(5, 6);
	pPt->print("pPt = ");

	Point::printCount();
	delete pPt;

	Point::printCount();

	r.add(p, q);
	r.print("P + Q = ");

	Point::printCount();

}