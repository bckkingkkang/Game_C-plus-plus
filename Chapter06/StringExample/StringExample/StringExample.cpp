#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void main() {
	string s1, s2 = "Game";

	s1 = s2 + " " + "Over";

	if(s1 == "Game Over") {
		cout << s1 << "가 맞습니다\n";
	}

	// 문자열의 처음부터 "Over" 검색, 위치 반환 => 없으면 strinpg::npos 또는 -1 반환
	cout << s1.find("Over") << endl;
	// 4번부터 e검색, 위치 반환 => 없으면 strinpg::npos 또는 -1 반환
	cout << s1.find("e", 4) << endl;

	cout << s1[0] << endl;


	// [5]부터 길이 4의 문자열 추출
	cout << s1.substr(5, 4) << endl;

	// string에서 문자 배열 주소(char*) 추출
	// s1은 std::string 타입, printf는 C 함수이기 때문에 C++ 객체인 std::string 을 바로 출력할 수 없음
	// c_str() 함수를 이용하여 C 스타일 문자열 const char*로 변환하여 출력
	printf("s1 = %s\n", s1.c_str());

	// 표준 입력(cin)에서 한 줄 전체를 읽어서 s1이라는 문자열에 저장
	getline(cin, s1);

	cout << s1 << endl;
}