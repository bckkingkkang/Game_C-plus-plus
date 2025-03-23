#include "MineSweeper.h"

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