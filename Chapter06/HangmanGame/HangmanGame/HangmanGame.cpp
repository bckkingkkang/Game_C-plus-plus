#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class Hangman {
	// 각 단계별 화면 출력용 배열(그림)
	string progress[64];
	// 정답 단어 보관 문자열
	string problem;
	// 사용자가 입력한 문자열
	string answer;
	// 전체 알파벳의 예측 상황을 나타내는 문자열
	string guessed;

	// 현재 시도 횟수
	int nTries;
	// 최대 허용 시도 횟수
	const int maxTries = 7;

	// "HangmanProgress.txt" 파일에서 상태 출력용 문자열을 읽어오는 함수
	void load(const char* progName = "HangmanProgress.txt") {
		// 파일에서 읽어오기
		ifstream fs(progName);
		// 파일이 정상적으로 열렸다면
		if (fs) {
			// 첫 번째 행은 주석으로 무시한다.
			getline(fs, progress[0]);
			for(int i = 1; i<64; i++) {
				// 한 줄마다 읽어서 progress[i]에 저장
				getline(fs, progress[i]);
			}
		}
	}

	// 현재의 상태를 화면에 출력
	void print() {
		
	}

	// 예측한 문자가 정답 내의 문자와 일치되는 개수를 반환하는 함수
	int countMatched(char ch) {
		// 예측한 문자가 정답 내의 문자와 일치되는 개수
		int nMatched = 0;

		for (int pos = -1; ; ) {
			pos = problem.find(ch, pos + 1);
			// ch가 나오는 인덱스의 정수를 반환, [0]번째 인덱스(pos+1)부터 find 시작
			// 반환된 인덱스의 정수를 pos 변수에 저장하고 다시 -> pos+1 인덱스부터 find 시작

			if(pos < 0) break;

			answer[pos] = ch;
			// answer : 현재 예측 중인 문자열, 최초에는 '_' 문자를 저장하고
			//          예측 문자 중 해당 문자열이 있으면 해당 문자를 표시한다.
			nMatched++;
		}
		return nMatched;
	}
};