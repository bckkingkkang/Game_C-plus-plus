#include "MonsterWorld.h"
#include "time.h"

/*
	7장 객체의 생성과 소멸
	: mon[] 배열에 몬스터 객체 자체를 저장
	  메모리 안에 Monster 객체가 mon[0], mon[1],... 직접 저장

	8장 객체와 포인터
	: pMonp[] 포인터 배열에 Monster 객체 주소를 저장
	  Monster 객체는 new로 동적 생성하고 pMon[0], pMon[1],...에 포인터 이용해서 저장

	- "차이는 객체를 직접 저장하냐, 주소만 저장하냐의 차이다."


*/

void main() {
	srand((unsigned)time(NULL));

	int w = 16;
	int h = 8;

	MonsterWorld game(w, h);

	//Monster m("Monster1", "※", rand() % w, rand() % h);
	//game.add(m);
	
	game.add(new Monster("Monster1", "※", rand() % w, rand() % h));
	game.add(new Monster("Monster2", "★", rand() % w, rand() % h));
	game.add(new Monster("Monster3", "§", rand() % w, rand() % h));
	game.add(new Monster("Monster4", "♥", rand() % w, rand() % h));

	game.play(300, 100);
	cout << "----------게임 종료----------" << endl;
}