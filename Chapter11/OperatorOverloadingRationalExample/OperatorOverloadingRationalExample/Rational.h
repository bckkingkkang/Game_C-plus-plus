#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Rational {
	// 유리수의 분자
	int top;
	// 유리수의 분모(0이 아니어야 한다.)
	int bottom;

public:
	// 생성자
	Rational(int t = 0, int b = 1) : top(t), bottom(b) { }

	// 증감연산자 - 전위
	Rational& operator++() {
		top += bottom;
		return *this;
	}

	// 증감연산자 - 후위
	Rational operator++(int) {
		// 객체에 대한 작업을 수행하고
		top += bottom;
		// 임시 복사본을 반환한다.
		return Rational(top - bottom, bottom);
	}

	// 비트 이동 연산자 - ostream
	friend ostream& operator<<(ostream& os, const Rational& f) {
		os << f.top << "/" << f.bottom;
		return os;
	}

	// 비트 이동 연산자 - istream
	friend istream& operator>>(istream& is, Rational& f) {
		is >> f.top >> f.bottom;
		return is;
	}

	// 형 변환 연산자
	operator double() {
		return (double)top / bottom;
	}

	// 인덱스 연산자
	int& operator[](int id) {
		if (id == 0) {
			return top;
		}
		else if (id == 1) {
			return bottom;
		}
		else {
			exit(0);
		}
	}

	// 함수 호출 연산자
	int& operator()(int id) {
		return (*this)[id];
	}
};