#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int playRussianRoulette(int nTurns, int nBullets) {

	srand((unsigned)time(NULL));

	// nTurns = 인원 수
	int start = rand() % nTurns;
	printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start +1);
	while (true) {
		int pos = rand() % 6;   // 0~ 5 무작위 수 발생
		printf("[%d번 人]    탄창을 돌립니다.\n", start+1);
		printf("             ENTER 를 누르면 격발됩니다.\n");
		getchar();
		if (pos < nBullets) {
			break;
		}
		printf("             생존\n");
		start = (start + 1) % nTurns;
	}
	printf("	탈락했습니다.\n");
	return start + 1;

}