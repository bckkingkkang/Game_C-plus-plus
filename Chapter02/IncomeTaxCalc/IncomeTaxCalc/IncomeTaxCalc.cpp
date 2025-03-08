// 근로소득세 계산 프로그램 Version 1

#include <stdio.h>
void main() {
	int income; // 소득
	double tax = 0; // 세금
	

	printf("소득을 입력하세요 : ");
	scanf_s("%d", &income);

	int in = income;

	if (income > 15000) {
		tax += (income-15000) * 0.38;
		income = 15000;
	}
	if (income > 8800) {
		tax += (income - 8800) * 0.35;
		income = 8800;
	}
	if (income > 4600) {
		tax += (income - 4600) * 0.24;
		income = 4600;
	}
	if (income > 1200) {
		tax += (income - 1200) * 0.15;
		income = 1200;
	}
	tax += income * 0.06;

	printf("전체 세금은 %7.0f만원입니다.\n", tax);
	printf("순수소득은 %7.0f만원입니다.", in - tax);

}