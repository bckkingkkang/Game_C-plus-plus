#include <stdio.h>

struct PlayInfo {
	char name[80];	// 이름
	int nMove;		// 이동 횟수
	double tElapsed;	// 소요 시간
};

extern void loadRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
extern void storeRanking(const char* filename);
