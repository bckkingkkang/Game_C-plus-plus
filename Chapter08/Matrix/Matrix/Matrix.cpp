#include "Matrix.h"

// 2차원 배열에서 가장 큰 값을 찾아 반환하는 함수
int findMaxFixel(int** a, int rows, int cols) {
	int max = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void main() {
	Matrix u(3, 6);
	u.setRand();
	u.print("U");
	cout << "Max Fixel Value : " << findMaxFixel(u.Data(), u.Rows(), u.Cols()) << endl;
}