#include "SpeedGugudan.h"

static int NumGames = 0; // 전체 시도 횟수
static int NumWins = 0;  // 맞힌 횟수
static double Score = 0;
double tElapsed;    // 게임 소요 시간

static bool playGuguOnce() {
	int a = rand() % 8 + 2; // 2~9
	int b = rand() % 8 + 2; // 2~9
	int result;

	NumGames++;
	printf("%d번째 문제 : %d X %d = ", NumGames, a, b);
	scanf_s("%d", &result);
	if (result == a * b) {
		NumWins++;
	}
	return (result == a * b); // 정답이면 true, 오답이면 false 반환
}

double playspeedGugu(int nPlay) {
	clock_t t0 = clock();
	for (int i = 1; i <= 10; i++) {
		if (playGuguOnce() == false) {
			printf("오답입니다.\n");
		}
	}
	clock_t t1 = clock();
	tElapsed = (double)t1 - (double)t0 / CLOCKS_PER_SEC;
	Score = (NumGames > NumWins) ? 0.0 : (5.0*NumGames - tElapsed) / (5.0*NumGames);
	return Score;
}