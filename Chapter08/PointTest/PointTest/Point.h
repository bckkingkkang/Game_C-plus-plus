#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Point {
	int x;
	int y;
public:
	// 클래스에 정적 멤버 변수 추가
	static int count;
	static int version;

	// 정적 멤버 함수
	static void printCount() {
		cout << "현재 생성된 객체 Count: " << count << endl;
	}

	// 생성자
	Point() {
		count++;
	}
	Point(int x, int y) : x(x), y(y) {
		count++;
	}
	
	// 소멸자
	~Point() {
		count--;
	}

	Point(const Point& p) : x(p.x), y(p.y) {
		count++;
	}

	void add(Point a, Point b) {
		x = a.x + b.x;
		y = a.y + b.y;
	}

	void print(string msg = "P = ") {
		cout << msg << x << ", " << y << endl;
	}
};