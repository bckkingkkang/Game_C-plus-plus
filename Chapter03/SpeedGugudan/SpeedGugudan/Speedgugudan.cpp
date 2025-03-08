#include "SpeedGugudan.h"

static int NumGames = 0; // ��ü �õ� Ƚ��
static int NumWins = 0;  // ���� Ƚ��
static double Score = 0;
double tElapsed;    // ���� �ҿ� �ð�

static bool playGuguOnce() {
	int a = rand() % 8 + 2; // 2~9
	int b = rand() % 8 + 2; // 2~9
	int result;

	NumGames++;
	printf("%d��° ���� : %d X %d = ", NumGames, a, b);
	scanf_s("%d", &result);
	if (result == a * b) {
		NumWins++;
	}
	return (result == a * b); // �����̸� true, �����̸� false ��ȯ
}

double playspeedGugu(int nPlay) {
	clock_t t0 = clock();
	for (int i = 1; i <= 10; i++) {
		if (playGuguOnce() == false) {
			printf("�����Դϴ�.\n");
		}
	}
	clock_t t1 = clock();
	tElapsed = (double)t1 - (double)t0 / CLOCKS_PER_SEC;
	Score = (NumGames > NumWins) ? 0.0 : (5.0*NumGames - tElapsed) / (5.0*NumGames);
	return Score;
}