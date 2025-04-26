#pragma once
#include <iostream>
#include <string>
#include <iomanip>	// 입출력 조정
using namespace std;

class Matrix {
	int rows, cols;

	// 실제 행렬 데이터
	int** mat;

public:
	// 생성자
	Matrix(int r, int c) :rows(r), cols(c) {
		mat = new int* [rows];
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[cols];
		}
	}

	// 소멸자
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}

	int Rows() {
		return rows;
	}

	int Cols() {
		return cols;
	}

	int& elem(int x, int y) {
		// 참조 반환, elem(x, y) 호출 시 해당 위치의 요소에 직접 접근 가능
		return mat[y][x];
	}

	// int** mat 반환하는 함수
	int** Data() {
		return mat;
	}

	void print(const char* msg = "Mat") {
		cout << msg << " " << rows << "x" << cols << endl;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << setw(4) << mat[i][j];
			}
			cout << "\n";
		}
	}

	void setRand(int val = 100) {
		if (mat != NULL) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					mat[i][j] = rand() % val;
				}
			}
		}
	}
};