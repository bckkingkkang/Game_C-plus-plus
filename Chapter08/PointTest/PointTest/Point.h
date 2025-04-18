#pragma once

class Point {
	int x;
	int y;
public:
	// 클래스에 정적 멤버 변수 추가
	static int count;
	static int version;
};