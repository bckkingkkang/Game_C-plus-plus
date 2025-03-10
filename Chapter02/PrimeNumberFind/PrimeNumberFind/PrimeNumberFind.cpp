﻿#include <cstdio>

void main() {

/*  2부터 n까지의 소수 구하기

	자연수 n을 입력받아 2부터 그 사이에 있는 소수를 모두 출력하고 소수의 개수도 출력

	소수의 정의는 1과 자기 자신만으로 나누어떨어지는 1보다 큰 양의 정수이다.
	임의의 수 k를 2부터 (k-1) 까지의 숫자로 순차적으로 나누어 나머지가 0인 경우가 한 번이라도 있으면 소수가 아니다.
	반복문과 break 사용
	k를 2부터 n까지 적용하여 처리한다 -> 이중루프 사용
	소수 개수를 위해 int 변수 count를 사용하고, 처음에는 0으로 초기화한다.
*/

	int k;
	int n;
	int count = 0;
	int i;

	printf("소수를 구할 최대 숫자를 입력 : ");
	scanf_s("%d", &n);

	for (i = 2; i <= n; i++) {	// 2부터 n 사이의 숫자에 대해서
		for (k = 2; k < i; k++) { // 2부터 (2부터 n 사이의 숫자)보다 작은 수까지
			if (i % k == 0) {
				break;	// 나누어 떨어지면 루프 빠져나감
			}
		}
		if (k == i) {	// 나누어 떨어지는 수가 없으면
			printf("%4d", i);	// 그 수를 출력하고
			count++;	// 카운트 증가
		}
	}
	printf("\n2부터 %d 사이의 소수의 개수는 %d개입니다.",n, count);
}