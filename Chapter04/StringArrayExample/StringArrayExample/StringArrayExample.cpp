// 문자열 처리 함수 사용 예
//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>

void main() {
	char s1[] = "game", s2[20], s3[20];

	strcpy_s(s2, "over");
	sprintf_s(s3, "%s %s !", s1, s2);
	// s3 : game over !

	printf("strlen(%s) = %d\n", s1, strlen(s1));
	printf("strlen(%s) = %d\n", s2, strlen(s2));
	printf("strlen(%s) = %d\n", s3, strlen(s3));

	// strcmp : 문자열이 같은지 비교하는 함수, 같으면 0을 반환하고 
	//          s1이 사전적으로 앞에 있으면 -1을, 아니면 1을 반환한다.
	printf("strcmp(%s,%s) = %d\n", s1, s2, strcmp(s1, s2));

	printf("strcmp(%s, game) = %d\n", s1, strcmp(s1, "game"));

}