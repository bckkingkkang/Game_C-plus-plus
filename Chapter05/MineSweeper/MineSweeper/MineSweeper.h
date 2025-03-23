// 헤더 파일이 여러 번 중복되는 걸 막아줌
#pragma once

// C 표준 입출력 함수
#include <stdio.h>
// 일반 유틸리티 함수
#include <stdlib.h>
// 문자열 처리
#include <string.h>
// 콘솔 I/O, 키 입력 처리(windows)
#include <conio.h>
// 시간 관련 함수
#include <time.h>
// 문자 검사/변환 함수
#include <ctype.h>

extern void playMineSweeper(int nBomb = 13);
