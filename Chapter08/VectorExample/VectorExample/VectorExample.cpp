#include "Vector.h"

void main() {
	Vector u(3), v(5), w;

	u.setRand();
	v.setRand();
	u.print("U");
	v.print("V");
	w.print("W");

	v.clone(u);
	v.print("V");

}