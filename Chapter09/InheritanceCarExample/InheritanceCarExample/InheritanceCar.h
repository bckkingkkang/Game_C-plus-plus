#pragma once
#include <cstdio>
#include <iostream>
using namespace std;

class Vehicle {
	int serial;

protected:
	int speed;

public:
	int price;
	Vehicle(int s = 0) : serial(s), speed(0), price(0) { }

	void speedUp() {
		speed++;
	}

	void speedDown() {
		speed--;
	}

	void print() {
		cout << "Vehicle serial : " << serial << ", speed : " << speed << ", price : " << price << endl;
	}
};

class Car : public Vehicle {
	int gear;
public:
	Car(int g = 0) : gear(g) {}

	void pushAccel() {
		speed += 5;
	}

	void pushBreak() {
		speedDown();
	}

	void setGear(int g) {
		gear = g;
	}

	void printCarInfo(string msg = "car") {
		cout << msg << endl << "speed : " << speed << endl << "gear : " << gear << endl << "price : " << price << endl;
	}
};