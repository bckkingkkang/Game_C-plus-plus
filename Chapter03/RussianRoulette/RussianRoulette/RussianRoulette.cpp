#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int playRussianRoulette(int nTurns, int nBullets) {

	srand((unsigned)time(NULL));

	// nTurns = �ο� ��
	int start = rand() % nTurns;
	printf("\n���� ���Ƚ��ϴ�. %d������ �����մϴ�.\n", start +1);
	while (true) {
		int pos = rand() % 6;   // 0~ 5 ������ �� �߻�
		printf("[%d�� ��]    źâ�� �����ϴ�.\n", start+1);
		printf("             ENTER �� ������ �ݹߵ˴ϴ�.\n");
		getchar();
		if (pos < nBullets) {
			break;
		}
		printf("             ����\n");
		start = (start + 1) % nTurns;
	}
	printf("	Ż���߽��ϴ�.\n");
	return start + 1;

}