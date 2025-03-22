#include <stdio.h>
#define WIDTH 17
#define HEIGHT 5

// label() : 한 지점에서 시작해서 상하좌우로 퍼지며 모든 연결된 9 좌표를 찾아서 색칠하는 재귀함수
void label(unsigned char img[HEIGHT][WIDTH], int x, int y, int color) {
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || img[y][x] != 9) {	// img[y][x] != 9 : 이미 채색된 전경인 경우 return
		// 이미 색칠했거나 배경이면 return
		return;
	}
	// 메모리 구조 상 [y][x]로 접근한다.
	img[y][x] = color;

	// 4방향으로 재귀호출, (x, y) 위치에 있는 9로 연결된 모든 전경 픽셀을 찾아서 같은 color로 칠한다.
	label(img, x - 1, y, color);
	label(img, x + 1, y, color);
	label(img, x, y - 1, color);
	label(img, x, y + 1, color);
}

// 영상 채색을 위한 주 함수
void blobColoring(unsigned char img[HEIGHT][WIDTH]) {
	// 0 : 배경, 9 : 아직 채색되지 않은 전경, 그 외 : 이미 채색된 전경
	int color = 1;

	// 영상의 모든 화소에 대해
	for (int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
			// 아직 채색되지 않은 전경인 경우
			if (img[y][x] == 9) {
				// 채색 시작
				label(img, x, y, color++);
			}
		}
	}
}

void printImage(unsigned char img[HEIGHT][WIDTH], const char* msg) {
	printf("%s\n", msg);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (img[y][x] == 0) {
				// 배경이면 .으로 나타낸다.
				printf(".");
			}
			else {
				printf("%d", img[y][x]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void main() {
	unsigned char image[HEIGHT][WIDTH] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 9, 9, 9, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0,
		9, 9, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9,
		0, 9, 9, 9, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	printImage(image, "Original image");
	blobColoring(image);
	printImage(image, "labelled image");
}