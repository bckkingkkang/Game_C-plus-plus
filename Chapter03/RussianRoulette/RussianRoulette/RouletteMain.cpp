#include "RussianRoulette.h"

void main() {
	int nTurn, nBullets;
	
	printf("게임 인원 : ");
	scanf_s("%d", &nTurn);
	printf("총알 개수(6개 미만) : ");
	scanf_s("%d", &nBullets);

	getchar();    // 입력 버퍼에 남아있는 엔터키 비움
	// 총알 개수 입력을 위해 숫자와 함께 엔터키가 입력되어야 하는데
	// scanf는 숫자까지만 읽어가고 엔터키는 입력 버퍼에 남는다.

	int bang = playRussianRoulette(nTurn, nBullets);
	printf("%d번 참가자가 총에 맞았습니다.\n",bang);

}