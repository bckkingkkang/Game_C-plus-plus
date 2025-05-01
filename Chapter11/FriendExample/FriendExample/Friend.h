#pragma once
#include <cstdio>
#include <iostream>
using namespace std;

class Point {
	int x, y;
	friend class Shape;
	friend class Line;

public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {

	}

	void print(const char* str = "점") {
		cout << str << ": ( " << x << ", " << y << " )" << endl;
	}
};

class Shape {
protected:
	Point p;
public:
	Shape(int x = 0, int y = 0) : p(x, y) {
		
	}

	void draw() {
		cout << "[형태] 위치 : " << p.x << ", " << p.y << endl;
	}
};

class Line : public Shape {
	Point q;
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : Shape(x1, y1), q(x2, y2) {}

	void draw() {
		cout << "[선분] P1 : " << p.x << ", " << p.y << ", P2 : " << q.x << ", " << q.y << endl;
	}
};