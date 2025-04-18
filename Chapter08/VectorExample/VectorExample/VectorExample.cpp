#include "Vector.h"

void main() {
	Vector u(3), v, w(3);

	u.setRand();
	//v.setRand();
	//u.print("U");
	//v.print("V");
	//w.print("W");

	v.clone(u);
	// v.print("V");

	v = u;
	v.print("V");
	u.print("U");

}