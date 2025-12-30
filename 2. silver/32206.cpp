#include <iostream>
#include <string>

using namespace std;

int N;
string S;

int main() {
	cin >> N >> S;
	cout << 25 * (N + 1) + 1;

	return 0;
}

/*
아이디어:
a -> 26 + 26 - 1(a는 중복)
kintex -> 26 + 25 + 25 + 25 + 25 + 25 + 25 = 176
앞에 나온 문자는 이전에 처리되었다고 가정
aa -> 26 + 25 + 25

입력:
N(문자열 길이) ~ [1, 2e5]
S(영문 소문자 문자열)

출력:
나올 수 있는 서로 다른 문자열의 개수

제약조건:
1. S의 앞이나 뒤, 혹은 두 문자 사이에 영문 소문자 '하나' 추가
*/