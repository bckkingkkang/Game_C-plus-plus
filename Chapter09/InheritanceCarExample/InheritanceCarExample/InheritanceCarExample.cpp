#include "InheritanceCar.h"

void main() {
	Car myCar(5), yourCar(3);

	// myCar.serial = 1234; // Error: serial is private
	// yourCar.speed = 100; // Error: speed is protected

	myCar.pushAccel();
	myCar.price = 10000;
	yourCar.price = 30000;

	myCar.print();
	yourCar.print();

	myCar.printCarInfo("myCar");
	yourCar.printCarInfo("yourCar");
}