#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	// 몬스터의 이름과 아이콘
	string name, icon;

	// 현재 위치와 먹은 아이템 수
	int x, y, nItem;

	// 현재 위치가 맵의 외부로 나가면 안쪽으로 다시 옮기는 함수
	void clip(int maxx, int maxy) {
		if (x < 0) {
			x = 0;
		}
		if (x >= maxx) {
			x = maxx - 1;
		}
		if (y < 0) {
			y = 0;
		}
		if(y >= maxy) {
			y = maxy - 1;
		}
	}

	// 현재 맵의 위치에 아이템이 있으면 아이템을 먹고 맵의 내용과 먹은 아이템 수를 갱신하는 함수
	void eat(int map[DIM][DIM]) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
		}
	}

public:
	// 생성자
	Monster(string n = "Monster", string i = "※", int px = 0, int py = 0) : name(n), icon(i), x(px), y(py), nItem(0) { }
	// 소멸자
	~Monster() {
		cout << "\t" << name << " " << icon << " 소멸" << endl;
	}

	// 몬스터를 캔버스에 그리는 함수, Canvas 클래스의 draw() 함수 호출
	// 생성된 canvas 객체를 복사하지 않고 직접 수정하기 위해 참조자로 전달
	void draw(Canvas& canvas) {
		canvas.draw(x, y, icon);
	}

	// 몬스터를 무작위로 이동시키는 함수
	void move(int map[DIM][DIM], int maxx, int maxy) {
		switch (rand() % 8) {
			case 0: y--; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: x++; break;
			case 4: x--; y--; break;
			case 5: x--; y++; break;
			case 6: x++; y--; break;
			case 7: x++; y++; break;
		}

		clip(maxx, maxy);
		eat(map);
	}

	// Monster의 정보 화면에 출력
	void print() {
		cout << "\t" << name << " " << icon << " : " << nItem << endl;
	}
};