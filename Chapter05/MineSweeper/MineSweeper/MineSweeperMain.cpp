#include "MineSweeper.h"

void main() {
	// 지뢰의 개수 total
	int total;

	printf("\t[ MINE SWEEPER ]\n");
	printf("매설할 총 지뢰의 개수를 입력 : ");
	scanf_s("%d", &total);
	printf("총 %d개의 지뢰를 설치합니다.\n", total);
	playMineSweeper(total);
}