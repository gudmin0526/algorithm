#include <iostream>
#include <string>
using namespace std;

const string vowels = "aeiou";

bool isVowel(const char& c) {
	return vowels.find(c) != string::npos;
}

bool isAcceptable(const string& word) {
	bool has_vowel = false;
	char lc = '\0'; // 이전 문자
	int cv_len = 0; // 연속된 vowel 길이
	int cc_len = 0; // 연속된 consonent 길이

	for (const char& c : word) {
		// 1-1. 모음 하나를 반드시 포함.
		if (isVowel(c)) {
			has_vowel = true;
			cv_len++;
			cc_len = 0;
		} else {
			cv_len = 0;
			cc_len++;
		}

		// 1-2. 모음이 3개, 자음이 3개 연속적으로 오면 안됨.
		if (cc_len == 3 || cv_len == 3)
			return false;

		// 1-3. 같은 글자가 연속적으로 두 번 오면 안됨.
		// 1-3-1. ee와 oo는 허용.
		if (!(c == 'o' || c == 'e') && c == lc)
			return false;
		lc = c;
	}

	return has_vowel;
}

int main() {
	string word;
	while (1) {
		cin >> word;
		if (word == "end")
			break;
		
		if (isAcceptable(word)) {
			cout << "<" << word << ">" << " is acceptable.\n";
		} else {
			cout << "<" << word << ">" << " is not acceptable.\n";
		}
	}

	return 0;
}

/*
출력:
각 테스트케이스의 품질 평가

제약조건:
1. 높은 품질 비밀번호의 조건
 1-1. 모음 하나를 반드시 포함.
 1-2. 모음이 3개 or 자음이 3개 연속 오면 안 됨.
 1-3. 같은 글자가 연속적으로 두 번 오면 안됨.
  1-3-1. ee와 oo의 경우는 예외적으로 허용.

2. 예외
 2-1. 패스워드는 대문자를 포함하지 않음.
*/