#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS

#define DIM 40
#define MAXMONS 8

class MonsterWorld {
	// 2차원 배열로 선언한 몬스터 맵
	int map[DIM][DIM];
	// xMax, yMax : 맵의 크기
	// monster 수, 전체 이동 횟수이동 횟수 선언 
	int xMax, yMax, nMon, nMove;

	// 8장 객체와 포인터에서 추가 
	Matrix world;
	Monster* pMon[MAXMONS];

	// 몬스터 객체 배열 선언
	Monster mon[MAXMONS];

	// Canvas 객체 생성
	Canvas canvas;

	// 몬스터 맵의 항목에 접근하기 위한 함수 (참조자 반환)
	int& Map(int x, int y) {
		//return map[y][x];

		// 8장 객체와 포인터에서 추가
		return world.elem(x, y);
	}

	// 몬스터 맵에 남아있는 아이템 수를 반환하는 함수
	int countItems() {
		int nItem = 0;
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x,y) == 1) {
					nItem++;
				}
			}
		}
		return nItem;
	}

	// 맵에 남은 아이템 수가 0이면 게임이 종료 
	bool isDone() {
		return countItems() == 0;
	}

	/*  현재의 몬스터 세상을 화면에 출력
	
		1. 캔버스를 지우고 현재의 맵 상태를 그린다.
		2. 캔버스에 모든 몬스터의 아이콘을 그린다.
		3. 현재 캔버스 내용을 모두 화면으로 출력
		4. 현재의 상태와 각 몬스터별 아이템 수를 출력
	*/
	void print() {
		canvas.clear();

		// 모든 좌표 칸에 대해 아이템이 존재하는 칸에는 "■"를 그린다.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x,y) > 0) {
					canvas.draw(x, y, "■");
				}
			}
		}
		
		// 생성된 몬스터 객체 수 만큼
		for (int i = 0; i < nMon; i++) {
			// 각 몬스터(mon[i])를 현재 위치(x, y)의 아이콘(icon)으로 캔버스에 그린다.
			// mon[i].draw(canvas);

			// 8장 객체와 포인터에서 추가
			pMon[i]->draw(canvas);
		}
		// canvas.print("Monster World BASIC");
		canvas.print("Monster World DYNAMIC");

		cerr << "전체 이동 횟수 : " << nMove << endl;
		cerr << "남은 아이템 수 : " << countItems() << endl;

		for (int i = 0; i < nMon; i++) {
			//mon[i].print();

			// 8장 객체와 포인터에서 추가
			pMon[i]->print();
		}
	}


public:
	// 생성자
	// 8장 객체와 포인터에서 멤버 초기화 리스트 Matrix 추가
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;

		cout << "world.Rows() = " << world.Rows() << endl;
		cout << "world.Cols() = " << world.Cols() << endl;

		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				Map(x, y) = 1;
			}
		}

		// 추가
		world.print("초기 맵");
	}

	// 소멸자
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++) {
			delete pMon[i];
		}
	}

	// MonsterWorld에 Monster를 추가하는 함수
	void add(Monster* m) {
		if (nMon < MAXMONS) {
			// Monster 객체를 저장하는 배열 mon[MAXMONS] 해당 인덱스에 생성한 Monster 객체 m을 복사해 저장하고 mMon을 1 증가시킨다.
			//mon[nMon++] = m;

			// 8장 객체와 포인터에서 추가
			pMon[nMon++] = m;
		}
	}

	/*
		전체 게임 진행 함수

		- 초기 맵을 화면에 출력
		- 엔터 입력 전까지 각 몬스터를 이동하고, 화면을 갱신하는 과정 반복
		- 최대 허용 이동 횟수와 지연 시간을 매개변수를 받는다.
		- 화면이 너무 빨리 움직이는 것을 방지하기 위해 Sleep() 함수에 넣을 지연 시간을 매개변수를 받음
	*/
	void play(int maxwalk, int wait) {
		print();
		cerr << "엔터를 누르면 몬스터가 이동합니다." << endl;
		getchar();
		/*
			getchar() : 문자 하나를 읽음.
            엔터를 입력해야 키보드 버퍼 내용이 넘어옴
		*/

		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++) {
				//mon[k].move(map, xMax, yMax);

				// 8장 객체와 포인터에서 추가
				//pMon[k]->move(world.Data(), xMax, yMax);

				// 9장 상속에서 추가
				((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);
				((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);
				((Ghost*)pMon[2])->move(world.Data(), xMax, yMax);
				((Jiangshi*)pMon[3])->move(world.Data(), xMax, yMax);
			}
			nMove++;
			print();
			if (isDone()) {
				break;
			}

			Sleep(wait);
		}
	}
};