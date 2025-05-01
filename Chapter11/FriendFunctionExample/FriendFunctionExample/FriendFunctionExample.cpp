#include "FriendFunctionExample.h"
void main() {
	Point arr[5] = {
		Point(0, 1),
		Point(2, 3),
		Point(3, 9)
	};

	arr[3] = addPoint(arr[0], arr[1]);
	arr[4] = subPoint(arr[2], arr[1]);

	for (int i = 0; i < 5; i++) {
		arr[i].print();
	}
	printf("\nAverage X = %lf\n", avgPointX(arr, 5));
}