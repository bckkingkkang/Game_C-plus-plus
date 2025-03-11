#include <stdio.h>

double CalcTax(int income) {
	int amount[5] = { 0, 1200, 4600, 8800, 15000 };
	double tax = 0;
	double rate[5] = { 0.06, 0.15, 0.24, 0.35, 0.38 };

	for (int i = 0; i < 5; i++) {
		if (income > amount[i]) {
			tax += (income - amount[i]) * rate[i];
			income = amount[i];
		}
	}
	tax += income * rate[0];
	return tax;
}

void main() {
	int income;
	double tax;
	printf("연봉을 입력하세요 : ");
	scanf_s("%d", &income);
	tax = CalcTax(income);
	printf("전체 세금은 %f입니다.\n", tax);
	printf("순수 소득은 %f입니다.\n", income - tax);
}