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