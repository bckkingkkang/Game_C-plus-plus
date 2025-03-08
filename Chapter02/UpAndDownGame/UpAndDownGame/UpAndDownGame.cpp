// 번호 맞추기 게임 up-and-down game
#include <stdio.h>
#include <conio.h>
void main() {

	int answer;		// 정답
	int input;		// 제출 답
	
	int min = 1;
	int max = 99;

	printf("두 자리 수 입력(1~99) : ");
	char a = _getch();
	printf("*");
	char b = _getch();
	printf("*\n");
	answer = (a - '0') * 10 + (b - '0');    // ASCII : '0' 48

	for (int i = 1; i <= 10; i++ ) {
		printf("기회 %d : %d ~ %d 사이의 수 입력 : ", i, min, max);
		scanf_s("%d", &input);
		if (input > answer) {
			printf("%d보다 작은 수 입니다. 남은 기회는 %d번입니다.\n", input, 10 - i);
			max = input;
		}
		else if (input < answer) {
			printf("%d보다 큰 수 입니다. 남은 기회는 %d번입니다.\n", input, 10 - i);
			min = input;
		}
		else {
			printf("정답입니다. %d번만에 성공했습니다.", i);
			break;
		}
	}
}