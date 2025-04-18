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

	void clone(Vector& a) {	// 참조자 전달 -> 복사 생성자가 호출되지 않고 실제 객체 직접 참조
		if (dim > 0) {		// arr이 이미 메모리를 가지고 있다면 해제
			delete[] arr;
		}
		dim = a.dim;		// 복사 대상의 크기 복사
		arr = new double[dim];	// heap 영역에 새로운 공간 할당
		for (int i = 0; i < dim; i++) {	// 확보한 공간에 데이터 복사
			arr[i] = a.arr[i];
		}
	}

	void add(Vector* a, Vector* b) {
		for (int i = 0; i < dim; i++) {
			arr[i] = a->arr[i] + b->arr[i];
		}
	}

	// 대입 연산자 정의(연산자 중복)
	void operator = (Vector& a) {
		// 깊은 복사를 수행하는 clone() 함수 호출
		clone(a);
	}

	// 복사 생성자 정의(dim 초기값 0으로 설정)
	Vector(Vector& a) : dim(0) {
		// 깊은 복사를 수행하는 clone() 함수 호출
		clone(a);
	}
};
