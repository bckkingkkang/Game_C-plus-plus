#include <stdio.h>

void main() {
	int choice;
	double cels, fahr;

	printf("섭씨에서 화씨 변환 1, 화씨에서 섭씨 변환 2 선택 : ");
	scanf_s("%d", &choice);

	if (choice == 1) {
		printf("섭씨에서 화씨로 온도를 변환합니다.\n변환할 섭씨 온도를 입력하세요 : ");
		scanf_s("%lf", &cels);
		fahr = 32.0 + (9.0 / 5.0 * cels);
		printf("변환된 섭씨 온도 %lf의 화씨 온도는 %lf입니다.\n", cels, fahr);
	}
	else if(choice == 2) {
		printf("화씨에서 섭씨로 온도를 변환합니다.\n변환할 화씨 온도를 입력하세요 : ");
		scanf_s("%lf", &fahr);
		cels = 5.0 / 9.0 * (fahr - 32.0);
		printf("변환된 화씨 온도 %lf의 섭씨 온도는 %lf입니다.\n", fahr, cels);
	}
	else {
		printf("유효하지 않은 선택입니다.\n");
	}
}