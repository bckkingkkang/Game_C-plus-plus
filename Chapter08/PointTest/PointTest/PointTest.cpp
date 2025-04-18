#include "Point.h"
void main() {
	Point a;
	Point::version = 3;
	Point::count++;

	// 변수 앞에 클래스명과 범위 연산자 :: 를 붙여 정적 멤버 사용
	// Point::count 는 Point 클래스에 선언된 정적 변수 count를 말한다.
	// 물론 해당 클래스의 멤버 함수에서는 Point::를 생략할 수 있다. 함수 자체가 그 클래스의 멤버이기 때문
}