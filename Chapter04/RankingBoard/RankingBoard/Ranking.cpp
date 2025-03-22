#include "Ranking.h"
#define _CRT_SECURE_NO_WARNINGS
static PlayInfo MVP[5];

// 전역변수나 함수를 static으로 처리하는 것은 그 변수나 함수를 해당 파일에서만 사용하라는 의미를 가진다
static void initRanking() {
	PlayInfo noname = { "C++", 1000, 1000.0 };
	for (int i = 0; i < 5; i++) {
		MVP[i] = noname;
	}
}

void loadRanking(const char* fname) {
	FILE* fp = fopen(fname, "r");
	if (fp == NULL) {
		initLanking();
	}
	else {
		for (int i = 0; i < 5; i++) {
			fscanf(fp, "%d %s %lf", &MVP[i].nMove, &MVP[i].name, &MVP[i].tElapsed);
		}
		fclose(fp);
	}
}

void printRanking() {
	for (int i = 0; i < 5; i++) {
		printf("%dÀ§ : %d %s %f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
	}
}

int addRanking(int nMove, double tElap) {
	if (nMove < MVP[4].nMove) {
		int pos = 4;
		for (; pos > 0; pos--) {
			if (nMove >= MVP[pos - 1].nMove) {
				break;
			}
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf("%dÀ§, ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä : ",pos+1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}

void storeRanking(const char* fname) {
	FILE* fp = fopen(fname, "w");
	if (fp == NULL) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		fprintf(fp, "d %s %f\n", MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
	}
	fclose(fp);
}
