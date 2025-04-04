#pragma once
#include <iostream>
using namespace std;

struct Point {
	int x, y;	// 화면 상의 점을 표현하는 클래스
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	void print() {
		cout << "\t(" << x << ", " << y << ")\n";
	}
};

class Line {	// 화면 상의 선분을 표현하는 클래스
	Point p1, p2;	// 선분의 양 끝 점

public:
	Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}

	void print() {
		cout << "Line: \n";
		p1.print();
		p2.print();
	}
};