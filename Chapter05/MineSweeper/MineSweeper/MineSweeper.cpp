#include "MineSweeper.h"
#include <windows.h>

// Demension(한 변 크기), 게임 판의 기본 크기 정의 DIM * DIM
#define DIM 9

// Label : 실제 지형 정보
enum LabelType {
	Empty = 0,
	Bomb = 9
};
// Mask : 플레이어에게 보여지는 상태
enum MaskType {
	Hide = 0,
	Open,
	Flag
};

static int MineMapMask[DIM][DIM];
static int MineMapLabel[DIM][DIM];

// DIM*DIM을 맵 사이즈의 고정으로 사용할 경우 맵 사이즈 변경 시 불편하기 때문에 nx/ny를 따로 둔다.
static int nx = DIM, ny = DIM;

// 지뢰의 개수는 사용자 입력을 받지만 9로 미리 초기화
static int nBomb = 9;

// mask, label 좌표 위치 return하는 인라인 함수 - 단순 반환 뿐만 아니라 값 변경도 가능하게 하기 위해 참조자 사용
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }

// 좌표가 맵 안에 있는지(유효한지) 확인
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
// 좌표가 맵 안에 있는지 && 해당 좌표에 폭탄이 있는지
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
// 좌표가 맵 안에 있는지 && 해당 좌표가 비어있는지
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

// 입력받은 (x,y) 좌표를 Open 상태로 변경하는 함수
static void dig(int x, int y) {
	/*
		칸을 파면 마스크 맵의 해당 칸은 Open이 된다.

		입력받은 좌표가 유효한 값이고 Open되지 않은 상태라면 해당 좌표 Open

		if(해당 좌표의 값이 0이라면) {
		    인접한 0이 없을 때까지 모든 이웃칸을 파낸다(Open) -> 재귀호출
		}	
	*/
	if (isValid(x, y) && mask(x, y) != Open) {
		// mask() 함수가 참조자를 반환하므로 mask(x, y) = Open; 으로 값 변경 가능
		mask(x, y) = Open;

		if (label(x, y) == 0) {
			dig(x - 1, y);
			dig(x + 1, y);
			dig(x, y - 1);
			dig(x, y + 1);
			dig(x - 1, y - 1);
			dig(x + 1, y + 1);
			dig(x - 1, y + 1);
			dig(x + 1, y - 1);
		}
	}

}

// 입력받은 (x, y) 좌표를 Flag 상태로 변경하는 함수
static void mark(int x, int y) {
	// isValid = true이면서 Open되지 않은 Hide 칸을 Flag로 변경
	if (isValid(x, y) && mask(x, y) == Hide) {
		// mask() 함수가 참조자를 반환하므로 mask(x, y) = Flag; 으로 값 변경 가능
		mask(x, y) = Flag;
	}
}

// Flag(깃발)의 수를 반환하는 함수
static int getFlagCount() {
	int count = 0;
	// 맵에 있는 모든 좌표에 대해
	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
			// Flag 상태라면 count 증가
			if (mask(x, y) == Flag) {
				count++;
			}
		}
	}
	return count;
}

// 지뢰 맵의 화면 출력 함수
static void print() {
	// windows 환경 전용 화면 클리어(콘솔 화면 지움)
	system("cls");
	printf("발견 : %d \t 전체 : %d\n", getFlagCount(), nBomb);

	// 열 라벨 표시
	printf("① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨\n");

	for (int y = 0; y < ny; y++) {
		// 행 라벨 표시
		printf("%c ", 'A' + y);	// ASCII 코드로 변환하여 출력

		// [y][x] 모든 좌표 값에 대해
		for (int x = 0; x < nx; x++) {
			// Hide(파지 않은) 상태인 곳이라면
			if (mask(x, y) == Hide) {
				printf("■");
			}
			// Flag 상태(지뢰 예상 자리)인 경우
			else if (mask(x, y) == Flag) {
				// 현재 콘솔 코드 페이지 저장
				UINT oldCP = GetConsoleOutputCP();
				// 인코딩 유니코드로 변경
				SetConsoleOutputCP(65001);
				// 깃발 출력
				printf(u8"\u2690");
				// 한글 인코딩 깨지지 않도록 이전 코드 페이지로 되돌려놓는다
				SetConsoleOutputCP(oldCP);
			}
			// open 상태인 곳에 대해 if
			else {
				// 지뢰인 좌표라면
				if (isBomb(x, y)) {
					// 현재 콘솔 코드 페이지 저장
					UINT oldCP = GetConsoleOutputCP();
					// 인코딩 유니코드로 변경
					SetConsoleOutputCP(65001);
					// 폭탄 출력
					printf(u8"\u2620");
					// 한글 인코딩 깨지지 않도록 이전 코드 페이지로 되돌려놓는다
					SetConsoleOutputCP(oldCP);
				}
				// 지뢰가 아닌 좌표라면
				else if (isEmpty(x, y)) {
					printf("□");
				}
				else {
					printf("%d\n", label(x, y));
				}
			}
		}
		printf("\n");
	}
}