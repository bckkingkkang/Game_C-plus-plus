#include "RussianRoulette.h"

void main() {
	int nTurn, nBullets;
	
	printf("���� �ο� : ");
	scanf_s("%d", &nTurn);
	printf("�Ѿ� ����(6�� �̸�) : ");
	scanf_s("%d", &nBullets);

	getchar();    // �Է� ���ۿ� �����ִ� ����Ű ���
	// �Ѿ� ���� �Է��� ���� ���ڿ� �Բ� ����Ű�� �ԷµǾ�� �ϴµ�
	// scanf�� ���ڱ����� �о�� ����Ű�� �Է� ���ۿ� ���´�.

	int bang = playRussianRoulette(nTurn, nBullets);
	printf("%d�� �����ڰ� �ѿ� �¾ҽ��ϴ�.\n",bang);

}