#include "SpeedGugudan.h"
void main() {
	srand((unsigned)time(NULL));

	int nPlay = 10;
	printf("���ǵ� ������ ����\n\n");
	printf("%d�� �׽�Ʈ�մϴ�.\n", nPlay);
	printf("�غ�Ǹ� ENTER�� ��������\n");
	getchar();
	system("cls");  // �ܼ� ȭ�� ����
	double score = playspeedGugu(nPlay);
	printf("���� : %lf�� (%lf��)\n", score, tElapsed);
}