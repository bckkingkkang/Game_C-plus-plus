#pragma once
#include <iostream>
using namespace std;

class Vector {
	int dim;
	double* arr;

public:
	Vector(int d = 0) : dim(d) {
		arr = new double[dim];
	}
	// 동적으로 할당된 메모리가 있기 때문에 소멸자에서 이 공간을 반드시 동적으로 해제해주어야 한다.
	~Vector() {
		delete[] arr;
	}

	void setRand(int max = 100) {
		for (int i = 0; i < dim; i++) {
			arr[i] = rand() % (max * 10) / 10.0;
		}
	}

	void print(const char* str = "Vector") {
		cout << str << " [ " << dim << " ] : [ ";
		for (int i = 0; i < dim; i++) {
			cout << arr[i] << " ";
		}
		cout << "]\n";
	}
};
