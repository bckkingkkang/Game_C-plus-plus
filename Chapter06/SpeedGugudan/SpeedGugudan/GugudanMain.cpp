#include "SpeedGugudan.h"
void main() {
	srand((unsigned)time(NULL));

	SpeedGuguDan gugu;

	int nPlay = 10;
	printf("스피드 구구단 게임\n\n");
	printf("%d번 테스트합니다.\n", nPlay);
	printf("준비되면 ENTER를 누르세요\n");
	getchar();
	system("cls");  // 콘솔 화면 지움
	double score = gugu.play(nPlay);
	printf("점수 : %lf점 (%lf초)\n", score, gugu.tElapsed);
}