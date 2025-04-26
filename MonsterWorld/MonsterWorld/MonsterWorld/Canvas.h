#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

/*
	Canvas 클래스
	- 화면 출력용 가상의 캔버스
	- 출력할 내용을 캔버스에 먼저 그리고,
	  전체가 그려지면 한꺼번에 실제 화면에 출력
*/

class Canvas {
	// 화면 출력을 위한 문자열
	string line[MAXLINES];
	// 맵의 크기
	int xMax, yMax;

public:
	// 생성자, 멤버 초기화 리스트 사용
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
		for (int y = 0; y < yMax; y++) {
			line[y] = string(xMax * 2, ' ');
		}
	}

	// Canvas의 (x, y) 좌표에 원하는 문자열(val)을 그린다.
	void draw(int x, int y, string val) {
		// x, y 좌표가 유효한지(캔버스 안에 있는지)
		if (x >= 0 && x < xMax && y >= 0 && y < yMax) {
			// x*2 부터 2길이만큼 val로 교체
			line[y].replace(x * 2, 2, val);
		}
	}

	// Canvas의 모든 화소를 동일한 val로 저장
	void clear(string val = ". ") {
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				draw(x, y, val);
			}
		}
	}

	void print(const char* title = "<My Canvas>") {
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++) {
			cout << line[y] << endl;
		}
		cout << endl;
	}
};