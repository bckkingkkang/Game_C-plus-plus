#pragma once
#include <cstdio>

class Point {
	int x, y;
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}

	void print(const char* s = "점") {
		printf("%s(%d, %d)\n", s, x, y);
	}

	// 평균 x값을 계산하는 일반 함수
	friend double avgPointX(Point* list, int n);
	
	// 두 포인트를 더하는 일반 함수
	friend Point addPoint(Point& p, Point& q) {
		// Point의 멤버 함수가 아닌 inline으로 구현된 일반 함수
		Point r;
		r.x = p.x + q.x;
		r.y = p.y + q.y;
		return r;
	}

	friend Point subPoint(Point& p, Point& q) {
		return Point(p.x - q.x, p.y - q.y);
	}
};

double avgPointX(Point* list, int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += list[i].x;
	}
	return sum / n;
}

