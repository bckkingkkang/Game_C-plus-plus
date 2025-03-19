#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Ranking.h"

void main() {
	srand((unsigned int)time(NULL));

	// 랭킹을 파일에서 읽어온다.
	loadRanking("ranking.txt");

	// 현재 랭킹 출력
	printRanking();

	// 난수를 5회 발생하여 랭킹 갱신
	for (int i = 0; i < 5; i++) {
		addRanking(rand() % 100 + 1, rand() % 1000 * 0.1);
	}
	storeRanking("ranking.txt");
}